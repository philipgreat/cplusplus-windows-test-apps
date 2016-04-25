#if !defined(AFX_ECOMBOBOX_H__DDCFD212_3B5B_4C1D_867B_EDF3EC9705D1__INCLUDED_)
#define AFX_ECOMBOBOX_H__DDCFD212_3B5B_4C1D_867B_EDF3EC9705D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EComboBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEComboBox window

class CEComboBox : public CComboBox
{
// Construction
public:
	CEComboBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEComboBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEComboBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CEComboBox)
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnEditchange();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ECOMBOBOX_H__DDCFD212_3B5B_4C1D_867B_EDF3EC9705D1__INCLUDED_)
