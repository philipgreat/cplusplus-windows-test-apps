
#if !defined(CCControlBar_H_INCLUDED)
#define CCControlBar_H_INCLUDED

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "CCButton.h"

/////////////////////////////////////////////////////////////////////////////
// CCControlBar class

//##ModelId=4095FA7F0290
class CCControlBar : public CControlBar
{
	DECLARE_DYNAMIC(CCControlBar)

// Construction
public:
	//##ModelId=4095FA7F02A0
	CCControlBar();

	//##ModelId=4095FA7F02AF
	CString		 m_Title;
// Attributes
protected:
	//##ModelId=4095FA7F02BF
	BOOL		 m_bInRecalcNC;
	//##ModelId=4095FA7F02CE
    BOOL         m_bTracking;
	//##ModelId=4095FA7F02DE
	BOOL		 m_bGripper;
	//##ModelId=4095FA7F02EE
	BOOL		 m_bButtons;
	//##ModelId=4095FA7F02FD
    UINT         m_cxEdge;
	//##ModelId=4095FA7F030D
	UINT		 m_menuID;
	//##ModelId=4095FA7F031C
    UINT         m_nDockBarID;
	//##ModelId=4095FA7F033C
    CSize        m_sizeMin;
	//##ModelId=4095FA7F034B
    CSize        m_sizeHorz;
	//##ModelId=4095FA7F035B
    CSize        m_sizeVert;
	//##ModelId=4095FA7F036B
    CSize        m_sizeFloat;
	//##ModelId=4095FA7F037A
    CRect        m_rectBorder;
	//##ModelId=4095FA7F038A
    CRect        m_rectTracker;
	//##ModelId=4095FA7F0399
    CPoint       m_ptOld;
	//##ModelId=4095FA7F03AA
	CCButton	 m_btnClose;
	//##ModelId=4095FA7F03BA
	CCButton     m_btnMinim;
	//##ModelId=4095FA7F03D9
	CImageList*  m_ImageList;
	//##ModelId=4095FA800001
	CToolTipCtrl m_ToolTip;
	

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCControlBar)
	public:
	//##ModelId=4095FA80001F
	virtual void OnUpdateCmdUI(CFrameWnd* pTarget, BOOL bDisableIfNoHndler);
	//##ModelId=4095FA80002E
	virtual BOOL Create(CWnd* pParentWnd, UINT nID, LPCTSTR lpszWindowName = NULL, CSize sizeDefault = CSize(200,200), DWORD dwStyle = WS_CHILD|WS_VISIBLE|CBRS_TOP);
	//##ModelId=4095FA80009C
    virtual CSize CalcFixedLayout( BOOL bStretch, BOOL bHorz );
	//##ModelId=4095FA8000BB
    virtual CSize CalcDynamicLayout( int nLength, DWORD dwMode );
	//##ModelId=4095FA8000DA
	virtual BOOL IsFloating();
	//}}AFX_VIRTUAL
	//##ModelId=4095FA8000EA
	virtual BOOL PreTranslateMessage(MSG* pMsg);

// Implementation
public:
	//##ModelId=4095FA8000FA
	BOOL IsHorzDocked() const;
	//##ModelId=4095FA800109
	BOOL IsVertDocked() const;
	
	//##ModelId=4095FA80010B
	void ShowFrameStuff(BOOL bGripper = TRUE, BOOL bButtons = TRUE) { 
		m_bGripper = bGripper;
		m_bButtons = bButtons;
	}

	//##ModelId=4095FA800128
	void DrawGripper(CDC* pDC);
	//##ModelId=4095FA800138
	CRect GetButtonRect();
	//##ModelId=4095FA800139
	UINT GetMenuID();
	//##ModelId=4095FA800148
	void SetMenuID(UINT nID);
	//##ModelId=4095FA800157
	CImageList* SetBtnImageList(CImageList *pImageList);
	//##ModelId=4095FA800159
	void OnInvertTracker(const CRect& rect);
	//##ModelId=4095FA800168
	void StopTracking(BOOL bAccept);
	//##ModelId=4095FA800178
	void StartTracking();
	//##ModelId=4095FA800186
	CPoint& ClientToWnd(CPoint& point);
	//##ModelId=4095FA800196
	virtual ~CCControlBar();

// Generated message map functions
protected:
	//{{AFX_MSG(CCControlBar)
	//##ModelId=4095FA8001A5
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//##ModelId=4095FA8001B6
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//##ModelId=4095FA8001D5
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//##ModelId=4095FA800203
	afx_msg void OnWindowPosChanged(WINDOWPOS FAR* lpwndpos);
	//##ModelId=4095FA800213
	afx_msg void OnNcPaint();
	//##ModelId=4095FA800222
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	//##ModelId=4095FA800242
	afx_msg UINT OnNcHitTest(CPoint point);
	//##ModelId=4095FA800251
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS FAR* lpncsp);
	//##ModelId=4095FA800271
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//##ModelId=4095FA800290
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	//##ModelId=4095FA80029F
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//##ModelId=4095FA8002BF
	afx_msg void OnPaint();
	//##ModelId=4095FA8002CE
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//##ModelId=4095FA8002DE
	afx_msg void OnButtonClose();
	//##ModelId=4095FA8002EE
	afx_msg void OnUpdateButtonClose(CCmdUI* pCmdUI);
	//##ModelId=4095FA8002FD
	afx_msg void OnButtonMinimize();
	//##ModelId=4095FA80030D
	afx_msg void OnUpdateButtonMinimize(CCmdUI* pCmdUI);
	//##ModelId=4095FA80031C
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(CCControlBar_H_INCLUDED)

