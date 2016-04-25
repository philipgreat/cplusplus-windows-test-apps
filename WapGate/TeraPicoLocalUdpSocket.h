
#ifndef  TERA_PICO_LOCAL_UDP_SOCKET_ClASS
#define  TERA_PICO_LOCAL_UDP_SOCKET_ClASS
#include "TeraPicoCommon.h"

namespace terapico{

class CTeraPicoLocalUdpSocket
{
private:
	
	long	m_lngId;
	int	m_intFd;
	int	m_intPort;
	
	
public:

	CTeraPicoLocalUdpSocket();
	CTeraPicoLocalUdpSocket(
		long	id,
		int	fd,
		int	port);
	virtual ~CTeraPicoLocalUdpSocket();

	bool Reset(
		int	fd,
		int	port);
	
	long GetId();
	void SetId(long id);
	
	int GetFd();
	void SetFd(int fd);
	
	int GetPort();
	void SetPort(int port);
	

};//end of  class CTeraPicoLocalUdpSocket

typedef CTeraPicoLocalUdpSocket* pLocalUdpSocket;
typedef CTeraPicoLocalUdpSocket LocalUdpSocket;

}//end of namespace terapico

#endif //TERA_PICO_LOCAL_UDP_SOCKET_ClASS




