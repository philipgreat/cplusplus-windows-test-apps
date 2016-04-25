// cfont_combo.cpp : implementation file
//

#include "stdafx.h"
#include "db.h"
#include "cfont_combo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// cfont_combo

cfont_combo::cfont_combo()
{
}

cfont_combo::~cfont_combo()
{
}


BEGIN_MESSAGE_MAP(cfont_combo, CComboBox)
	//{{AFX_MSG_MAP(cfont_combo)
	ON_CONTROL_REFLECT(CBN_SELCHANGE, OnSelchange)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// cfont_combo message handlers
#include "childfrm.h"
void cfont_combo::OnSelchange() 
{
	// TODO: Add your control notification handler code here
	
		BOOL bMaximized = FALSE;
		CChildFrame* pActiveWnd = (CChildFrame*)((CMainFrame *)AfxGetMainWnd())->MDIGetActive(&bMaximized);
		CDbView *pActiveView = NULL;
		if (!pActiveWnd) 
		{
			return;
		}
		pActiveView = (CDbView *)pActiveWnd->GetActiveView();	
	

}

int cfont_combo::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CComboBox::OnCreate(lpCreateStruct) == -1)
		return -1;
	

	// TODO: Add your specialized creation code here
	
	return 0;
}
