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


//##ModelId=4095FA7D0242
class fm : public CFormView
{
protected:
	//##ModelId=4095FA7D0252
	fm();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(fm)

// Form Data
public:
	//{{AFX_DATA(fm)
	enum { IDD = IDD_FORMVIEW };
	//##ModelId=4095FA7D0262
	CButton	m_button_add;
	//##ModelId=4095FA7D0272
	CListBox	m_list_title;
	//##ModelId=4095FA7D0281
	CEdit	m_add_title;
	//##ModelId=4095FA7D02A0
	CEdit	m_text_search;
	//##ModelId=4095FA7D02B0
	CComboBox	m_combo_type;
	

	//}}AFX_DATA

// Attributes
public:
	//##ModelId=4095FA7D02BF
	CString type;
	//##ModelId=4095FA7D02CE
	CString title;
	//##ModelId=4095FA7D02DE
	CString sql;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(fm)
	public:
	//##ModelId=4095FA7D02EE
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	//##ModelId=4095FA7D034B
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//##ModelId=4095FA7D035B
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	//##ModelId=4095FA7D038A
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
protected:
	//##ModelId=4095FA7D0399
	virtual ~fm();
#ifdef _DEBUG
	//##ModelId=4095FA7D039B
	virtual void AssertValid() const;
	//##ModelId=4095FA7D03AA
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
	afx_msg void OnButtonDeleteItem();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FM_H__5A1F8043_E227_11D4_93B0_0000E8233645__INCLUDED_)
