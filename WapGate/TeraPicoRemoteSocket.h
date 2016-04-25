
#ifndef  TERA_PICO_REMOTE_SOCKET_ClASS
#define  TERA_PICO_REMOTE_SOCKET_ClASS
#include "TeraPicoCommon.h"

#include "TeraPicoHttpContent.h"
	
namespace terapico{

class CTeraPicoRemoteSocket
{
private:
	
	long	m_lngId;
	int	m_intFd;
	pchar	m_strHostName;
	int	m_intPort;
	pHttpContent	m_objContent;
	
	
public:
	int ShutDown(int how);

	CTeraPicoRemoteSocket();
	CTeraPicoRemoteSocket(
		long	id,
		int	fd,
		pchar	host_name,
		int	port,
		pHttpContent	content);
	virtual ~CTeraPicoRemoteSocket();

	bool Reset(
		int	fd,
		pchar	host_name,
		int	port,
		pHttpContent	content);
	
	long GetId();
	void SetId(long id);
	
	int GetFd();
	void SetFd(int fd);
	
	pchar GetHostName();
	void SetHostName(pchar host_name);
	
	int GetPort();
	void SetPort(int port);
	
	pHttpContent GetContent();
	void SetContent(pHttpContent content);
	
	int Recv(char* p,int len);
	int Send(const char*p,int len);
	int Close();

};//end of  class CTeraPicoRemoteSocket

typedef CTeraPicoRemoteSocket* pRemoteSocket;
typedef CTeraPicoRemoteSocket RemoteSocket;

}//end of namespace terapico

#endif //TERA_PICO_REMOTE_SOCKET_ClASS


