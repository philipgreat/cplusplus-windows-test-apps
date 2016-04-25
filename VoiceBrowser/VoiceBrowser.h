// VoiceBrowser.h : main header file for the VOICEBROWSER application
//

#if !defined(AFX_VOICEBROWSER_H__91E86172_ABA1_4D87_8D5B_55546DCD8EA1__INCLUDED_)
#define AFX_VOICEBROWSER_H__91E86172_ABA1_4D87_8D5B_55546DCD8EA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVoiceBrowserApp:
// See VoiceBrowser.cpp for the implementation of this class
//

class CVoiceBrowserApp : public CWinApp
{
public:
	CVoiceBrowserApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVoiceBrowserApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVoiceBrowserApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VOICEBROWSER_H__91E86172_ABA1_4D87_8D5B_55546DCD8EA1__INCLUDED_)
