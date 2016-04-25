// ServerContext.h: interface for the CServerContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERVERCONTEXT_H__6772803E_DA46_4447_B1BD_A171B7F7E279__INCLUDED_)
#define AFX_SERVERCONTEXT_H__6772803E_DA46_4447_B1BD_A171B7F7E279__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#pragma warning(disable: 4530)
#pragma warning(disable: 4786)

#include "CommonContext.h"
#include "CommonTask.h"
#include <windows.h>
#include <list>
#include <algorithm>

using namespace std;

class CServerContext : public CCommonContext  
{

private:

	list<CCommonTask *> sessionList;


#ifdef WIN32
	HANDLE hSyncEvent;
#endif

	int sessionCount;
public:
	void BroadcastMessage(const char* msg);
	static int  SendText(int socket, const char *text);
	void Report(int socket);
	BOOL Remove(CCommonTask* task);
	int ClearUnactiveSession();
	void ResetList();
	int GetSessionCount();
	AddSession(CCommonTask *pTask);
	char* GetEnvProperty(const char *name);
	CServerContext();
	virtual ~CServerContext();

};

#endif // !defined(AFX_SERVERCONTEXT_H__6772803E_DA46_4447_B1BD_A171B7F7E279__INCLUDED_)
