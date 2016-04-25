#if !defined(AFX_BROWSE_H__E8319495_E1E8_11D4_93AC_0000E8233645__INCLUDED_)
#define AFX_BROWSE_H__E8319495_E1E8_11D4_93AC_0000E8233645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// browse.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// browse view
#include "afxcview.h"
class browse : public CTreeView
{
protected:
	browse();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(browse)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(browse)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~browse();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(browse)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROWSE_H__E8319495_E1E8_11D4_93AC_0000E8233645__INCLUDED_)
