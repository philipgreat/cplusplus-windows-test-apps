// ServerContext.cpp: implementation of the CServerContext class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ServerContext.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CServerContext::CServerContext():sessionCount(0)
{
	this->hSyncEvent=::CreateEvent(NULL,TRUE,TRUE,TEXT("context sync"));

}

CServerContext::~CServerContext()
{
	::CloseHandle(this->hSyncEvent);
}

char* CServerContext::GetEnvProperty(const char *name)
{
	return "this is a good server!";
}

CServerContext::AddSession(CCommonTask *pTask)
{
	::WaitForSingleObject(this->hSyncEvent,INFINITE);
	::ResetEvent(this->hSyncEvent);
	this->ClearUnactiveSession();
	this->sessionList.push_back(pTask);
	this->sessionCount++;
	::SetEvent(this->hSyncEvent);

}

int CServerContext::GetSessionCount()
{
	return this->sessionCount;
}



int CServerContext::ClearUnactiveSession()
{
	list<CCommonTask *>::iterator iter;	
	for(iter=sessionList.begin();iter!=sessionList.end();++iter){
		if(!(*iter)->IsActive()){
			delete (*iter);
			printf("clear\n");
		}		
	}
	return 0;
}

BOOL CServerContext::Remove(CCommonTask *task)
{
	WaitForSingleObject(this->hSyncEvent,INFINITE);
	ResetEvent(this->hSyncEvent);
	sessionList.remove(task);
	SetEvent(this->hSyncEvent);

	return TRUE;
}

#ifndef  _WIN32_WCE
#pragma comment(lib,"ws2_32")
#include <Winsock2.h>
#else
#pragma comment(lib,"ws2")
#include <Winsock.h>
#endif
#include <stdlib.h>



static Report2(int socket,CCommonTask * task)
{
	//sprintf(""
	CServerContext::SendText(socket,task->ToString());
	CServerContext::SendText(socket,"\r\n");
}

void CServerContext::Report(int socket)
{
	//for_each(sessionList.begin(),sessionList.end(),Report2);
	list<CCommonTask *>::iterator iter;
	CServerContext::SendText(socket,"all clients:\r\n");
	CServerContext::SendText(socket,"=====================================\r\n");

	for(iter=sessionList.begin();iter!=sessionList.end();iter++)
	{
		Report2(socket,*iter);
	}
	CServerContext::SendText(socket,"=====================================\r\n");

}

int CServerContext::SendText(int socket, const char *text)
{
	return send(socket,text,strlen(text)+1,0);
}

void CServerContext::BroadcastMessage(const char *msg)
{
	list<CCommonTask *>::iterator iter;
	for(iter=sessionList.begin();iter!=sessionList.end();iter++)
	{
		//Report2(socket,*iter);
		(*iter)->SendText(msg);		
	}
}
