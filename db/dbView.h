// dbView.h : interface of the CDbView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBVIEW_H__28EBFF13_E1DD_11D4_93AC_0000E8233645__INCLUDED_)
#define AFX_DBVIEW_H__28EBFF13_E1DD_11D4_93AC_0000E8233645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define WM_MY_MESSAGE (WM_USER+100)
#include "dbdoc.h"
//##ModelId=4095FA7E0186
class CDbView : public CEditView
{
protected: // create from serialization only
	//##ModelId=4095FA7E01A5
	CDbView();
	DECLARE_DYNCREATE(CDbView)

// Attributes
public:
	//##ModelId=4095FA7E01A6
	CDbDoc* GetDocument();
	//##ModelId=4095FA7E01B6
	CFont m_Font;
	//##ModelId=4095FA7E01C6
	CFont m_Font1;
	//##ModelId=4095FA7E01D5
	CFont m_Font2;
	//##ModelId=4095FA7E01F5
	CFont m_Font3;
	//##ModelId=4095FA7E0203
	bool additem ;



// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDbView)
	public:
	//##ModelId=4095FA7E0213
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	//##ModelId=4095FA7E0222
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//##ModelId=4095FA7E0232
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	//##ModelId=4095FA7E0243
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	//##ModelId=4095FA7E0261
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	//##ModelId=4095FA7E0280
	virtual ~CDbView();
#ifdef _DEBUG
	//##ModelId=4095FA7E0282
	virtual void AssertValid() const;
	//##ModelId=4095FA7E0290
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDbView)
	//##ModelId=4095FA7E029F
	afx_msg void OnFileSave();
	//##ModelId=4095FA7E02A1
	afx_msg void OnFileNew();
	//##ModelId=4095FA7E02B0
	afx_msg void OnFileSaveAs();
	//##ModelId=4095FA7E02BF
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//##ModelId=4095FA7E02CE
	afx_msg void OnFileClose();
	//##ModelId=4095FA7E02DE
	afx_msg void OnFilePrintPreview();
	//##ModelId=4095FA7E02E0
	afx_msg void OnAppExit();
	//##ModelId=4095FA7E02EF
	afx_msg void OnMenuitem32782();
	//##ModelId=4095FA7E02FD
	afx_msg void OnButton32783();
	//##ModelId=4095FA7E030D
	afx_msg void OnButton32784();
	//##ModelId=4095FA7E030F
	afx_msg void OnButton32785();
	//##ModelId=4095FA7E031C
	afx_msg void OnMenuitem32781();
	//##ModelId=4095FA7E032C
	afx_msg void OnMenuitem32780();
	//##ModelId=4095FA7E032E
	afx_msg void OnMenuitem32790();
	//##ModelId=4095FA7E033D
	afx_msg void OnMenuitem32791();
	//##ModelId=4095FA7E034B
	afx_msg void OnMenuitem32792();
	//##ModelId=4095FA7E034D
	afx_msg void OnMenuitem32793();
	//##ModelId=4095FA7E035C
	afx_msg void OnSaveMessage();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in dbView.cpp
inline CDbDoc* CDbView::GetDocument()
   { return (CDbDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBVIEW_H__28EBFF13_E1DD_11D4_93AC_0000E8233645__INCLUDED_)
