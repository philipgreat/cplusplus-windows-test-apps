// CommonState.h: interface for the CCommonState class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMMONSTATE_H__B550A08A_D5D5_4C6A_93BC_7C0B183AE4E1__INCLUDED_)
#define AFX_COMMONSTATE_H__B550A08A_D5D5_4C6A_93BC_7C0B183AE4E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <windows.h>
class CCommonState  
{
private:
	CRITICAL_SECTION  safeStateSection;
	int state;
public:
	int GetState();
	void SetState(int st);
	CCommonState();
	virtual ~CCommonState();

};

#endif // !defined(AFX_COMMONSTATE_H__B550A08A_D5D5_4C6A_93BC_7C0B183AE4E1__INCLUDED_)
