#if !defined(AFX_CFONT_COMBO_H__6E64C2A3_E5E7_11D4_93B4_0000E8233645__INCLUDED_)
#define AFX_CFONT_COMBO_H__6E64C2A3_E5E7_11D4_93B4_0000E8233645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// cfont_combo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// cfont_combo window

class cfont_combo : public CComboBox
{
// Construction
public:
	cfont_combo();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(cfont_combo)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~cfont_combo();

	// Generated message map functions
protected:
	//{{AFX_MSG(cfont_combo)
	afx_msg void OnSelchange();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CFONT_COMBO_H__6E64C2A3_E5E7_11D4_93B4_0000E8233645__INCLUDED_)
