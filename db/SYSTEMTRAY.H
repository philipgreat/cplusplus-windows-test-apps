/////////////////////////////////////////////////////////////////////////////
// SystemTray.h : header file
//
// Written by Chris Maunder (Chris.Maunder@cbr.clw.csiro.au)
// Copyright (c) 1998.
//
// This code may be used in compiled form in any way you desire. This
// file may be redistributed unmodified by any means PROVIDING it is 
// not sold for profit without the authors written consent, and 
// providing that this notice and the authors name is included. If 
// the source code in  this file is used in any commercial application 
// then acknowledgement must be made to the author of this file 
// (in whatever form you wish).
//
// This file is provided "as is" with no expressed or implied warranty.
//
// Expect bugs.
// 
// Please use and enjoy. Please let me know of any bugs/mods/improvements 
// that you have found/implemented and I will fix/incorporate them into this
// file. 

#ifndef _INCLUDED_SYSTEMTRAY_H_
#define _INCLUDED_SYSTEMTRAY_H_

#include <afxtempl.h>
#include <afxdisp.h>    // COleDateTime

/////////////////////////////////////////////////////////////////////////////
// CSystemTray window

//##ModelId=4095FA7B0148
class CSystemTray : public CWnd
{
// Construction/destruction
public:
	//##ModelId=4095FA7B0158
    CSystemTray();
	//##ModelId=4095FA7B0167
    CSystemTray(CWnd* pWnd, UINT uCallbackMessage, LPCTSTR szTip, HICON icon, UINT uID);
	//##ModelId=4095FA7B0186
    virtual ~CSystemTray();

    DECLARE_DYNAMIC(CSystemTray)

// Operations
public:
	//##ModelId=4095FA7B0188
    BOOL Enabled() { return m_bEnabled; }
	//##ModelId=4095FA7B0189
    BOOL Visible() { return !m_bHidden; }

    // Create the tray icon
	//##ModelId=4095FA7B0196
    Create(CWnd* pParent, UINT uCallbackMessage, LPCTSTR szTip, HICON icon, UINT uID);

    // Change or retrieve the Tooltip text
	//##ModelId=4095FA7B01B5
    BOOL    SetTooltipText(LPCTSTR pszTooltipText);
	//##ModelId=4095FA7B01B7
    BOOL    SetTooltipText(UINT nID);
	//##ModelId=4095FA7B01C6
    CString GetTooltipText() const;

    // Change or retrieve the icon displayed
	//##ModelId=4095FA7B01D4
    BOOL  SetIcon(HICON hIcon);
	//##ModelId=4095FA7B01E4
    BOOL  SetIcon(LPCTSTR lpszIconName);
	//##ModelId=4095FA7B01E6
    BOOL  SetIcon(UINT nIDResource);
	//##ModelId=4095FA7B01F5
    BOOL  SetStandardIcon(LPCTSTR lpIconName);
	//##ModelId=4095FA7B0203
    BOOL  SetStandardIcon(UINT nIDResource);
	//##ModelId=4095FA7B0205
    HICON GetIcon() const;
	//##ModelId=4095FA7B0214
    void  HideIcon();
	//##ModelId=4095FA7B0215
    void  ShowIcon();
	//##ModelId=4095FA7B0222
    void  RemoveIcon();
	//##ModelId=4095FA7B0223
    void  MoveToRight();

    // For icon animation
	//##ModelId=4095FA7B0232
    BOOL  SetIconList(UINT uFirstIconID, UINT uLastIconID); 
	//##ModelId=4095FA7B0243
    BOOL  SetIconList(HICON* pHIconList, UINT nNumIcons); 
	//##ModelId=4095FA7B0252
    BOOL  Animate(UINT nDelayMilliSeconds, int nNumSeconds = -1);
	//##ModelId=4095FA7B0263
    BOOL  StepAnimation();
	//##ModelId=4095FA7B0271
    BOOL  StopAnimation();

    // Change menu default item
	//##ModelId=4095FA7B0272
    void GetMenuDefaultItem(UINT& uItem, BOOL& bByPos);
	//##ModelId=4095FA7B0281
    BOOL SetMenuDefaultItem(UINT uItem, BOOL bByPos);

    // Change or retrieve the window to send notification messages to
	//##ModelId=4095FA7B0291
    BOOL  SetNotificationWnd(CWnd* pNotifyWnd);
	//##ModelId=4095FA7B029F
    CWnd* GetNotificationWnd() const;

    // Default handler for tray notification message
	//##ModelId=4095FA7B02A1
    virtual LRESULT OnTrayNotification(WPARAM uID, LPARAM lEvent);

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CSystemTray)
	protected:
	//##ModelId=4095FA7B02B2
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	//##ModelId=4095FA7B02CF
    void Initialise();

	//##ModelId=4095FA7B02DE
    BOOL            m_bEnabled;   // does O/S support tray icon?
	//##ModelId=4095FA7B035B
    BOOL            m_bHidden;    // Has the icon been hidden?
	//##ModelId=4095FA7B038B
    NOTIFYICONDATA  m_tnd;

	//##ModelId=4095FA7B0399
    CArray<HICON, HICON> m_IconList;
	//##ModelId=4095FA7B03A9
    static UINT  m_nIDEvent;
	//##ModelId=4095FA7B03B9
    UINT         m_uIDTimer;
	//##ModelId=4095FA7B03C8
    int          m_nCurrentIcon;
	//##ModelId=4095FA7B03D9
    COleDateTime m_StartTime;
	//##ModelId=4095FA7C000F
    int          m_nAnimationPeriod;
	//##ModelId=4095FA7C001F
    HICON        m_hSavedIcon;
	//##ModelId=4095FA7C002E
    UINT         m_DefaultMenuItemID;
	//##ModelId=4095FA7C003E
    BOOL         m_DefaultMenuItemByPos;

// Generated message map functions
protected:
	//{{AFX_MSG(CSystemTray)
	//##ModelId=4095FA7C005D
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG

    DECLARE_MESSAGE_MAP()
};


#endif

/////////////////////////////////////////////////////////////////////////////
