
#include "TeraPicoServerSocket.h"

#include "TeraPicoClientSocket.h"
#include "TeraPicoHttpBody.h"

#include "TeraPicoRemoteSocket.h"
#include "TeraPicoRemoteUdpSocket.h"
#include "TeraPicoLogFile.H"
namespace terapico{

CTeraPicoServerSocket::CTeraPicoServerSocket()
{
	struct sockaddr_in sin;
	
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	
	memset(&sin, 0, sizeof(sin));
	//sin.sin_port = htons(8090);
	sin.sin_port = htons(8090);

	sin.sin_family=AF_INET;
	bind(sock, (struct sockaddr *) &sin, sizeof (sin));
	listen(sock, 5);
	SetFd(sock);

	this->Service ();

	
}

CTeraPicoServerSocket::CTeraPicoServerSocket(
		long	id,
		int	fd,
		pchar	host_name,
		int	server_port)
{

	SetId(id);
	SetFd(fd);
	SetHostName(host_name);
	SetServerPort(server_port);
}


CTeraPicoServerSocket::~CTeraPicoServerSocket()
{
	
}

bool CTeraPicoServerSocket::Reset(
		int	fd,
		pchar	host_name,
		int	server_port)
{
	
	SetFd(fd);
	SetHostName(host_name);
	SetServerPort(server_port);
	return true;
}


void  CTeraPicoServerSocket::SetId(long id)
{
	this->m_lngId=id;
}
long CTeraPicoServerSocket::GetId()
{
	return this->m_lngId;
}

void  CTeraPicoServerSocket::SetFd(int fd)
{
	this->m_intFd=fd;
}
int CTeraPicoServerSocket::GetFd()
{
	return this->m_intFd;
}

void  CTeraPicoServerSocket::SetHostName(pchar host_name)
{
	this->m_strHostName=host_name;
}
pchar CTeraPicoServerSocket::GetHostName()
{
	return this->m_strHostName;
}

void  CTeraPicoServerSocket::SetServerPort(int server_port)
{
	this->m_intServerPort=server_port;
}
int CTeraPicoServerSocket::GetServerPort()
{
	return this->m_intServerPort;
}


int CTeraPicoServerSocket::Service()
{
	int fd=0;
	struct sockaddr_in sin;
	int len = sizeof(sin);
	int seqno=0;
	RemoteUdpSocket *prus=new RemoteUdpSocket(100,0,"127.0.0.1",16800);
	LogFile *plf=new LogFile(0,
			"C:\\lcc\\projects\\standard\\src\\save.dat",
			1024*1024,
			0,
			NULL,
			NULL
			);

	while(fd = accept(this->GetFd(), (struct sockaddr *) &sin, &len))
	{
		++seqno;
		ClientSocket *pcs=new ClientSocket(seqno,fd,sin.sin_port,NULL);
		//here create a thread!
		//TransTheData;
		char info[2048+128]={0};
		char data[2048]={0};
	
		int l=pcs->Recv(data,2048);

		//int l=0;
		sprintf(info,"\r\nRecv data from  host (len = %d):\r\n%s\r\n",
			l,
			data
			);
		plf->Logging(info);
		
		prus->Send(info,strlen(info)); 
		//pcs->Send(data,l); 
		
		RemoteSocket *prs=new RemoteSocket(seqno,0,"127.0.0.1",80,NULL);
		//RemoteSocket *prs=new RemoteSocket(seqno,0,"127.0.0.1",389,NULL);

		
		//printf("\nSending to remote host");
		
		//while(0<);
		prs->Send (data,l);
		//printf("\nToShutDown");
		
		//prs->ShutDown (1);

		//printf("\nRecving data from  remote host");

		while((l=prs->Recv(data,2048))>0){
			printf("\nlen = %6d",l);
			pcs->Send(data,l);	
		}

		//pcs->SetContent (new HttpContent(
		prs->Close ();
		pcs->Close ();
		
		if(prs) delete prs;
		if(pcs) delete pcs;
		
	}
	return 0;
}


}//end of namespace terapico


