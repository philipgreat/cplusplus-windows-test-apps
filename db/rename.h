#if !defined(AFX_RENAME_H__46BFCE03_E213_11D4_93B0_0000E8233645__INCLUDED_)
#define AFX_RENAME_H__46BFCE03_E213_11D4_93B0_0000E8233645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// rename.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// rename dialog

class rename : public CDialog
{
// Construction
public:
	rename(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(rename)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(rename)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(rename)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RENAME_H__46BFCE03_E213_11D4_93B0_0000E8233645__INCLUDED_)
