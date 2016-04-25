
#if !defined(CCButton_H_INCLUDED)
#define CCButton_H_INCLUDED

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
//2001-4-17 13:49:45 Edited by Suddy
//wer
/////////////////////////////////////////////////////////////////////////////
/*2001-4-17 13:49:35 Edited by Suddy// CCButton class
*/
/*2001-4-17 13:49:52 Edited by Suddywerw
*/
class CCButton : public CButton
{
	DECLARE_DYNAMIC(CCButton)

// Construction
public:
	CCButton();

// Attributes
protected:
	CSize       m_cSize;
	CRect		m_rcItem;
	CRect		m_rcIcon;
	UINT		m_nState;
	bool		m_bLBtnDown;
	bool		m_bFlatLook;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void SetIcon(HICON hIcon,CSize cSize);
	//}}AFX_VIRTUAL

// Implementation
public:
	void DisableFlatLook() { m_bFlatLook = false; }
	void SetIconRect();
	virtual ~CCButton();

// Generated message map functions
protected:
	//{{AFX_MSG(CCButton)
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(CCButton_H_INCLUDED)

