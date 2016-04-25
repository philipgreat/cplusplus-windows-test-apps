// InputControlTestDoc.h : interface of the CInputControlTestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_INPUTCONTROLTESTDOC_H__CFB99C56_B347_4C56_B7DE_C9C0B4993B1A__INCLUDED_)
#define AFX_INPUTCONTROLTESTDOC_H__CFB99C56_B347_4C56_B7DE_C9C0B4993B1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CInputControlTestDoc : public CDocument
{
protected: // create from serialization only
	CInputControlTestDoc();
	DECLARE_DYNCREATE(CInputControlTestDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInputControlTestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CInputControlTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CInputControlTestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTCONTROLTESTDOC_H__CFB99C56_B347_4C56_B7DE_C9C0B4993B1A__INCLUDED_)
