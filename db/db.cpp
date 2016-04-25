// db.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "db.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "dbDoc.h"
#include "dbView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDbApp

BEGIN_MESSAGE_MAP(CDbApp, CWinApp)
//{{AFX_MSG_MAP(CDbApp)
ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
ON_COMMAND(ID_APP_EXIT, OnAppExit)
//}}AFX_MSG_MAP
// Standard file based document commands
ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
// Standard print setup command
ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDbApp construction

//##ModelId=4095FA7F000F
CDbApp::CDbApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDbApp object

CDbApp theApp;


/////////////////////////////////////////////////////////////////////////////
// CDbApp initialization

//##ModelId=4095FA7F001F
BOOL CDbApp::InitInstance()
{
	AfxEnableControlContainer();
	


	
	m_hOneInstance=::CreateMutex (NULL,FALSE,UNIQE_APP);
	
	if(GetLastError()==ERROR_ALREADY_EXISTS){
		

		//AfxMessageBox("我发现有一个兄弟正在运行中，所以我将退出",MB_ICONSTOP);

		char title[64]={0};
		CTeraPicoRegKey::GetValue (REG_KEY_PATH,REG_KEY_KEY,title);
		HWND hWnd=FindWindow (NULL,title);

		::ShowWindow(hWnd ,	SW_SHOWMAXIMIZED);
		::SetActiveWindow (hWnd);
		//::EnableWindow(hWnd,TRUE);
		::SetForegroundWindow(hWnd);
		//::SendMessage(hWnd,	WM_SETFOCUS|WM_SHOWWINDOW,NULL,NULL);
		//this->ExitInstance ();		
		//::FindWindow( 
		return FALSE;


	} else{
		
		CTeraPicoRegKey::SetValue (REG_KEY_PATH,REG_KEY_KEY,"db - [Db1]");
	
	}
	
	
	
	
	
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.
	
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	
	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	
	LoadStdProfileSettings();  // Load standard INI file options (including MRU)
	
	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.
	
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_DBTYPE,
		RUNTIME_CLASS(CDbDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CDbView));
	AddDocTemplate(pDocTemplate);
	
	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;
	
	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	
	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	
	// The main window has been initialized, so show and update it.
	//pMainFrame->ShowWindow(m_nCmdShow);
	//pMainFrame->DragAcceptFiles ();
	
	//pMainFrame->ShowWindow(SW_SHOWMAXIMIZED);
	pMainFrame->ShowWindow(SW_HIDE);
	
	//pMainFrame->UpdateWindow();
	
	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

//##ModelId=4095FA8101E4
class CAboutDlg : public CDialog
{
public:
	//##ModelId=4095FA8101F5
	CAboutDlg();
	
	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	//##ModelId=4095FA8101F6
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


//##ModelId=4095FA8101F5
CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

//##ModelId=4095FA8101F6
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
//##ModelId=4095FA7F002F
void CDbApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CDbApp message handlers


//##ModelId=4095FA7F0021
int CDbApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	CloseHandle(m_hOneInstance); 
	
	
	return CWinApp::ExitInstance();
}

//##ModelId=4095FA7F003E
void CDbApp::OnAppExit() 
{
	// TODO: Add your command handler code here
	//ShowWindow(SW_SHOWMAXIMIZED);
	
	//AfxMessageBox("asd");
	
}
