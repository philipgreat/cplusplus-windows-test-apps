// Thread.h: interface for the Thread class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THREAD_H__C98A5840_5ED3_48CE_85DB_EF727B3DC400__INCLUDED_)
#define AFX_THREAD_H__C98A5840_5ED3_48CE_85DB_EF727B3DC400__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "task.h"
#include <windows.h>

class Thread  
{
private:
	Task *currentTask;
	HANDLE threadHandle;
	DWORD threadId;
	int threadState;
public:
	bool canRunNewTask();
	bool isPassived();
	void passive();
	void active(Task *p);
	void wait();
	void end();
	void run();
	void start();
	void SetId(int id);
	Thread();
	virtual ~Thread();

};

#endif // !defined(AFX_THREAD_H__C98A5840_5ED3_48CE_85DB_EF727B3DC400__INCLUDED_)
