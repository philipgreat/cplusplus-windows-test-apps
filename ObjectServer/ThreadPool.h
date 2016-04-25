// ThreadPool.h: interface for the CThreadPool class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THREADPOOL_H__7DA99858_99DB_4854_913C_91ACFDFB3C9E__INCLUDED_)
#define AFX_THREADPOOL_H__7DA99858_99DB_4854_913C_91ACFDFB3C9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <windows.h>
#include <list>
#include <algorithm>

using namespace std;

struct THREAD_INFO{
	HANDLE thread;
	HANDLE state;
};

class CThreadPool  
{
private:
	list<HANDLE>threadList;

public:
	CThreadPool(int size);
	virtual ~CThreadPool();

};

#endif // !defined(AFX_THREADPOOL_H__7DA99858_99DB_4854_913C_91ACFDFB3C9E__INCLUDED_)
