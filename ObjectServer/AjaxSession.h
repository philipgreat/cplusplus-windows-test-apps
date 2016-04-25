// AjaxSession.h: interface for the CAjaxSession class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AJAXSESSION_H__A9ACA6A6_B4FD_4F37_AD1F_5F29C01B65CF__INCLUDED_)
#define AFX_AJAXSESSION_H__A9ACA6A6_B4FD_4F37_AD1F_5F29C01B65CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CommonTask.h"

class CAjaxSession: public CCommonTask 
{
private:
	char **commandLine;
	BOOL isActive;
	char *nameBuffer;
	char *clientAddr;
	int clientPort;
	int socket;
public:
	BOOL KillProcess(const char *fileName);
	BOOL ReportProcess();
	int ReportMemory();
	int Printf(const char* format, ... );
	int Recv(char *buffer, int length);
	BOOL IsActive();
	char* ToString();
	void SetConnectInfo(char *ip,int port);
	CCommonContext * GetContext();
	int Run();
	int OnEnd();
	int OnStart();
	int SendText(const char* msg);

	CAjaxSession(int sock);
	virtual ~CAjaxSession();

private:
	void Echo(char msg);
	int ReportTime();
	int ExecuteCommand(int argc,char **argv);

};
#endif // !defined(AFX_AJAXSESSION_H__A9ACA6A6_B4FD_4F37_AD1F_5F29C01B65CF__INCLUDED_)
