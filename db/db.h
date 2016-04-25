// db.h : main header file for the DB application
//

#if !defined(AFX_DB_H__28EBFF09_E1DD_11D4_93AC_0000E8233645__INCLUDED_)
#define AFX_DB_H__28EBFF09_E1DD_11D4_93AC_0000E8233645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif
#define UNIQE_APP "{E719E980-D193-11d5-B71A-0000B4C258C7}"

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDbApp:
// See db.cpp for the implementation of this class
//2001-4-17 13:48:57 Edited by Suddy
////2001-4-17 13:48:53 Edited by Suddy
/*
2001-4-17 13:49:01 Edited by Suddy////
*/

//##ModelId=4095FA7E03C8
class CDbApp : public CWinApp
{
public:


	//##ModelId=4095FA7F000F
	CDbApp();
	//##ModelId=4095FA7F0010
	HANDLE  m_hOneInstance;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDbApp)
	public:
	//##ModelId=4095FA7F001F
	virtual BOOL InitInstance();
	//##ModelId=4095FA7F0021
	virtual int ExitInstance();
	//}}AFX_VIRTUAL
	
// Implementation
	//{{AFX_MSG(CDbApp)
	//##ModelId=4095FA7F002F
	afx_msg void OnAppAbout();
	//##ModelId=4095FA7F003E
	afx_msg void OnAppExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DB_H__28EBFF09_E1DD_11D4_93AC_0000E8233645__INCLUDED_)
