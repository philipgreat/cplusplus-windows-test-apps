// UDPServer1.cpp: implementation of the CUDPServer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UDPServer1.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUDPServer::CUDPServer()
{
	
}
CUDPServer::CUDPServer(unsigned short port):
	serviceHandler(NULL)
{
	serverAddr.sin_family      = AF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_port        = htons(port);	
	
}
CUDPServer::CUDPServer(const char* bindIP,unsigned short port):
	serviceHandler(NULL)
{
	serverAddr.sin_family      = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr(bindIP);
	serverAddr.sin_port        = htons(port);	
}
CUDPServer::~CUDPServer()
{
	closesocket(serverSocket);	
}

int CUDPServer::Bind()
{
	serverSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (serverSocket == INVALID_SOCKET){
		printf("error in socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)");
		return CUDPServer::UDP_SOCKET_ERROR_BIND;
	}
	
	if (bind(serverSocket, (sockaddr *) &serverAddr, sizeof(sockaddr)) == SOCKET_ERROR)
	{
		printf("bind(serverSocket, (sockaddr *) &serverAddr, sizeof(sockaddr)) == SOCKET_ERROR");

		return CUDPServer::UDP_SOCKET_ERROR_BIND;
	}
	return 0;
}

int CUDPServer::Send(BYTE *buffer, int len)
{
	//send 
	return sendto(serverSocket, 
		(char*)buffer, 
		len, 
		0, (sockaddr *)
		&clientAddr, sizeof(clientAddr));	
}

int CUDPServer::Recv(BYTE *buffer, int len, int timeout)
{	
	//has timeout functions
	
	int result;
	struct timeval tv;
	fd_set readfds;
	int retLength=0;
	int fromlen = 0;
	FD_ZERO(&readfds);
	FD_SET(serverSocket, &readfds);
	tv.tv_sec=timeout;
	tv.tv_usec=0;

	result = select(serverSocket+1, &readfds, (fd_set*)NULL, (fd_set*)NULL, &tv);

	
	if(result > 0){
		memset(&clientAddr,0x00,sizeof(clientAddr));
		fromlen=sizeof(sockaddr);
		retLength = recvfrom(serverSocket, (char*)buffer, len, 0, (sockaddr *)&clientAddr, &fromlen);
		//error
	}else if(result == 0){
		//timeout
		return CUDPServer::UDP_SOCKET_RECV_TIMEOUT;
	}else{		
		//error
		return CUDPServer::UDP_SOCKET_RECV_FATAL;

	}
	return retLength;
	
}


int CUDPServer::Run()
{
	this->Bind();
	CServiceRequest request;
	CServiceRequest response;

	while(1){
		//recv package
		//reuse a response
		//
		//invoke the serviceobject method
		int state=0;
		state=this->Recv((BYTE*)&request,sizeof(CServiceRequest));
		//printf("server.Recv %d\n",state);
		if(state==CUDPServer::UDP_SOCKET_RECV_TIMEOUT){
			//printf("recv timeout \n");		
		}else if(state==CUDPServer::UDP_SOCKET_RECV_FATAL){
			//printf("recv fail \n");	
			Sleep(1000);
		}else{
			//printf("recv ok \n");
			//CServiceRequest *req=(CServiceRequest*)buffer;

			request.Show();
			if(NULL!=this->serviceHandler){
				
				serviceHandler->Invoke(&request,&response);
				state=this->Send((BYTE*)&response,sizeof(CServiceRequest));
				printf("server.Send %d\n",state);
			
			}
		}		
	
	}
}

void CUDPServer::SetServiceHandler(CServiceObject *handler)
{
	this->serviceHandler=handler;
}

void CUDPServer::Close()
{
	closesocket(this->serverSocket);
}
