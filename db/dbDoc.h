// dbDoc.h : interface of the CDbDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBDOC_H__28EBFF11_E1DD_11D4_93AC_0000E8233645__INCLUDED_)
#define AFX_DBDOC_H__28EBFF11_E1DD_11D4_93AC_0000E8233645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//##ModelId=4095FA7E036B
class CDbDoc : public CDocument
{
protected: // create from serialization only
	//##ModelId=4095FA7E038A
	CDbDoc();
	DECLARE_DYNCREATE(CDbDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDbDoc)
	public:
	//##ModelId=4095FA7E038B
	virtual BOOL OnNewDocument();
	//##ModelId=4095FA7E0399
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:

	//##ModelId=4095FA7E039C
	virtual ~CDbDoc();
#ifdef _DEBUG
	//##ModelId=4095FA7E03AA
	virtual void AssertValid() const;
	//##ModelId=4095FA7E03AC
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDbDoc)
	//##ModelId=4095FA7E03BB
	afx_msg void OnAppExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBDOC_H__28EBFF11_E1DD_11D4_93AC_0000E8233645__INCLUDED_)
