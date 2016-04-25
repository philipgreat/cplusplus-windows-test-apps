#if !defined(AFX_FM_H__5A1F8043_E227_11D4_93B0_0000E8233645__INCLUDED_)
#define AFX_FM_H__5A1F8043_E227_11D4_93B0_0000E8233645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// fm.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// fm form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
#define IDD_FORMVIEW 101


class fm : public CFormView
{
protected:
	fm();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(fm)

// Form Data
public:
	//{{AFX_DATA(fm)
	enum { IDD = IDD_FORMVIEW };
	CButton	m_button_add;
	CListBox	m_list_title;
	CEdit	m_add_title;
	CEdit	m_text_search;
	CComboBox	m_combo_type;
	

	//}}AFX_DATA

// Attributes
public:
	CString type;
	CString title;
	CString sql;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(fm)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~fm();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(fm)
	afx_msg void Onsearch();
	afx_msg void OnSelchangetype();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSelchangeList1();
	afx_msg void OnButton2_sort_time();
	afx_msg void OnButton5add();
	afx_msg void OnButton4cancel();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnPaint();
	afx_msg void OnAppExit();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FM_H__5A1F8043_E227_11D4_93B0_0000E8233645__INCLUDED_)
