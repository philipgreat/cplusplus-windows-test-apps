// UTest2.h : main header file for the UTEST2 application
//

#if !defined(AFX_UTEST2_H__BAD2A98A_0FE3_4AFF_AE05_06681103024C__INCLUDED_)
#define AFX_UTEST2_H__BAD2A98A_0FE3_4AFF_AE05_06681103024C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CUTest2App:
// See UTest2.cpp for the implementation of this class
//

class CUTest2App : public CWinApp
{
public:
	CUTest2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUTest2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CUTest2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UTEST2_H__BAD2A98A_0FE3_4AFF_AE05_06681103024C__INCLUDED_)
