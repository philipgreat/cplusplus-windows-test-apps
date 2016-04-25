// ThreadPool.cpp: implementation of the ThreadPool class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ThreadPool.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ThreadPool::ThreadPool()
{
	minTheadCount = 5;
	maxThreadCount = 10;
	this->initiateThread(this->minTheadCount);
	//not run when create it
	//return hThread;
}

ThreadPool::~ThreadPool()
{

}

void ThreadPool::runTask(Task *ptask)
{
	//select a thread to active
	//printf("task %u planned to run\n",ptask);
	//this->pThread->active(ptask);
	Thread *p=NULL;
	vector<Thread *>::iterator iter;	
	bool isAssinged = false;
	for(iter=threadList.begin();iter!=threadList.end();++iter){
		p=(*iter);
		if(p->canRunNewTask()){
			p->active(ptask);
			isAssinged = true;
			break;
		}
	}
	if(!isAssinged){
		printf("task is not assigned to a thread\n");
	}
}

int ThreadPool::increaseThreadCoun(int count)
{
	return initiateThread(count);
}

int ThreadPool::initiateThread(int count)
{
	for(int i=0;i<count;i++)
	{
		Thread *pThread=new Thread();
		this->threadList.push_back(pThread);
	}
	return 0;
}
