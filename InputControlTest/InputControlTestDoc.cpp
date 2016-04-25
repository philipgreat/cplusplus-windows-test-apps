// InputControlTestDoc.cpp : implementation of the CInputControlTestDoc class
//

#include "stdafx.h"
#include "InputControlTest.h"

#include "InputControlTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInputControlTestDoc

IMPLEMENT_DYNCREATE(CInputControlTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CInputControlTestDoc, CDocument)
	//{{AFX_MSG_MAP(CInputControlTestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInputControlTestDoc construction/destruction

CInputControlTestDoc::CInputControlTestDoc()
{
	// TODO: add one-time construction code here

}

CInputControlTestDoc::~CInputControlTestDoc()
{
}

BOOL CInputControlTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CInputControlTestDoc serialization

void CInputControlTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CInputControlTestDoc diagnostics

#ifdef _DEBUG
void CInputControlTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CInputControlTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CInputControlTestDoc commands
