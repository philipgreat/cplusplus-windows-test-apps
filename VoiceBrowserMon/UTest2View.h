// UTest2View.h : interface of the CUTest2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UTEST2VIEW_H__EAAE8729_3CB2_440F_89F9_24CC0093B9F2__INCLUDED_)
#define AFX_UTEST2VIEW_H__EAAE8729_3CB2_440F_89F9_24CC0093B9F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "DebugUDP.h"


class CUTest2View : public CEditView
{
protected: // create from serialization only
	CUTest2View();
	DECLARE_DYNCREATE(CUTest2View)

// Attributes
public:
	CUTest2Doc* GetDocument();
	CFont 	m_Font;
	CDebugUDP m_sockSend;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUTest2View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUTest2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUTest2View)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnEditSelectAll();
	afx_msg void OnFileSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in UTest2View.cpp
inline CUTest2Doc* CUTest2View::GetDocument()
   { return (CUTest2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UTEST2VIEW_H__EAAE8729_3CB2_440F_89F9_24CC0093B9F2__INCLUDED_)
