
#ifndef  TERA_PICO_REMOTE_UDP_SOCKET_ClASS
#define  TERA_PICO_REMOTE_UDP_SOCKET_ClASS
#include "TeraPicoCommon.h"

namespace terapico{
	
	class CTeraPicoRemoteUdpSocket
	{
	private:
		
		long	m_lngId;
		int	m_intFd;
		pchar	m_strHostName;
		int	m_intPort;
		
		
	public:
		int Recv(char* p);
		int Send(const char *p);
		
		CTeraPicoRemoteUdpSocket();
		CTeraPicoRemoteUdpSocket(
			long	id,
			int	fd,
			pchar	host_name,
			int	port);
		virtual ~CTeraPicoRemoteUdpSocket();
		
		bool Reset(
			int	fd,
			pchar	host_name,
			int	port);
		
		long GetId();
		void SetId(long id);
		
		int GetFd();
		void SetFd(int fd);
		
		pchar GetHostName();
		void SetHostName(pchar host_name);
		
		int GetPort();
		void SetPort(int port);
		
		int Recv(char* p,int len);
		int Send(const char*p,int len);
		int ShutDown(int how);
		int Close();
		
		
	};//end of  class CTeraPicoRemoteUdpSocket
	
	typedef CTeraPicoRemoteUdpSocket* pRemoteUdpSocket;
	typedef CTeraPicoRemoteUdpSocket RemoteUdpSocket;
	
}//end of namespace terapico

#endif //TERA_PICO_REMOTE_UDP_SOCKET_ClASS
