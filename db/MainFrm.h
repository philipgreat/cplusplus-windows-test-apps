// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__28EBFF0D_E1DD_11D4_93AC_0000E8233645__INCLUDED_)
#define AFX_MAINFRM_H__28EBFF0D_E1DD_11D4_93AC_0000E8233645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define		TTSWINDDOW	0X10000
#include "cctabctrlbar.h"
#include "look.h"
#include "fm.h"
#include "FindResultView.h"
#include "dbview.h"
#include "FindToolBar.h"
#include "childfrm.h"
#include "SystemTray.h"
#include "texttospeech.h"
#define _TTS		1
//##ModelId=4095FA7C008C
class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	//##ModelId=4095FA7C009D
	CMainFrame();
	//##ModelId=4095FA7C00AB
	LRESULT	OnTrayNotification(WPARAM wParam, LPARAM lParam);

// Attributes
public:
	//##ModelId=4095FA7C00BC
	CCTabCtrlBar	m_wndWorkspace;
	//##ModelId=4095FA7C00CC
	CImageList	m_ImageList;

//	MYSQL *my_connection;
	//##ModelId=4095FA7C00DB
	mysql con;

	//##ModelId=4095FA7C00EA
     BOOL bMaxed;

// Operations
public:
#ifdef	_TTS
	//##ModelId=4095FA7C00FB
	CTextToSpeech m_tts;
#endif


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	//##ModelId=4095FA7C0109
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	//##ModelId=4095FA7C011B
	virtual ~CMainFrame();
#ifdef _DEBUG
	//##ModelId=4095FA7C0129
	virtual void AssertValid() const;
	//##ModelId=4095FA7C0138
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	//##ModelId=4095FA7C0149
	CStatusBar  m_wndStatusBar;
	//##ModelId=4095FA7C0158
	CFindToolBar    m_wndToolBar;
	//##ModelId=4095FA7C0168
	CSystemTray m_TrayIcon;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	//##ModelId=4095FA7C0186
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//##ModelId=4095FA7C0197
	afx_msg void OnMenuitem32773();
	//##ModelId=4095FA7C01A6
	afx_msg void OnUpdateMenuitem32773(CCmdUI* pCmdUI);
	//##ModelId=4095FA7C01C5
	afx_msg void OnToolbarDropDown(NMTOOLBAR* pnmh, LRESULT* plRes);
	//##ModelId=4095FA7C01E4
	afx_msg void OnAppExit();
	//##ModelId=4095FA7C01E6
	afx_msg void OnFindButton();
	//##ModelId=4095FA7C01F5
	afx_msg void OnMenuitemExit();
	//##ModelId=4095FA7C0204
	afx_msg void OnMenuitemShow();
	//##ModelId=4095FA7C0213
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	//##ModelId=4095FA7C0222
	afx_msg void OnMenuitemHide();
	//##ModelId=4095FA7C0232
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//##ModelId=4095FA7C0252
	afx_msg void OnButtonsay();
	//##ModelId=4095FA7C0262
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//##ModelId=4095FA7C0280
	afx_msg void OnButtonWWW();
	//##ModelId=4095FA7C0282
	afx_msg void OnCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__28EBFF0D_E1DD_11D4_93AC_0000E8233645__INCLUDED_)


