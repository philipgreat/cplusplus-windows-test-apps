
#if !defined(CJTABCTRLBAR_H_INCLUDED)
#define CJTABCTRLBAR_H_INCLUDED

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <afxtempl.h>
#include "CCControlBar.h"
//#include "mapx.h"
//#include "test.h"
#include "dbview.h"


//##ModelId=4095FA7F00AC
typedef struct
{
	CWnd *pWnd;
	char szLabel[32];
}TCB_ITEM;

/////////////////////////////////////////////////////////////////////////////
// CCTabCtrlBar tab control bar

//##ModelId=4095FA7F00DA
class CCTabCtrlBar : public CCControlBar
{
// Construction
public:
	//##ModelId=4095FA7F00EA
	CCTabCtrlBar();

// Attributes
public:
	//##ModelId=4095FA7F00FB
	CTabCtrl m_tabctrl;
	//##ModelId=4095FA7F010A
	CToolTipCtrl* m_ToolTip;
//	CMapX	 m_ctrlMapX;

protected:
	//##ModelId=4095FA7F0119
	int m_nActiveTab;
	//##ModelId=4095FA7F0129
	CView* m_pActiveView;	
	//##ModelId=4095FA7F0139
	CList <TCB_ITEM *,TCB_ITEM *> m_views;
	

// Operations
public:
	//##ModelId=4095FA7F0157
	void SetActiveView(int nNewTab);
	//##ModelId=4095FA7F0167
	void SetActiveView(CRuntimeClass *pViewClass);
	//##ModelId=4095FA7F0177
	CImageList* SetTabImageList(CImageList *pImageList);
	//##ModelId=4095FA7F0186
	BOOL ModifyTabStyle(DWORD dwRemove, DWORD dwAdd, UINT nFlags);

// Overrides
public:
    // ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCTabCtrlBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	//##ModelId=4095FA7F01A5
	CView* GetActiveView();
	//##ModelId=4095FA7F01A6
	CView* GetView(int nView);
	//##ModelId=4095FA7F01B5
	CView* GetView(CRuntimeClass *pViewClass);
	//##ModelId=4095FA7F01C5
	BOOL AddView(LPCTSTR lpszLabel, CRuntimeClass *pViewClass, CCreateContext *pContext = NULL);
	//##ModelId=4095FA7F01E4
	void RemoveView(int nView);
	//##ModelId=4095FA7F01F4
	virtual ~CCTabCtrlBar();

// Generated message map functions
protected:
	//{{AFX_MSG(CCTabCtrlBar)
	//##ModelId=4095FA7F01F6
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//##ModelId=4095FA7F0205
	afx_msg void OnTabSelChange(NMHDR* pNMHDR, LRESULT* pResult) ;
	//##ModelId=4095FA7F0223
	afx_msg void OnWindowPosChanged(WINDOWPOS FAR* lpwndpos);
	//}}AFX_MSG
	//void OnMouseDownMap(short FAR* Button, short FAR* Shift, float FAR* X, float FAR* Y);
	
	DECLARE_MESSAGE_MAP()
	DECLARE_EVENTSINK_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // CJTABCTRLBAR_H_INCLUDED
