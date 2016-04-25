// rename.cpp : implementation file
//

#include "stdafx.h"
#include "db.h"
#include "rename.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// rename dialog


rename::rename(CWnd* pParent /*=NULL*/)
	: CDialog(rename::IDD, pParent)
{
	//{{AFX_DATA_INIT(rename)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void rename::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(rename)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(rename, CDialog)
	//{{AFX_MSG_MAP(rename)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// rename message handlers
