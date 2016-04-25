#if !defined(AFX_FINDTOOLBAR_H__E4F9BF11_F8CC_11D4_93D3_0000E8233645__INCLUDED_)
#define AFX_FINDTOOLBAR_H__E4F9BF11_F8CC_11D4_93D3_0000E8233645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FindToolBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFindToolBar window

//##ModelId=4095FA7E007D
class CFindToolBar : public CToolBar
{
// Construction
public:
	//##ModelId=4095FA7E008C
	CFindToolBar();

// Attributes
	//##ModelId=4095FA7E008E
	CComboBox m_wndsnap;
public:


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFindToolBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	//##ModelId=4095FA7E00BB
	virtual ~CFindToolBar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFindToolBar)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINDTOOLBAR_H__E4F9BF11_F8CC_11D4_93D3_0000E8233645__INCLUDED_)
