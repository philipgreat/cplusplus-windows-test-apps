// RawSocket1.cpp: implementation of the CRawSocket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RawSocket.h"
#pragma comment(lib,"WS2_32.LIB")

static FILE *file;

PROTN2T _PROTOCAL2TEXT_TABLE [ PROTO_NUM + 1] = 
{  
	{ IPPROTO_IP   , "IP" },
	{ IPPROTO_ICMP , "ICMP" },  
	{ IPPROTO_IGMP , "IGMP" }, 
	{ IPPROTO_GGP  , "GGP" },  
	{ IPPROTO_TCP  , "TCP" },  
	{ IPPROTO_PUP  , "PUP" },  
	{ IPPROTO_UDP  , "UDP" },  
	{ IPPROTO_IDP  , "IDP" },  
	{ IPPROTO_ND   , "NP"  },  
	{ IPPROTO_RAW  , "RAW" },  
	{ IPPROTO_MAX  , "MAX" },
	{ NULL , "" } 
} ;  





//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//typical usage of the class
//
CRawSocket::CRawSocket()
{
	InitializeSocket();
	filteredPortsCount = 0;
}

CRawSocket::~CRawSocket()
{
	WSACleanup(); 
}

USHORT CRawSocket::CheckSum(USHORT *buffer, int size)
{
	unsigned long cksum=0; 
	
	while(size >1) { 
		
		cksum+=*buffer++; 
		
		size -=sizeof(USHORT); 
		
	} 
	
	if(size ) { 
		
		cksum += *(UCHAR*)buffer; 
		
	} 
	
	cksum = (cksum >> 16) + (cksum & 0xffff); 
	
	cksum += (cksum >>16); 
	
	return (USHORT)(~cksum); 
}

char* CRawSocket::GetProtocolName(unsigned char proto)
{
	BOOL bFound = FALSE ;
	for( int i = 0 ; i < PROTO_NUM ; i++ )
	{
		if( _PROTOCAL2TEXT_TABLE[i].proto == proto )
		{
			bFound = TRUE ;
			break ;
		}	
	}
	if( bFound )
		return _PROTOCAL2TEXT_TABLE[i].pprototext ;
	return _PROTOCAL2TEXT_TABLE[PROTO_NUM].pprototext ;
}

bool RaisePrivleges( HANDLE hToken, char *pPriv )
{
    TOKEN_PRIVILEGES tkp;
    if ( !LookupPrivilegeValue( NULL, pPriv, &tkp.Privileges[0].Luid ) )
    {
        printf( "LookupPrivilegeValue Error:%d\n", GetLastError() );
        return false;
    }
    tkp.PrivilegeCount = 1;
    tkp.Privileges[0].Attributes |= SE_PRIVILEGE_ENABLED;
    int iRet = AdjustTokenPrivileges(hToken,
        false,
        &tkp,
        0,
        (PTOKEN_PRIVILEGES)NULL,
        0 );
    if (iRet == NULL)//AdjustTokenPrivileges函数调用失败
    {
        printf( "AdjustTokenPrivileges Error:%d\n", GetLastError() );
        return false;
    }
	
	iRet = GetLastError();
	switch ( iRet )
	{
	case ERROR_NOT_ALL_ASSIGNED://未指派所有的特权
		printf( "AdjustTokenPrivileges ERROR_NOT_ALL_ASSIGNED\n" );
		return false;
		
	case ERROR_SUCCESS:               //成功地指派了所有的特权
		return true;
	default:                              //不知名的错误
		printf( "AdjustTokenPrivileges Unknow Error:%d\n", iRet );
		return false;
	}
    
}//end of RaisePrivleges 


int CRawSocket::InitializeSocket()
{
	int ErrorCode,flag; 
	WSADATA wsaData; 	
	
	
	
	//初始化SOCK_RAW 
	
	if((ErrorCode=WSAStartup(MAKEWORD(2,1),&wsaData))!=0){ 
		fprintf(stderr,"WSAStartup failed: %d\n",ErrorCode); 		
		ExitProcess(STATUS_FAILED); 		
	} 
	
	//
	
	m_intSocket=WSASocket(AF_INET,SOCK_RAW,IPPROTO_RAW,NULL,0,WSA_FLAG_OVERLAPPED); 
	
	if (m_intSocket==INVALID_SOCKET){ 
		
		fprintf(stderr,"WSASocket() failed: %d\n",WSAGetLastError()); 
		
		ExitProcess(STATUS_FAILED); 
		
	} 
	
	flag=TRUE; 
	
	ErrorCode=setsockopt(m_intSocket,IPPROTO_IP,IP_HDRINCL,(char *)&flag,sizeof(int)); 	
	if (ErrorCode==SOCKET_ERROR) printf("Set IP_HDRINCL Error!\n"); 
	
	
	
	
	return 0;
}

int CRawSocket::SetOptions()
{
	
	
	int ErrorCode; 
	int TimeOut=200,SendSEQ=0; 
	
	ErrorCode=setsockopt(this->m_intSocket,
		SOL_SOCKET,SO_SNDTIMEO,
		(char*)&TimeOut,
		sizeof(TimeOut)); 
	
	if(ErrorCode==SOCKET_ERROR){ 
		
		fprintf(stderr,"Failed to set send TimeOut: %d\n",WSAGetLastError()); 
		
		//__leave; 
		
	} 
	
	return 0;
}

