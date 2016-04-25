// EStatusBar.cpp : implementation file
//

#include "stdafx.h"
#include "UTest2.h"
#include "EStatusBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEStatusBar

CEStatusBar::CEStatusBar()
{
}

CEStatusBar::~CEStatusBar()
{
}


BEGIN_MESSAGE_MAP(CEStatusBar, CStatusBar)
	//{{AFX_MSG_MAP(CEStatusBar)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEStatusBar message handlers

int CEStatusBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CStatusBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}
