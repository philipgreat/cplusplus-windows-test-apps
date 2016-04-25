#if !defined(AFX_TERAPICOOPTIONDIALOG_H__2AAACA8C_D65E_4A15_85BD_78C759B05D87__INCLUDED_)
#define AFX_TERAPICOOPTIONDIALOG_H__2AAACA8C_D65E_4A15_85BD_78C759B05D87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TerapicoOptionDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTerapicoOptionDialog dialog

class CTerapicoOptionDialog : public CDialog
{
// Construction
public:
	int GetMaxLength();
	CTerapicoOptionDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTerapicoOptionDialog)
	enum { IDD = IDD_TERAPICO_OPTION_DIALOG };
	int	m_lngMaxLengh;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTerapicoOptionDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int ReadConfig();
	int SaveConfig();

	// Generated message map functions
	//{{AFX_MSG(CTerapicoOptionDialog)
	afx_msg void OnChangeEditMaxLengh();
	virtual void OnOK();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TERAPICOOPTIONDIALOG_H__2AAACA8C_D65E_4A15_85BD_78C759B05D87__INCLUDED_)
