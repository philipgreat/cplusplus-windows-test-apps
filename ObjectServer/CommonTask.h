// CommonTask.h: interface for the CCommonTask class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMMONTASK_H__491FC0AA_1F8D_4AED_BC5C_B251544B03DB__INCLUDED_)
#define AFX_COMMONTASK_H__491FC0AA_1F8D_4AED_BC5C_B251544B03DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <windows.h>
#include "CommonContext.h"

class CCommonTask  
{
protected:

	CCommonContext *m_pContext;
public:
	virtual int SendText(const char*message) =0 ;
	virtual char * ToString() = 0;
	virtual int SetContext(CCommonContext *pContext);
	virtual BOOL IsActive() = 0;
	virtual int OnStart() = 0;
	virtual int Run() = 0;
	virtual int OnEnd() = 0;

	//virtual int OnSleep()=0;
	CCommonTask();
	virtual ~CCommonTask();

};




#endif // !defined(AFX_COMMONTASK_H__491FC0AA_1F8D_4AED_BC5C_B251544B03DB__INCLUDED_)
