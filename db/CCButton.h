
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
//##ModelId=4095FA8100DA
class CCButton : public CButton
{
	DECLARE_DYNAMIC(CCButton)

// Construction
public:
	//##ModelId=4095FA8100EB
	CCButton();

// Attributes
protected:
	//##ModelId=4095FA8100FA
	CSize       m_cSize;
	//##ModelId=4095FA810109
	CRect		m_rcItem;
	//##ModelId=4095FA810119
	CRect		m_rcIcon;
	//##ModelId=4095FA810128
	UINT		m_nState;
	//##ModelId=4095FA810138
	bool		m_bLBtnDown;
	//##ModelId=4095FA810148
	bool		m_bFlatLook;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCButton)
	public:
	//##ModelId=4095FA810157
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//##ModelId=4095FA810169
	virtual void SetIcon(HICON hIcon,CSize cSize);
	//}}AFX_VIRTUAL

// Implementation
public:
	//##ModelId=4095FA810179
	void DisableFlatLook() { m_bFlatLook = false; }
	//##ModelId=4095FA810186
	void SetIconRect();
	//##ModelId=4095FA810187
	virtual ~CCButton();

// Generated message map functions
protected:
	//{{AFX_MSG(CCButton)
	//##ModelId=4095FA810196
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//##ModelId=4095FA8101A5
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//##ModelId=4095FA8101B6
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//##ModelId=4095FA8101C7
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(CCButton_H_INCLUDED)

