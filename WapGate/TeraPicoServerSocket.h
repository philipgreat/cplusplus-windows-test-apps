
#ifndef  TERA_PICO_SERVER_SOCKET_ClASS
#define  TERA_PICO_SERVER_SOCKET_ClASS
#include "TeraPicoCommon.h"

namespace terapico{

class CTeraPicoServerSocket
{
private:
	
	long	m_lngId;
	int	m_intFd;
	pchar	m_strHostName;
	int	m_intServerPort;
	
	
public:
	int Service();

	CTeraPicoServerSocket();
	CTeraPicoServerSocket(
		long	id,
		int	fd,
		pchar	host_name,
		int	server_port);
	virtual ~CTeraPicoServerSocket();

	bool Reset(
		int	fd,
		pchar	host_name,
		int	server_port);
	
	long GetId();
	void SetId(long id);
	
	int GetFd();
	void SetFd(int fd);
	
	pchar GetHostName();
	void SetHostName(pchar host_name);
	
	int GetServerPort();
	void SetServerPort(int server_port);
	

};//end of  class CTeraPicoServerSocket

typedef CTeraPicoServerSocket* pServerSocket;
typedef CTeraPicoServerSocket ServerSocket;

}//end of namespace terapico

#endif //TERA_PICO_SERVER_SOCKET_ClASS


