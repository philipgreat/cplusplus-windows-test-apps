// InputControlTestView.h : interface of the CInputControlTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_INPUTCONTROLTESTVIEW_H__1170EC46_371A_49D9_A0E5_1A41A21F8A88__INCLUDED_)
#define AFX_INPUTCONTROLTESTVIEW_H__1170EC46_371A_49D9_A0E5_1A41A21F8A88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CInputControlTestView : public CView
{
protected: // create from serialization only
	CInputControlTestView();
	DECLARE_DYNCREATE(CInputControlTestView)

// Attributes
public:
	CInputControlTestDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInputControlTestView)
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
	virtual ~CInputControlTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CInputControlTestView)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in InputControlTestView.cpp
inline CInputControlTestDoc* CInputControlTestView::GetDocument()
   { return (CInputControlTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTCONTROLTESTVIEW_H__1170EC46_371A_49D9_A0E5_1A41A21F8A88__INCLUDED_)
