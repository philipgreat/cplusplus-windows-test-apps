// EPGTest03View.h : interface of the CEPGTest03View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EPGTEST03VIEW_H__146A4733_90B6_416C_81D4_8340ABFFC7D0__INCLUDED_)
#define AFX_EPGTEST03VIEW_H__146A4733_90B6_416C_81D4_8340ABFFC7D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEPGTest03View : public CView
{
protected: // create from serialization only
	CEPGTest03View();
	DECLARE_DYNCREATE(CEPGTest03View)

// Attributes
public:
	CEPGTest03Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEPGTest03View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	void drawActivity(CActivity &p);
	virtual ~CEPGTest03View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEPGTest03View)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in EPGTest03View.cpp
inline CEPGTest03Doc* CEPGTest03View::GetDocument()
   { return (CEPGTest03Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EPGTEST03VIEW_H__146A4733_90B6_416C_81D4_8340ABFFC7D0__INCLUDED_)
