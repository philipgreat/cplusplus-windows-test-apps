// ChildFrm.h : interface of the CChildFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDFRM_H__28EBFF0F_E1DD_11D4_93AC_0000E8233645__INCLUDED_)
#define AFX_CHILDFRM_H__28EBFF0F_E1DD_11D4_93AC_0000E8233645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/*2001-4-17 13:50:26 Edited by Suddy
*/

//##ModelId=4095FA7F004E
class CChildFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	//##ModelId=4095FA7F005E
	CChildFrame();

/*2001-4-17 13:50:31 Edited by Suddy
// Attributes
*/
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildFrame)
	public:
	//##ModelId=4095FA7F005F
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//##ModelId=4095FA7F006F
	virtual void ActivateFrame(int nCmdShow = -1);
	//}}AFX_VIRTUAL

// Implementation
public:
	//##ModelId=4095FA7F007E
	virtual ~CChildFrame();
#ifdef _DEBUG
	//##ModelId=4095FA7F0080
	virtual void AssertValid() const;
	//##ModelId=4095FA7F008C
	virtual void Dump(CDumpContext& dc) const;
#endif

// Generated message map functions
protected:
	//{{AFX_MSG(CChildFrame)
	//##ModelId=4095FA7F008F
	afx_msg void OnFileSave();
	//##ModelId=4095FA7F009D
	afx_msg void OnAppExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDFRM_H__28EBFF0F_E1DD_11D4_93AC_0000E8233645__INCLUDED_)
