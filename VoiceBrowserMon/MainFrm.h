// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__4F3139DF_A108_4A76_80AD_8153A4CA7807__INCLUDED_)
#define AFX_MAINFRM_H__4F3139DF_A108_4A76_80AD_8153A4CA7807__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "EToolbar.h"
#include "Estatusbar.h"
#include "TerapicoOptionDialog.h"
class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)
	CTerapicoOptionDialog *m_pdlgOption;

// Attributes
public:
	
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:

	BOOL AddToFinderList(CString text);

	int GetMaxLogLength();
	CString GetToolBarText();
	CEToolBar* GetToolBar();
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CEStatusBar  m_wndStatusBar;
	CEToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnEditSelectAll();
	afx_msg void OnEditOption();
	afx_msg void OnFileSave();
	afx_msg void OnClearCombo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__4F3139DF_A108_4A76_80AD_8153A4CA7807__INCLUDED_)
