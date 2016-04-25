
#include "TeraPicoRemoteUdpSocket.h"

namespace terapico{

CTeraPicoRemoteUdpSocket::CTeraPicoRemoteUdpSocket()
{

}

CTeraPicoRemoteUdpSocket::CTeraPicoRemoteUdpSocket(
		long	id,
		int	fd,
		pchar	host_name,
		int	port)
{
	int    sockfd=0;
	struct sockaddr_in 	sin;
	struct hostent 		*he;
	
	if((sockfd=socket(AF_INET,SOCK_DGRAM,0))==-1){
		
		perror("Create sock error");
		MessageBox (NULL,"sockfd=socket(AF_INET,SOCK_DGRAM,0))=-1!!","ÑÏÖØ´íÎó",0);
		//exit(1);
	}
	//MessageBox (NULL,"asd","asdasd",0);

	if((he=gethostbyname(host_name))==NULL)
	{ 
	        
	      perror("Client host name:"); 
	      //exit(1);
	}

	sin.sin_family=AF_INET;
	sin.sin_port=htons(port);
	sin.sin_addr=*((struct in_addr *)he->h_addr);

	if(connect(sockfd,
		(struct sockaddr *)&sin,
		sizeof(struct sockaddr))==-1)
	{
                /*I  made mistakes here!!!!!remmber*/
		perror("Connect error");
		//return NULL;
		//exit(1);
	}


	SetId(id);
	SetFd(sockfd);
	SetHostName(host_name);
	SetPort(port);
}


CTeraPicoRemoteUdpSocket::~CTeraPicoRemoteUdpSocket()
{

}

bool CTeraPicoRemoteUdpSocket::Reset(
		int	fd,
		pchar	host_name,
		int	port)
{
	
	SetFd(fd);
	SetHostName(host_name);
	SetPort(port);
	return true;
}


void  CTeraPicoRemoteUdpSocket::SetId(long id)
{
	this->m_lngId=id;
}
long CTeraPicoRemoteUdpSocket::GetId()
{
	return this->m_lngId;
}

void  CTeraPicoRemoteUdpSocket::SetFd(int fd)
{
	this->m_intFd=fd;
}
int CTeraPicoRemoteUdpSocket::GetFd()
{
	return this->m_intFd;
}

void  CTeraPicoRemoteUdpSocket::SetHostName(pchar host_name)
{
	this->m_strHostName=host_name;
}
pchar CTeraPicoRemoteUdpSocket::GetHostName()
{
	return this->m_strHostName;
}

void  CTeraPicoRemoteUdpSocket::SetPort(int port)
{
	this->m_intPort=port;
}
int CTeraPicoRemoteUdpSocket::GetPort()
{
	return this->m_intPort;
}

int CTeraPicoRemoteUdpSocket::Send(const char *p)
{
	int len=strlen(p);
	return this->Send(p,len);

}

int CTeraPicoRemoteUdpSocket::Send(const char *p, int len)
{

	int l=0;
	
#ifdef WIN32
	l=send(this->GetFd (),p,len,0);
#else
	l=write(this->GetFd (),p,len,0);
#endif

	return l;

}

int CTeraPicoRemoteUdpSocket::Recv(char *p)
{
	int len=strlen(p);
	return this->Recv(p,len);
}

int CTeraPicoRemoteUdpSocket::Recv(char *p, int len)
{

	int l=0;

#ifdef WIN32
	l=recv(this->GetFd (),p,len,0);
#else
	l=read(this->GetFd (),p,len,0);
#endif

	return l;
}

int CTeraPicoRemoteUdpSocket::Close()
{
#ifdef WIN32
	closesocket(this->GetFd ());
#else
	close(this->GetFd ());
#endif
	

	return 0;	
}

int CTeraPicoRemoteUdpSocket::ShutDown(int how)
{
	shutdown(this->GetFd (),how);
	return how;
}

}//end of namespace terapico



