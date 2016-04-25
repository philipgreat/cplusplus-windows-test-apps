// browse.cpp : implementation file
//

#include "stdafx.h"
#include "db.h"
#include "browse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// browse

IMPLEMENT_DYNCREATE(browse, CTreeView)

browse::browse()
{
}

browse::~browse()
{
}


BEGIN_MESSAGE_MAP(browse, CTreeView)
	//{{AFX_MSG_MAP(browse)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// browse drawing

void browse::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// browse diagnostics

#ifdef _DEBUG
void browse::AssertValid() const
{
	CTreeView::AssertValid();
}

void browse::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// browse message handlers
