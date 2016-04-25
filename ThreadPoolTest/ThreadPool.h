// ThreadPool.h: interface for the ThreadPool class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THREADPOOL_H__C9EA5C93_E2DE_4CB6_AC53_DB10D0623B4C__INCLUDED_)
#define AFX_THREADPOOL_H__C9EA5C93_E2DE_4CB6_AC53_DB10D0623B4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include  "Task.h"
#include  "Thread.h"
#include <vector>
using namespace std;
class ThreadPool  
{
private:
	//CThread *pThread;
	vector<Thread *>threadList;
	int minTheadCount;
	int maxThreadCount;
	int initiateThread(int count);
public:
	
	int increaseThreadCoun(int count);
	void runTask(Task *ptask);
	ThreadPool();
	virtual ~ThreadPool();

};

#endif // !defined(AFX_THREADPOOL_H__C9EA5C93_E2DE_4CB6_AC53_DB10D0623B4C__INCLUDED_)
