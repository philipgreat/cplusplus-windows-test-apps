// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "db.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CChildFrame)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_APP_EXIT, OnAppExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildFrame construction/destruction

//##ModelId=4095FA7F005E
CChildFrame::CChildFrame()
{
	// TODO: add member initialization code here
	
}

//##ModelId=4095FA7F007E
CChildFrame::~CChildFrame()
{
}

//##ModelId=4095FA7F005F
BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CChildFrame diagnostics

#ifdef _DEBUG
//##ModelId=4095FA7F0080
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();

}

//##ModelId=4095FA7F008C
void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers

//##ModelId=4095FA7F006F
void CChildFrame::ActivateFrame(int nCmdShow) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CMDIChildWnd::ActivateFrame(SW_SHOWMAXIMIZED);
}

//##ModelId=4095FA7F008F
void CChildFrame::OnFileSave() 
{
	// TODO: Add your command handler code here
	
}

//##ModelId=4095FA7F009D
void CChildFrame::OnAppExit() 
{
	// TODO: Add your command handler code here
	
}