int CRawSocket::SetDestAddress(const char *dest)
{
	struct sockaddr_in DestAddr; 
	memset(&DestAddr,0,sizeof(DestAddr)); 
	
	DestAddr.sin_family=AF_INET; 
	
	DestAddr.sin_addr.s_addr=inet_addr(dest); 
	
	if (bind(this->m_intSocket,(PSOCKADDR)&DestAddr, sizeof(DestAddr)) == SOCKET_ERROR)
	{
		
		fprintf(stderr,"WSASocket() failed: %d\n",WSAGetLastError()); 
		closesocket( this->m_intSocket ) ;
		return 0;
	} 
	return 0;
	
}

int CRawSocket::SetMixtureMode()
{
	unsigned long dwBufferInLen=1;
	unsigned long dwBufferLen=1;
	unsigned long dwBytesReturned=1;
	int ErrorCode=0;
	
	ErrorCode = WSAIoctl( this->m_intSocket, 
		SIO_RCVALL , //重点位置
		&dwBufferInLen,
		sizeof(dwBufferInLen),             
		&dwBufferLen, 
		sizeof(dwBufferLen),
		&dwBytesReturned , 
		NULL , 
		NULL);
	
	if(SOCKET_ERROR !=ErrorCode){
		return 0;
	}else{
		return 1;
	}
	
}



int CRawSocket::Monitor()
{
	
	
	
	char  buf [655536] , *bufwork ;
	int   iRet ;
	char *data=NULL;;
	
	char  *pSource , *pDest ;
	_iphdr *pIpHeader ;
	_tcphdr *pTcpHeader ;
	_udphdr *pUdpHeader ;
	in_addr ina ;
	char   szSource [16] , szDest[16] ;
	char *pLastBuf = NULL ;	
	
	memset(buf,0,sizeof(buf));
	
	
	iRet = 	recv( this->m_intSocket , buf , sizeof(buf) , 0 ) ;
	
	if( iRet == SOCKET_ERROR )
	{
		fprintf(stderr,"WSASocket() failed: %d\n",WSAGetLastError()); 
		Sleep(1000);
		goto End;
		
	}else if( *buf ){
		
		bufwork   = buf ;
		pIpHeader = ( _iphdr *)bufwork ;
		WORD iLen = ntohs(pIpHeader->total_len) ;
		//printf("%d.%d.%d.%d",*(c),*(c+1) %256,*(c+2) %256,*(c+3) %256);
		
		ina.S_un.S_addr = pIpHeader->sourceIP ;
		pSource = inet_ntoa( ina ) ;
		strcpy( szSource , pSource ) ;
		ina.S_un.S_addr = pIpHeader->destIP ;
		pDest = inet_ntoa( ina ) ;
		strcpy( szDest , pDest ) ;
		
#if 1
		printf("\n[%4s]%16s =>%16s < %05u >", 
			this->GetProtocolName( pIpHeader->proto),
			szSource,
			szDest,
			ntohs(pIpHeader->total_len));
#endif
		
		if(pIpHeader->proto==IPPROTO_TCP){
			
			pTcpHeader = ( _tcphdr *)(bufwork+sizeof(_iphdr));
			data=(char*)pTcpHeader+sizeof(_tcphdr);
			//data[256]=0;
			unsigned short sport=ntohs(pTcpHeader->th_sport);
			unsigned short cport=ntohs(pTcpHeader->th_dport);
			unsigned short offset=(pTcpHeader->th_lenres&0xf0)>>4;
			unsigned short length=ntohs(pIpHeader->total_len)
				-sizeof(_iphdr)
				-sizeof(_tcphdr);
			//data[256]=0;
			char *realdata=data;
			if(pTcpHeader->th_lenres!=0x50)
			{
				realdata=data+12;
				
			}
			if(isNeedShowContent(cport)||isNeedShowContent(sport))
			{
				
				printf("\n ===============%5u->%5u================= \n%s",
					ntohs(pTcpHeader->th_sport),
					ntohs(pTcpHeader->th_dport),
					realdata
					);	
				
			}else{
				
				printf("%5u->%5u",
					ntohs(pTcpHeader->th_sport),
					::ntohs(pTcpHeader->th_dport)				
					);
			}
			
		} else	if(pIpHeader->proto==IPPROTO_UDP){
			
			pUdpHeader = ( _udphdr *)(bufwork+sizeof(_iphdr));
			data=(char*)pUdpHeader+sizeof(_udphdr);
			data[16]=0;
#if 1
			printf("%5u->%5u",
				ntohs(pUdpHeader->uh_sport),
				::ntohs(pUdpHeader->uh_dport)				
				);
#endif
		} else{
			
			
		}
		//data=NULL;
		//Sleep(50) ; 	
		
	}
	return 1;
End:
	return 0;
}
static int parseToArray(const char *input, unsigned short *ports,int length,char sep=',')
{
	char msg[1024];	
	int i=0;
	int counter = 1;
	char *p=msg;
	strcpy(msg,input);	
	if(length>0) *ports=0;
	while(*(p)){
		if(*p==sep)
		{
			*(ports+counter)=i+1;			
			counter++;			
		}
		p++;
		i++;
	}
	p=msg;
	
	for(int j=0;j<counter;j++)
	{
		//printf("%d,",*(ports+j));
		*(ports+j)=(unsigned short)atoi(msg+(*(ports+j)));		
	}
	return counter;
}
void CRawSocket::SetFilteredPorts(const char *portsExpr)
{
	this->filteredPortsCount=parseToArray(portsExpr,this->filteredPorts,1024);
}

bool CRawSocket::isNeedShowContent(unsigned int port)
{
	bool ret = false;
	for(int i=0;i<this->filteredPortsCount;i++)
	{
		if(port==this->filteredPorts[i])
		{
			ret = true;
			break;
		}
	}
	return ret;
}
