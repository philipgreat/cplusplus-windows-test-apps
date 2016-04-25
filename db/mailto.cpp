// mailto.cpp : implementation file
//

#include "stdafx.h"
#include "db.h"
#include "mailto.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// mailto dialog


mailto::mailto(CWnd* pParent /*=NULL*/)
	: CDialog(mailto::IDD, pParent)
{
	//{{AFX_DATA_INIT(mailto)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void mailto::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(mailto)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(mailto, CDialog)
	//{{AFX_MSG_MAP(mailto)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// mailto message handlers
