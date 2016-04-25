#if !defined(AFX_LOOK_H__0F513841_E1F5_11D4_93B0_0000E8233645__INCLUDED_)
#define AFX_LOOK_H__0F513841_E1F5_11D4_93B0_0000E8233645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// look.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// look view
#include "mysql.h"
#include "inifile.h"
//##ModelId=4095FA7C02AF
class look : public CTreeView
{
protected:
	//##ModelId=4095FA7C02C0
	look();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(look)

// Attributes
public:

// Operations
public:
	
	//##ModelId=4095FA7C02CF
	CFont m_Font;
	//##ModelId=4095FA7C02DF
	CImageList	m_ImageList;
	//##ModelId=4095FA7C02FE
	CTreeCtrl*	m_TreeCtrl;
	//##ModelId=4095FA7C030D
	HTREEITEM dad;
	//##ModelId=4095FA7C030E
	HTREEITEM son;
	//##ModelId=4095FA7C031C
	CString title;
	//##ModelId=4095FA7C032C
	CString type;
	//##ModelId=4095FA7C034B
	CString content;
	//##ModelId=4095FA7C035C
	mysql con;
	//##ModelId=4095FA7C036C
	MYSQL *my;
	//##ModelId=4095FA7C037B
	MYSQL_RES	*rs_son ;
	//##ModelId=4095FA7C038B
	MYSQL_RES	*rs_dad ;
	//##ModelId=4095FA7C039A
	inifile			m_ini;
	//##ModelId=4095FA7C03AA
	MYSQL_ROW row;
	//##ModelId=4095FA7C03BA
	MYSQL_ROW row_son;


//	rename rm;


	//HTREEITEM m_htParentPots;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(look)
	protected:
	//##ModelId=4095FA7C03CA
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	//##ModelId=4095FA7D0000
	virtual ~look();
#ifdef _DEBUG
	//##ModelId=4095FA7D000F
	virtual void AssertValid() const;
	//##ModelId=4095FA7D0011
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(look)
	//##ModelId=4095FA7D002E
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	//##ModelId=4095FA7D005D
	afx_msg void OnSelchanging(NMHDR* pNMHDR, LRESULT* pResult);
	//##ModelId=4095FA7D007D
	afx_msg void OnSetdispinfo(NMHDR* pNMHDR, LRESULT* pResult);
	//##ModelId=4095FA7D00AB
	afx_msg void OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult);
	//##ModelId=4095FA7D00CB
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//##ModelId=4095FA7D00FA
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	//##ModelId=4095FA7D0119
	afx_msg void OnClick(NMHDR* pNMHDR, LRESULT* pResult);
	//##ModelId=4095FA7D0139
	afx_msg void OnMenuitem32777();
	//##ModelId=4095FA7D0149
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	//##ModelId=4095FA7D0167
	afx_msg void OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
	//##ModelId=4095FA7D0186
	afx_msg void OnMenuitem32774();
	//##ModelId=4095FA7D0196
	afx_msg void OnMenuitem32775();
	//##ModelId=4095FA7D0198
	afx_msg void OnMenuitem32776();
	//##ModelId=4095FA7D01A6
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOOK_H__0F513841_E1F5_11D4_93B0_0000E8233645__INCLUDED_)
