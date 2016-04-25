
#include "TeraPicoRemoteSocket.h"

namespace terapico{

CTeraPicoRemoteSocket::CTeraPicoRemoteSocket()
{

}

CTeraPicoRemoteSocket::CTeraPicoRemoteSocket(
		long	id,
		int	fd,
		pchar	host_name,
		int	port,
		pHttpContent	content)
{

	int		sockfd=0;	
	struct   hostent *he;  
    struct   sockaddr_in svraddr;
	


	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
	        perror("Create sock error");
	        exit(1);
	}
	long iostate=1;//1;

	if((he=gethostbyname(host_name))==NULL)
	{ 
	        
	        perror("Client host name:"); 
	        exit(1);
	}    
	memset(&svraddr,0,sizeof(svraddr));
	svraddr.sin_family=AF_INET;
	svraddr.sin_port=htons(port);
	svraddr.sin_addr=*((struct in_addr *)he->h_addr);
	int TimeOut=1000; //ÉèÖÃ·¢ËÍ³¬Ê±1Ãë
	if(setsockopt(sockfd,
			SOL_SOCKET,
			SO_RCVTIMEO,
			(char *)&TimeOut,
			sizeof(TimeOut))==SOCKET_ERROR
			)
	{
		perror("Setsockopt(Recv):"); 
		exit(1);
	}


	if(setsockopt(sockfd,
			SOL_SOCKET,
			SO_RCVTIMEO,
			(char *)&TimeOut,
			sizeof(TimeOut))==SOCKET_ERROR)
	{
		perror("Setsockopt(Send):"); 
		exit(1);
	}
	//printf("\nconnect to remote server");

	connect(sockfd,(struct sockaddr *)&svraddr,sizeof(struct sockaddr));

	//printf("\n the fd is: %d\n",sockfd);

	SetId(id);
	SetFd(sockfd);
	SetHostName(host_name);
	SetPort(port);
	SetContent(content);

}


CTeraPicoRemoteSocket::~CTeraPicoRemoteSocket()
{

}

bool CTeraPicoRemoteSocket::Reset(
		int	fd,
		pchar	host_name,
		int	port,
		pHttpContent	content)
{
	
	SetFd(fd);
	SetHostName(host_name);
	SetPort(port);
	SetContent(content);
	return true;
}


void  CTeraPicoRemoteSocket::SetId(long id)
{
	this->m_lngId=id;
}
long CTeraPicoRemoteSocket::GetId()
{
	return this->m_lngId;
}

void  CTeraPicoRemoteSocket::SetFd(int fd)
{
	this->m_intFd=fd;
}
int CTeraPicoRemoteSocket::GetFd()
{
	return this->m_intFd;
}

void  CTeraPicoRemoteSocket::SetHostName(pchar host_name)
{
	this->m_strHostName=host_name;
}
pchar CTeraPicoRemoteSocket::GetHostName()
{
	return this->m_strHostName;
}

void  CTeraPicoRemoteSocket::SetPort(int port)
{
	this->m_intPort=port;
}
int CTeraPicoRemoteSocket::GetPort()
{
	return this->m_intPort;
}

void  CTeraPicoRemoteSocket::SetContent(pHttpContent content)
{
	this->m_objContent=content;
}
pHttpContent CTeraPicoRemoteSocket::GetContent()
{
	return this->m_objContent;
}
int CTeraPicoRemoteSocket::Send(const char *p, int len)
{

	int l=0;
	
#ifdef WIN32
	l=send(this->GetFd (),p,len,0);
#else
	l=write(this->GetFd (),p,len,0);
#endif

	return l;

}

int CTeraPicoRemoteSocket::Recv(char *p, int len)
{

	int l=0;

#ifdef WIN32
	l=recv(this->GetFd (),p,len,0);
#else
	l=read(this->GetFd (),p,len,0);
#endif

	return l;
}

int CTeraPicoRemoteSocket::Close()
{
#ifdef WIN32
	closesocket(this->GetFd ());
#else
	close(this->GetFd ());
#endif
	

	return 0;	
}

int CTeraPicoRemoteSocket::ShutDown(int how)
{
	shutdown(this->GetFd (),how);
	return how;
}

}//end of namespace terapico


