// TCPServer.cpp: implementation of the CTCPServer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TCPServer.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
static void InitSocketEnvironment()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	/*=======================================================================*/
	wVersionRequested = MAKEWORD( 2, 2 );
	err = WSAStartup( wVersionRequested, &wsaData );
}
static void UninitSocketEnvironment()
{
	::WSACleanup();
}

static void InitServer(int *pSockfd,unsigned short port)
{
	
	struct sockaddr_in svraddr; 
	
	if((*pSockfd=socket(AF_INET,SOCK_STREAM,0))==-1){
		printf("Create sock error");
		exit(1);
	}
	memset(&svraddr,0,sizeof(svraddr));
	svraddr.sin_family=AF_INET;
	svraddr.sin_port=htons(port);
	svraddr.sin_addr.s_addr=htonl(INADDR_ANY); 
	if(bind(*pSockfd,(struct sockaddr *)&svraddr,sizeof(struct sockaddr))==-1)
	{
		printf("Bind error");
		exit(1);
	} 
	if(listen(*pSockfd,5)==-1)
	{
		printf("Listen error");
		exit(1);
		
	}
}

CTCPServer::CTCPServer()
{
	InitSocketEnvironment();
	this->port=7866;
	InitServer(&this->listenSocket,this->port);
	
}
CTCPServer::CTCPServer(int port)
{
	InitSocketEnvironment();
	this->port=port;
	InitServer(&this->listenSocket,this->port);
}
CTCPServer::~CTCPServer()
{
	closesocket(this->listenSocket);
	UninitSocketEnvironment();
}

int CTCPServer::AcceptConnection(char** ppAddr,
								 unsigned short *pPort)
{
	int clientSocket=0;
	struct sockaddr_in addr;
	memset(&addr,0,sizeof(sockaddr));
	int addrlen=sizeof(struct sockaddr_in);
	clientSocket=accept(
		this->listenSocket,
		(struct sockaddr*)&addr,//sockaddr*
		&addrlen);

	*pPort=addr.sin_port;
	*ppAddr=inet_ntoa(addr.sin_addr);

	//printf("connect from %s: %d\n",inet_ntoa(addr.sin_addr),addr.sin_port);
	
	return clientSocket;


}
#include "SocketSession.h"
#include "AjaxSession.h"
#include <stdio.h>
int CTCPServer::Run()
{
	int socket;
	char *pClientIP;
	unsigned short usport;
	HANDLE handle=NULL;


	while((socket=this->AcceptConnection(&pClientIP,&usport))>0){
	
		//CAjaxSession *pTask = new CAjaxSession(socket);
		CSocketSession *pTask = new CSocketSession(socket);
		pTask->SetConnectInfo(pClientIP,ntohs(usport));
		handle=CTCPServer::RunTask(pTask,&this->serverContext);
		if(handle) CloseHandle(handle);
		
	}
	return 0;
}



DWORD __stdcall CTCPServer::ThreadWork(void *pTask)
{	
	CCommonTask *p=(CCommonTask*)pTask;
	p->OnStart();

	while(1){
		int i=p->Run();
		if(i<=0) break;
	}
	p->OnEnd();
	delete p;
	return 0;
}



HANDLE CTCPServer::RunTask(CCommonTask *pTask, CCommonContext *pContext)
{
	
	//每个工作线程	1
	//accept		2

	HANDLE hThread=NULL;
	DWORD threadId=0;
	pTask->SetContext(pContext);
	hThread=::CreateThread(
		NULL,
		40*1024,
		ThreadWork,
		(void*)pTask,0,&threadId);
	return hThread;

}