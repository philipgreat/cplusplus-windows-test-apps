// UDPServer1.h: interface for the CUDPServer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UDPSERVER1_H__CC45160A_EEC6_465A_B602_84E005BDDE31__INCLUDED_)
#define AFX_UDPSERVER1_H__CC45160A_EEC6_465A_B602_84E005BDDE31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#ifndef  _WIN32_WCE
#pragma comment(lib,"ws2_32")
#include <Winsock2.h>
#else
#pragma comment(lib,"ws2")
#include <Winsock.h>
#endif
#include <windows.h>
#include <winsock.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ServiceObject.h"
//F:/suddy/settopbox/bin/Release/UdpServer.exe
//d:/resin-2.1.16/doc/UdpServer.exe

class CUDPServer  
{

private:
	CServiceObject *serviceHandler;
	struct sockaddr_in serverAddr;
	struct sockaddr_in clientAddr;
	SOCKET serverSocket;
	//CServerObject 

public:
	void Close();
	void SetServiceHandler(CServiceObject *handler);
	int Run();
	static enum UDP_SOCKET_STATE{
		UDP_SOCKET_RECV_TIMEOUT=-0Xff,
		UDP_SOCKET_RECV_FATAL,
		UDP_SOCKET_ERROR_BIND,
		UDP_SOCKET_ERROR_SOCKET
	};
	int Recv(BYTE*buffer, int len,int timeout=1);
	//该函数包含超时控制
	int Send(BYTE*buffer, int len);
	int Bind();
	CUDPServer();
	CUDPServer(unsigned short port);
	CUDPServer(const char* bindIP, unsigned short port);
	virtual ~CUDPServer();

};

#endif // !defined(AFX_UDPSERVER1_H__CC45160A_EEC6_465A_B602_84E005BDDE31__INCLUDED_)
