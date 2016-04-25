// ThreadedTask.h: interface for the CThreadedTask class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THREADEDTASK_H__25BAE466_2489_413E_94F4_C356DDE556CA__INCLUDED_)
#define AFX_THREADEDTASK_H__25BAE466_2489_413E_94F4_C356DDE556CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Task
{

public:
	virtual void report() = 0;
	virtual void execute() = 0;
	Task();
	virtual ~Task();

};

#endif // !defined(AFX_THREADEDTASK_H__25BAE466_2489_413E_94F4_C356DDE556CA__INCLUDED_)
