#if !defined(AFX_ESTATUSBAR_H__404702AD_53CC_4936_BED0_56DDE2FA8C6E__INCLUDED_)
#define AFX_ESTATUSBAR_H__404702AD_53CC_4936_BED0_56DDE2FA8C6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EStatusBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEStatusBar window

class CEStatusBar : public CStatusBar
{
// Construction
public:
	CEStatusBar();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEStatusBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEStatusBar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CEStatusBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ESTATUSBAR_H__404702AD_53CC_4936_BED0_56DDE2FA8C6E__INCLUDED_)
