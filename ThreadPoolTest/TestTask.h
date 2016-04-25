// TestTask.h: interface for the TestTask class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTTASK_H__DFBD003B_80C8_42D4_86ED_A05C4BAC1CDD__INCLUDED_)
#define AFX_TESTTASK_H__DFBD003B_80C8_42D4_86ED_A05C4BAC1CDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Task.h"

class TestTask : public Task  
{
private:
	int counter;
public:
	void report();
	void execute();

	TestTask();
	virtual ~TestTask();

};

#endif // !defined(AFX_TESTTASK_H__DFBD003B_80C8_42D4_86ED_A05C4BAC1CDD__INCLUDED_)
