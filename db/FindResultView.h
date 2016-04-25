#if !defined(AFX_FINDRESULTVIEW_H__8A31E9C1_FB11_11D4_93D7_0000E8233645__INCLUDED_)
#define AFX_FINDRESULTVIEW_H__8A31E9C1_FB11_11D4_93D7_0000E8233645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FindResultView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFindResultView view
#include "dbview.h"

//##ModelId=4095FA7E00CB
class CFindResultView : public CListView
{
protected:
	//##ModelId=4095FA7E00DA
	CFindResultView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CFindResultView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFindResultView)
	public:
	//##ModelId=4095FA7E00EA
	virtual void OnInitialUpdate();
	protected:
	//##ModelId=4095FA7E00EC
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	//##ModelId=4095FA7E00FB
	virtual ~CFindResultView();
#ifdef _DEBUG
	//##ModelId=4095FA7E0109
	virtual void AssertValid() const;
	//##ModelId=4095FA7E0119
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CFindResultView)
	//##ModelId=4095FA7E011C
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//##ModelId=4095FA7E012A
	afx_msg void OnItemClick(NMHDR* pNMHDR, LRESULT* pResult);
	//##ModelId=4095FA7E0148
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//##ModelId=4095FA7E0157
	afx_msg void OnItemchanged(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINDRESULTVIEW_H__8A31E9C1_FB11_11D4_93D7_0000E8233645__INCLUDED_)
