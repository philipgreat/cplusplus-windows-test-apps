// EPGTest03.h : main header file for the EPGTEST03 application
//

#if !defined(AFX_EPGTEST03_H__5E07FA46_719C_4131_9963_FC1A134B71A4__INCLUDED_)
#define AFX_EPGTEST03_H__5E07FA46_719C_4131_9963_FC1A134B71A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEPGTest03App:
// See EPGTest03.cpp for the implementation of this class
//

class CEPGTest03App : public CWinApp
{
public:
	CEPGTest03App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEPGTest03App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEPGTest03App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EPGTEST03_H__5E07FA46_719C_4131_9963_FC1A134B71A4__INCLUDED_)
