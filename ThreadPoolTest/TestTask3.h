// TestTask3.h: interface for the TestTask3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTTASK3_H__63CC27AF_2457_4297_AD98_873682FAD675__INCLUDED_)
#define AFX_TESTTASK3_H__63CC27AF_2457_4297_AD98_873682FAD675__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Task.h"

class TestTask3 : public Task  
{
public:
	void execute();
	TestTask3();
	virtual ~TestTask3();

};

#endif // !defined(AFX_TESTTASK3_H__63CC27AF_2457_4297_AD98_873682FAD675__INCLUDED_)
