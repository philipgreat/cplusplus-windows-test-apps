// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "UTest2.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame


IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
//{{AFX_MSG_MAP(CMainFrame)
ON_WM_CREATE()
ON_COMMAND(ID_EDIT_SELECT_ALL, OnEditSelectAll)
	ON_COMMAND(IDM_EDIT_OPTION, OnEditOption)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(IDC_CLEARCOMBO, OnClearCombo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
		ID_INDICATOR_CAPS,
		ID_INDICATOR_NUM,
		ID_INDICATOR_SCRL,

};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_pdlgOption=new CTerapicoOptionDialog();
	m_pdlgOption->Create(IDD_TERAPICO_OPTION_DIALOG);


}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	
	m_wndToolBar.AddNewCombo (12,0);

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	
	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	m_wndToolBar.LoadSettings();

	
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnEditSelectAll() 
{
	// TODO: Add your command handler code here
	CString s;

	//this->GetActiveView()
	
	
}



CEToolBar* CMainFrame::GetToolBar()
{
	return (&m_wndToolBar);
}

CString CMainFrame::GetToolBarText()
{
	//CString ret="";
	return this->m_wndToolBar.GetFilText ();
}

void CMainFrame::OnEditOption() 
{
	// TODO: Add your command handler code here
	m_pdlgOption->ShowWindow(1);
	int i=m_pdlgOption->m_lngMaxLengh;

	
}

int CMainFrame::GetMaxLogLength()
{
	return m_pdlgOption->m_lngMaxLengh;
}


BOOL CMainFrame::AddToFinderList(CString text)
{
	//this->m_wndToolBar.get
	return TRUE;
}	


void CMainFrame::OnFileSave() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnClearCombo() 
{
	// TODO: Add your command handler code here
	this->m_wndToolBar.ClearComboBoxItems();

}
