// TCPServer.h: interface for the CTCPServer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TCPSERVER_H__03BB3B14_31CD_48D7_8119_24B1B7BC31BB__INCLUDED_)
#define AFX_TCPSERVER_H__03BB3B14_31CD_48D7_8119_24B1B7BC31BB__INCLUDED_

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

#include <stdlib.h>
#include <stdio.h>
#include "ServerContext.h"
#include "CommonTask.h"

class CTCPServer  
{


private:
//	int A:: *p;
	CServerContext serverContext;
	int listenSocket;
	unsigned short port;
public:
	int Run();
	int AcceptConnection(char** ppAddr,
								 unsigned short *pPort);
	CTCPServer();
	CTCPServer(int port);
	virtual ~CTCPServer();

	static  DWORD __stdcall ThreadWork(void *pTask);
	static HANDLE RunTask(CCommonTask *pTask, CCommonContext *pContext);
};

#endif // !defined(AFX_TCPSERVER_H__03BB3B14_31CD_48D7_8119_24B1B7BC31BB__INCLUDED_)
