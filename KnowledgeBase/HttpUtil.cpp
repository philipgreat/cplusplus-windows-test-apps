// HttpUtil.cpp: implementation of the CHttpUtil class.
//
//////////////////////////////////////////////////////////////////////
#include "HttpUtil.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "stdafx.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#define SAFE_DELETE(x)    if(NULL!=x) {delete x;x=NULL;}
CHttpUtil::CHttpUtil()
{
	buffer=new char[1024*8];
}

CHttpUtil::~CHttpUtil()
{
	delete[] buffer;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
static int SockConnect(char *domain,short port) 
{

	int white_sock; 
	struct hostent * site; 
	struct sockaddr_in me; 

	memset(&me,0,sizeof(struct sockaddr_in)); 
	me.sin_addr.s_addr=inet_addr(domain);
	
	if (me.sin_addr.s_addr==(DWORD)-1){
		site = gethostbyname(domain);
		memcpy(&me.sin_addr,site->h_addr_list[0],site->h_length);
	}
	white_sock = socket(AF_INET,SOCK_STREAM,0); 
	//NOTE: found memory error here in pc edition 
	//this is a known bug in windows socket 

	if (white_sock<0) return -1; 	
	
	me.sin_family = AF_INET; 
	me.sin_port = htons(port); 
	
	return (connect(white_sock,(struct sockaddr *)&me,sizeof(struct sockaddr))<0) ? -1 : white_sock; 
}   

static int SockSend(int sock,char *fmt,...) 
{ 
	char BUF[1024]; 
	va_list argptr; 
	va_start(argptr,fmt); 
	vsprintf(BUF,fmt,argptr); 
	va_end(argptr); 
	return send(sock,BUF,strlen(BUF),0); 
}
static int SeekDoubleReturn(const char *buffer,int len)
{
	char *p=(char*)buffer;
	int i=0;
	//printf("i = %s\n",buffer);
	while(memcmp(p,"\r\n\r\n",4) != 0 
		&&memcmp(p,"\n\r\n\r",4) !=0
		&&p-buffer<len){
		p++;
		i++;
	}
	//abcd1234
	//01234567890
	//if want ignore the strings , please +4 for your application
	return i;
}

int CHttpUtil::ProcessGet(const char *url,BYTE *retData,DWORD *maxLen)
{
	
	int clientSocket; 
	int len = 0;
	double avgsize = 0.0f;
	double span = 0.0f;
	double avg = 0.0f;

	//if (argc<2) return 1; 
	DWORD count = 0;
	DWORD total = 0;
	DWORD state = 0;
	DWORD dataSize = 1024;
	unsigned short port = 0;	

	char *phost;
	char *ppath;
	char *proto;

	this->ParseURL(url,&proto,&phost,&port,&ppath);
	//
	clientSocket = SockConnect(phost,port); 
	//clientSocket = SockConnect("10.130.100.2",80); 

	if (clientSocket<0) {
		printf("error on connect; maybe you need use WSAStartup to initiate your env\n");

		return HTTP_ERROR_CONNECT; 
	}
	//MultiByteToWideChar

	SockSend(clientSocket,"GET /%s HTTP/1.0\r\n\r\n",ppath); 
	char *recvBuffer=new char[1024];
	memset(recvBuffer,0,dataSize);

	if ((len=recv(clientSocket,recvBuffer,dataSize-1,0))>0) { 
		//printf("error on recv %d %s\n",len,recvBuffer);
		int i=SeekDoubleReturn(recvBuffer,len);	
		DWORD copyLen=(len-i-4)+1< *maxLen?(len-i-4)+1:*maxLen;
		*maxLen=copyLen;
		memcpy(retData,recvBuffer+i+4,copyLen);
		//printf("error on recv %s\n",retData);
	} 


	delete[] recvBuffer;
	closesocket(clientSocket);
	return 0;
}

int CHttpUtil::ProcessPost(const char *url,
						   BYTE *sendData,DWORD *sendMaxLen,
						   BYTE *retData,DWORD *maxLen)
{

	int clientSocket; 
	int len = 0;
	double avgsize = 0.0f;
	double span = 0.0f;
	double avg = 0.0f;

	//if (argc<2) return 1; 
	DWORD count = 0;
	DWORD total = 0;
	DWORD state = 0;
	DWORD dataSize = 1024;
	unsigned short port = 0;	

	char *phost;
	char *ppath;
	char *proto;

	this->ParseURL(url,&proto,&phost,&port,&ppath);
	//
	clientSocket = SockConnect(phost,port); 
	//clientSocket = SockConnect("10.130.100.2",80); 

	if (clientSocket<0) {
		printf("error on connect; maybe you need use WSAStartup to initiate your env\n");

		return HTTP_ERROR_CONNECT; 
	}
	//MultiByteToWideChar

	SockSend(clientSocket,"GET /%s HTTP/1.0\r\n\r\n",ppath); 
	char *recvBuffer=new char[1024];
	memset(recvBuffer,0,dataSize);

	if ((len=recv(clientSocket,recvBuffer,dataSize-1,0))>0) { 
		//printf("error on recv %d %s\n",len,recvBuffer);
		int i=SeekDoubleReturn(recvBuffer,len);	
		DWORD copyLen=(len-i-4)+1< *maxLen?(len-i-4)+1:*maxLen;
		*maxLen=copyLen;
		memcpy(retData,recvBuffer+i+4,copyLen);
		//printf("error on recv %s\n",retData);
	} 


	delete[] recvBuffer;
	closesocket(clientSocket);
	return 0;


}

static enum URL_PARSE_STATE{URL_START=0,
					 URL_PROT_START,
					 URL_PROT_IN,
					 URL_PROT_END,
					 URL_HOST_START,
					 URL_HOST_IN,
					 URL_HOST_END,
					 URL_PORT_START,
					 URL_PORT_IN,
					 URL_PORT_END,
					 URL_PATH_START,
					 URL_PATH_IN,
					 URL_PATH_END,
					 URL_END};

int CHttpUtil::ParseURL(const char *url, 
						char **proto,
						char **host, 
						unsigned short *port, 
						char **path)
{
	//该函数看起来有一些奇怪, 输入的指针只是指向了输入的字符串
	int		len=strlen(url)+1;
	char	*header=NULL;
	int		state=URL_START;
	char	*pproto=NULL;
	char	*phost=NULL;
	unsigned short nport=0;
	char	*ppath=NULL;
	char	*pport=NULL;

	*port=80;

	char *p=header=this->buffer;

	memcpy(this->buffer,url,len);
	//不要轻易改变该段代码,在更改之前需要经过比较详细的状态机分析

	while(p-header<len)
	{
		
		switch(state){
		case URL_START:
			state=URL_PROT_START;
			//break;
		case URL_PROT_START:
			pproto=p;
			state=URL_PROT_IN;
			break;
		case URL_PROT_IN:
			if(*p==':'){
				*p='\0';
				state=URL_PROT_END;
			}
			break;
		case URL_PROT_END:
			if(*p=='/'&&*(p-1)=='/')
			{
				*p='\0';
				*(p-1)='\0';
				state=URL_HOST_START;			
			}
			
			break;
		case URL_HOST_START:
			if(isalnum(*p)){
				phost=p;
				state=URL_HOST_IN;				
			}
			break;
		case URL_HOST_IN:
			if(*p==':'){
				//phost=p;
				*p='\0';				
				state=URL_HOST_END;				
				state=URL_PORT_START;
			}
			if(*p=='/'){
				//phost=p;
				*p='\0';
				//p--;
				state=URL_HOST_END;
				state=URL_PATH_START;				
			}
			break;
		case URL_PORT_START:
			if(isalnum(*p)){
				pport=p;
				state=URL_PORT_IN;
			}
			break;
		case URL_PORT_IN:
			if(*p=='/'){
				//*p='\0';
				//state=URL_PORT_END;
				//p--;
				state=URL_PORT_END;
				state=URL_PATH_START;
				//p--;
			}
			break;
		case URL_PATH_START:
			ppath=p;
			state=URL_PATH_IN;		
			break;		
		case URL_PATH_IN:
			//ppath=p;
			//state=URL_PATH_IN;		
			break;
		default:			
			break;
		
		}
		//printf("%d %s \n",state,p);
		p++;
	
	}

	*host=phost;
	*proto=pproto;
	*path=ppath;
	*port=(pport==NULL?80:atoi(pport));

	//SAFE_DELETE(header);

	
	return 0;
}

void CHttpUtil::InitNetwork()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	BOOL stateWrite=FALSE;
	/*=======================================================================*/

	wVersionRequested = MAKEWORD( 1, 1 );
	err = WSAStartup( wVersionRequested, &wsaData );
}

void CHttpUtil::UninitNetwork()
{
	::WSACleanup();
}
