// UTest2Doc.h : interface of the CUTest2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UTEST2DOC_H__4489D8C9_E42B_424E_80D4_5088B5D0C2F0__INCLUDED_)
#define AFX_UTEST2DOC_H__4489D8C9_E42B_424E_80D4_5088B5D0C2F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CUTest2Doc : public CDocument
{
protected: // create from serialization only
	CUTest2Doc();
	DECLARE_DYNCREATE(CUTest2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUTest2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUTest2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUTest2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UTEST2DOC_H__4489D8C9_E42B_424E_80D4_5088B5D0C2F0__INCLUDED_)
