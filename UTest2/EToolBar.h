#if !defined(AFX_ETOOLBAR_H__B25D49BD_C7FA_438D_ABDE_1AA61486DC5B__INCLUDED_)
#define AFX_ETOOLBAR_H__B25D49BD_C7FA_438D_ABDE_1AA61486DC5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EToolBar.h : header file
//
#include "EComboBox.h"

/////////////////////////////////////////////////////////////////////////////
// CEToolBar window

class CEToolBar : public CToolBar
{
// Construction
public:
	CEToolBar();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEToolBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	int ClearComboBoxItems();

	int LoadSettings();
	int SaveFilters();
	int GetComboItemCount();
	CString GetTextByIndex(int index);
	CString GetFilText();
	int AddNewCombo(int index,int style);
	virtual ~CEToolBar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CEToolBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnDestroy();
	afx_msg void OnEnable(BOOL bEnable);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
protected:
	CEComboBox		m_wndSnap;
	CFont			m_snapFont;


private:
	int m_iComboIndex;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ETOOLBAR_H__B25D49BD_C7FA_438D_ABDE_1AA61486DC5B__INCLUDED_)
