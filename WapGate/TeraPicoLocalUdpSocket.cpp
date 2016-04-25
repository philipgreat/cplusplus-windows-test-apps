
#include "TeraPicoLocalUdpSocket.h"

namespace terapico{

CTeraPicoLocalUdpSocket::CTeraPicoLocalUdpSocket()
{

}

CTeraPicoLocalUdpSocket::CTeraPicoLocalUdpSocket(
		long	id,
		int	fd,
		int	port)
{

	SetId(id);
	SetFd(fd);
	SetPort(port);
}


CTeraPicoLocalUdpSocket::~CTeraPicoLocalUdpSocket()
{

}

bool CTeraPicoLocalUdpSocket::Reset(
		int	fd,
		int	port)
{
	
	SetFd(fd);
	SetPort(port);
	return true;
}


void  CTeraPicoLocalUdpSocket::SetId(long id)
{
	this->m_lngId=id;
}
long CTeraPicoLocalUdpSocket::GetId()
{
	return this->m_lngId;
}

void  CTeraPicoLocalUdpSocket::SetFd(int fd)
{
	this->m_intFd=fd;
}
int CTeraPicoLocalUdpSocket::GetFd()
{
	return this->m_intFd;
}

void  CTeraPicoLocalUdpSocket::SetPort(int port)
{
	this->m_intPort=port;
}
int CTeraPicoLocalUdpSocket::GetPort()
{
	return this->m_intPort;
}


}//end of namespace terapico





