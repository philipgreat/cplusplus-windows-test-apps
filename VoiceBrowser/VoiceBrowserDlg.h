// VoiceBrowserDlg.h : header file
//

#if !defined(AFX_VOICEBROWSERDLG_H__0E1296C2_B8FE_47F8_999D_15C734448207__INCLUDED_)
#define AFX_VOICEBROWSERDLG_H__0E1296C2_B8FE_47F8_999D_15C734448207__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVoiceBrowserDlg dialog

class CVoiceBrowserDlg : public CDialog
{
// Construction
public:
	CVoiceBrowserDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CVoiceBrowserDlg)
	enum { IDD = IDD_VOICEBROWSER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVoiceBrowserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVoiceBrowserDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VOICEBROWSERDLG_H__0E1296C2_B8FE_47F8_999D_15C734448207__INCLUDED_)
