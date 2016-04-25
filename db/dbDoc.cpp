// dbDoc.cpp : implementation of the CDbDoc class
//

#include "stdafx.h"
#include "db.h"

#include "dbDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDbDoc

IMPLEMENT_DYNCREATE(CDbDoc, CDocument)

BEGIN_MESSAGE_MAP(CDbDoc, CDocument)
	//{{AFX_MSG_MAP(CDbDoc)
	ON_COMMAND(ID_APP_EXIT, OnAppExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDbDoc construction/destruction

//##ModelId=4095FA7E038A
CDbDoc::CDbDoc()
{
	// TODO: add one-time construction code here

}

//##ModelId=4095FA7E039C
CDbDoc::~CDbDoc()
{
}

//##ModelId=4095FA7E038B
BOOL CDbDoc::OnNewDocument()
{


	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDbDoc serialization

//##ModelId=4095FA7E0399
void CDbDoc::Serialize(CArchive& ar)
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
// CDbDoc diagnostics

#ifdef _DEBUG
//##ModelId=4095FA7E03AA
void CDbDoc::AssertValid() const
{
	
	CDocument::AssertValid();
}

//##ModelId=4095FA7E03AC
void CDbDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDbDoc commands

//##ModelId=4095FA7E03BB
void CDbDoc::OnAppExit() 
{
	// TODO: Add your command handler code here

	
}

