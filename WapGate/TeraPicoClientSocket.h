
#ifndef  TERA_PICO_CLIENT_SOCKET_ClASS
#define  TERA_PICO_CLIENT_SOCKET_ClASS
#include "TeraPicoCommon.h"

#include "TeraPicoHttpContent.h"
	
namespace terapico{

class CTeraPicoClientSocket
	:public CTeraPicoCommonObject
{
private:
	
	long	m_lngId;
	int	m_intFd;
	int	m_intPort;
	pHttpContent	m_objContent;
	
	
public:
	int Recv(char* p,int len);
	int Send(const char*p,int len);
	int Close();

	CTeraPicoClientSocket();
	CTeraPicoClientSocket(
		long	id,
		int	fd,
		int	port,
		pHttpContent	content);
	virtual ~CTeraPicoClientSocket();

	bool Reset(
		int	fd,
		int	port,
		pHttpContent	content);
	
	long GetId();
	void SetId(long id);
	
	int GetFd();
	void SetFd(int fd);
	
	int GetPort();
	void SetPort(int port);
	
	pHttpContent GetContent();
	void SetContent(pHttpContent content);
	

};//end of  class CTeraPicoClientSocket

typedef CTeraPicoClientSocket* pClientSocket;
typedef CTeraPicoClientSocket ClientSocket;

}//end of namespace terapico

#endif //TERA_PICO_CLIENT_SOCKET_ClASS


