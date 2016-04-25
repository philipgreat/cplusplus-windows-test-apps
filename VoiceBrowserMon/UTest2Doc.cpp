// UTest2Doc.cpp : implementation of the CUTest2Doc class
//

#include "stdafx.h"
#include "UTest2.h"

#include "UTest2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUTest2Doc

IMPLEMENT_DYNCREATE(CUTest2Doc, CDocument)

BEGIN_MESSAGE_MAP(CUTest2Doc, CDocument)
	//{{AFX_MSG_MAP(CUTest2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUTest2Doc construction/destruction

CUTest2Doc::CUTest2Doc()
{
	// TODO: add one-time construction code here

}

CUTest2Doc::~CUTest2Doc()
{
}

BOOL CUTest2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	((CEditView*)m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CUTest2Doc serialization

void CUTest2Doc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CUTest2Doc diagnostics

#ifdef _DEBUG
void CUTest2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CUTest2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUTest2Doc commands
