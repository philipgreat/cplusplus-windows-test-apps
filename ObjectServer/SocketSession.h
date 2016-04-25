// SocketSession.h: interface for the CSocketSession class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOCKETSESSION_H__BC60733A_D3EC_46A7_AC2C_C7A64492FBE6__INCLUDED_)
#define AFX_SOCKETSESSION_H__BC60733A_D3EC_46A7_AC2C_C7A64492FBE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CommonTask.h"

class CSocketSession: public CCommonTask 
{
private:
	char **commandLine;
	BOOL isActive;
	char *nameBuffer;
	char *clientAddr;
	int clientPort;
	int socket;
public:
	BOOL IsActive();
	char* ToString();
	void SetConnectInfo(char *ip,int port);
	CCommonContext * GetContext();
	int Run();
	int OnEnd();
	int OnStart();
	int SendText(const char* msg);

	CSocketSession(int sock);
	virtual ~CSocketSession();

private:
	void Echo(char msg);
	int ReportTime();
	int ExecuteCommand(int argc,char **argv);

};

#endif // !defined(AFX_SOCKETSESSION_H__BC60733A_D3EC_46A7_AC2C_C7A64492FBE6__INCLUDED_)
