
#include "TeraPicoClientSocket.h"

namespace terapico{

CTeraPicoClientSocket::CTeraPicoClientSocket()
{

}

CTeraPicoClientSocket::CTeraPicoClientSocket(
		long	id,
		int	fd,
		int	port,
		pHttpContent	content)
{

	SetId(id);
	SetFd(fd);
	SetPort(port);
	SetContent(content);
}


CTeraPicoClientSocket::~CTeraPicoClientSocket()
{

}

bool CTeraPicoClientSocket::Reset(
		int	fd,
		int	port,
		pHttpContent	content)
{
	
	SetFd(fd);
	SetPort(port);
	SetContent(content);
	return true;
}


void  CTeraPicoClientSocket::SetId(long id)
{
	this->m_lngId=id;
}
long CTeraPicoClientSocket::GetId()
{
	return this->m_lngId;
}

void  CTeraPicoClientSocket::SetFd(int fd)
{
	this->m_intFd=fd;
}
int CTeraPicoClientSocket::GetFd()
{
	return this->m_intFd;
}

void  CTeraPicoClientSocket::SetPort(int port)
{
	this->m_intPort=port;
}
int CTeraPicoClientSocket::GetPort()
{
	return this->m_intPort;
}

void  CTeraPicoClientSocket::SetContent(pHttpContent content)
{
	this->m_objContent=content;
}
pHttpContent CTeraPicoClientSocket::GetContent()
{
	return this->m_objContent;
}

int CTeraPicoClientSocket::Close()
{
#ifdef WIN32
	closesocket(this->GetFd ());
#else
	close(this->GetFd ());
#endif
	

	return 0;	
}

int CTeraPicoClientSocket::Send(const char *p, int len)
{

	int l=0;
	
#ifdef WIN32
	l=send(this->GetFd (),p,len,0);
#else
	l=write(this->GetFd (),p,len,0);
#endif

	return l;

}

int CTeraPicoClientSocket::Recv(char *p, int len)
{

	int l=0;

#ifdef WIN32
	l=recv(this->GetFd (),p,len,0);
#else
	l=read(this->GetFd (),p,len,0);
#endif

	return l;
}


}//end of namespace terapico


