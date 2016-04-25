// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "db.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define	WM_ICON_NOTIFY			WM_USER+10
/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_MENUITEM32773, OnMenuitem32773)
	ON_UPDATE_COMMAND_UI(ID_MENUITEM32773, OnUpdateMenuitem32773)
	ON_NOTIFY(TBN_DROPDOWN, AFX_IDW_TOOLBAR, OnToolbarDropDown)
	ON_COMMAND(ID_APP_EXIT, OnAppExit)
	ON_COMMAND(IDC_FIND_BUTTON, OnFindButton)
	ON_COMMAND(ID_MENUITEM32797, OnMenuitemExit)
	ON_COMMAND(ID_MENUITEM32796, OnMenuitemShow)
	ON_WM_GETMINMAXINFO()
	ON_COMMAND(ID_MENUITEM32798, OnMenuitemHide)
	ON_WM_SIZE()
	ON_COMMAND(ID_BUTTONSAY, OnButtonsay)
	ON_COMMAND(ID_BUTTON32800, OnButtonWWW)
	ON_MESSAGE(WM_ICON_NOTIFY, OnTrayNotification)
	ON_COMMAND(IDC_COMBO1, OnCombo1)
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

//##ModelId=4095FA7C009D
CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

//##ModelId=4095FA7C011B
CMainFrame::~CMainFrame()
{
}

//##ModelId=4095FA7C0186
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

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
	//m_wndToolBar.SetButtonInfo (1,IDR_MENU1,TBSTYLE_DROPDOWN,1);
	//m_wndToolBar.SetButtonInfo(1, IDR_MENU1,TBBS_BUTTON, 1);
	//
	CRect rc(0,0,10,10);
#ifdef	_TTS1
	if(!m_tts.Create(NULL,WS_VISIBLE ,rc,this,TTSWINDDOW,NULL)){
	
		MessageBox("FAIL TO CTEATE TTS OBJECT");

	
	}

	m_tts.SetSpeed(160);
	m_tts.Gender(4);

#endif
	
	//THIS CREATE A TTS WINDOW THAT  I CAN USE THE VOICE 
	//FUNCITONS

	
	

	m_wndToolBar.SetButtonStyle(1,IDR_MENU1|TBSTYLE_DROPDOWN);

	m_ImageList.Create(IDB_IMAGELIST, 13, 1, RGB(0,255,0));
	



	m_wndWorkspace.SetBtnImageList (&m_ImageList);

	////////////////////////////////////////////
	//toolbar process
	int index=0;
	CRect rect;
	while(m_wndToolBar.GetItemID (index)!=IDC_COMBO1)
		index++;
	m_wndToolBar.SetButtonInfo (index,IDC_COMBO1,TBBS_SEPARATOR,400);
	
	
	m_wndToolBar.GetItemRect (index,&rect);
	rect.bottom +=300;

	if(!m_wndToolBar.m_wndsnap .Create (WS_CHILD|WS_VISIBLE|CBS_AUTOHSCROLL|
		CBS_DROPDOWN|CBS_HASSTRINGS,rect,&m_wndToolBar,IDC_COMBO1))
		{
	
	       TRACE0("FAIL TO CREATE IT!");

	
	
		}

	m_wndToolBar.m_wndsnap .ShowWindow (SW_SHOW);


	//m_wndWorkspace.SetMenuID(IDR_MENU1);
	if (!m_wndWorkspace.Create(this, 100,
		_T("导航器"), CSize(200,260)))
	{
		TRACE0("Failed to create dialog bar m_wndWorkspace\n");
		return -1;		// fail to create
	}
	//	m_wndWorkspace.AddView(_T("装置/罐区"),RUNTIME_CLASS(CPotDevice));
	m_wndWorkspace.AddView(_T("导航器"), RUNTIME_CLASS(look));
	m_wndWorkspace.AddView(_T("搜索引擎"), RUNTIME_CLASS(fm));
	m_wndWorkspace.AddView(_T("查找结果"), RUNTIME_CLASS(CFindResultView));
	

	//m_wndWorkspace.AddView(_T("事故预案"),RUNTIME_CLASS(CCounterPlan));

    m_wndWorkspace.SetBarStyle(m_wndWorkspace.GetBarStyle() |
	    CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	m_wndWorkspace.EnableDocking(CBRS_ALIGN_ANY);


	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndWorkspace, AFX_IDW_DOCKBAR_LEFT);


	if (!m_TrayIcon.Create(this, WM_ICON_NOTIFY, "", AfxGetApp()->LoadIcon(IDR_DBTYPE), IDR_MENU3))
		return -1;

	//m_TrayIcon.MoveToRight();
	bMaxed=FALSE;


	return 0;
}

//##ModelId=4095FA7C0109
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
//##ModelId=4095FA7C0129
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

//##ModelId=4095FA7C0138
void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


//##ModelId=4095FA7C0197
void CMainFrame::OnMenuitem32773() 
{
	BOOL bVisible=((m_wndWorkspace.GetStyle() & WS_VISIBLE) != 0);
	ShowControlBar(&m_wndWorkspace, !bVisible, FALSE);
	RecalcLayout();// TODO: Add your command handler code here
	
}

//##ModelId=4095FA7C01A6
void CMainFrame::OnUpdateMenuitem32773(CCmdUI* pCmdUI) 
{
		// TODO: Add your command update UI handler code here
	BOOL bVisible=((m_wndWorkspace.GetStyle() & WS_VISIBLE) != 0);
	pCmdUI->SetCheck(bVisible);
	
}
//##ModelId=4095FA7C01C5
void CMainFrame::OnToolbarDropDown(NMTOOLBAR* pnmtb, LRESULT *plr)
{
	CWnd *pWnd;
//	UINT nID;

	
	
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu* pPopup = menu.GetSubMenu(0);
	//ASSERT(pPopup);
	pWnd = &m_wndToolBar;
	CRect rc;
	pWnd->SendMessage(TB_GETRECT, pnmtb->iItem, (LPARAM)&rc);
	
	pWnd->ClientToScreen(&rc);
	
	pPopup->TrackPopupMenu( TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_VERTICAL,
		rc.left, rc.bottom, this, &rc);
}

//##ModelId=4095FA7C01E4
void CMainFrame::OnAppExit() 
{
	// TODO: Add your command handler code here
	
	MessageBox("asd");

	ShowWindow(SW_SHOWMAXIMIZED);

	AfxGetMainWnd()->PostMessage (WM_CLOSE);
}

//##ModelId=4095FA7C01E6
void CMainFrame::OnFindButton() 
{
	// TODO: Add your command handler code here
	
	BOOL bMaximized = FALSE;
	CChildFrame* pActiveWnd = (CChildFrame*)((CMainFrame *)AfxGetMainWnd())->MDIGetActive(&bMaximized);
	CDbView *pActiveView = NULL;
	if (!pActiveWnd) 
	{
			return;
	}
	pActiveView = (CDbView *)pActiveWnd->GetActiveView();
	CString *s=new CString ();
	CFindResultView *pResult=(CFindResultView *)m_wndWorkspace.GetView (RUNTIME_CLASS(CFindResultView));
	char *strLine=new char[300];

	CString content;
	pResult->GetListCtrl ().DeleteAllItems ();


	//AfxMessageBox("asd");

	m_wndToolBar.m_wndsnap.GetWindowText (*s);
	

	
	if(s->GetLength ()!=0&&m_wndToolBar.m_wndsnap.FindString (0,*s)==-1)
	{
		
		m_wndToolBar.m_wndsnap.AddString (*s);
	}
	for (int i=0;i<pActiveView->GetEditCtrl ().GetLineCount ();i++)
	{
	
		
		int count=pActiveView->GetEditCtrl ().GetLine (i,strLine,300);
		*(strLine+count)='\0';

		content.Format ("%s",strLine);
		if(content.Find(*s)!=-1){
		    
			CString s_number;
			s_number.Format ("%6d",i+1);

			pResult->GetListCtrl ().InsertItem(0,s_number);

			pResult->GetListCtrl ().SetItemText (0,1,content);


			//pResult->GetListCtrl ().InsertItem (

		
		}
	
	}


	delete strLine;

	delete s;

	
}



//##ModelId=4095FA7C00AB
LRESULT CMainFrame::OnTrayNotification(WPARAM wParam, LPARAM lParam)
{

    return m_TrayIcon.OnTrayNotification(wParam, lParam);
}

//##ModelId=4095FA7C01F5
void CMainFrame::OnMenuitemExit() 
{
	// TODO: Add your command handler code here
	AfxGetMainWnd()->PostMessage (WM_CLOSE);
}

//##ModelId=4095FA7C0204
void CMainFrame::OnMenuitemShow() 
{
	// TODO: Add your command handler code here

	ShowWindow(SW_SHOWMAXIMIZED);		
}

//##ModelId=4095FA7C0213
void CMainFrame::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI) 
{
	// TODO: Add your message handler code here and/or call default
	//if(bMaxed) ShowWindow(SW_HIDE),bMaxed=FALSE;

	//else  bMaxed=TRUE;
	//TRACE("ASDAD");


	//ShowWindow(SW_HIDE);

	CFrameWnd::OnGetMinMaxInfo(lpMMI);
}

//##ModelId=4095FA7C0222
void CMainFrame::OnMenuitemHide() 
{
	// TODO: Add your command handler code here
	ShowWindow(SW_HIDE);
}

//##ModelId=4095FA7C0232
void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{

	TRACE1("%d\n",nType);
	if(nType==1)  this->ShowWindow (SW_HIDE);
	else this->ShowWindow (SW_SHOW);

	CMDIFrameWnd::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	
}

//##ModelId=4095FA7C0252
void CMainFrame::OnButtonsay() 
{
	// TODO: Add your command handler code here
	//m_tts.Speak("I love you");
	///////////////////
#ifdef	_TTS
	BOOL bMaximized = FALSE;
	CChildFrame* pActiveWnd = (CChildFrame*)((CMainFrame *)AfxGetMainWnd())->MDIGetActive(&bMaximized);
	CDbView *pActiveView = NULL;
	if (!pActiveWnd){
		return;
	}
	pActiveView = (CDbView *)pActiveWnd->GetActiveView();
	
	CString  strSay;
	//while(1){
	//
	//	pActiveView->GetSelectedText(strTmp);
	//	if(strTmp=="") break;

	//	strSay+=strTmp;
	//}
	//pActiveView->GetSelectedText(strSay);
	
	int start=0 ,end=0;

	pActiveView->GetEditCtrl().GetSel(start,end);

	pActiveView->GetEditCtrl().GetWindowText (strSay);

	strSay=strSay.Mid(start,end-start);
	//strSay.Replace ("\r\n"," ");
	//strSay.Replace ("\n\r"," ");
	//m_tts.StopSpeaking();
	//MessageBox(strSay);
	//pActiveView->GetSelectedText(strSay);
	//strSay.Replace ("\r\n"," ");
	//strSay.Replace ("\n\r"," ");
	//m_tts.StopSpeaking();
	//MessageBox(strSay);
	
    //m_tts.Speak("\Pit=128\Spd=250\Vol=1200\welcom to fullstrong.yeah.net !"); 
	m_tts.Speak((LPCSTR)strSay);
#endif
	///////////////////


}

#include <afxinet.h>
DWORD dwHttpRequestFlags =
	INTERNET_FLAG_EXISTING_CONNECT | INTERNET_FLAG_NO_AUTO_REDIRECT;
//##ModelId=4095FA7C0280
void CMainFrame::OnButtonWWW() 
{
	// TODO: Add your command handler code here
	BOOL bMaximized = FALSE;
	CChildFrame* pActiveWnd = (CChildFrame*)((CMainFrame *)AfxGetMainWnd())->MDIGetActive(&bMaximized);
	CDbView *pActiveView = NULL;
	if (!pActiveWnd) 
	{
			return;
	}
	pActiveView = (CDbView *)pActiveWnd->GetActiveView();
	CString *s=new CString ();
	CFindResultView *pResult=(CFindResultView *)m_wndWorkspace.GetView (RUNTIME_CLASS(CFindResultView));
	char *strLine=new char[300];
	
	CString content;
	



	pResult->GetListCtrl ().DeleteAllItems ();


	//AfxMessageBox("asd");

	m_wndToolBar.m_wndsnap.GetWindowText (*s);
	
	
	
	if(s->GetLength ()!=0&&m_wndToolBar.m_wndsnap.FindString (0,*s)==-1)
	{
		
		m_wndToolBar.m_wndsnap.AddString (*s);
	}

	
	
	CString pszURL = "http://suddy/";
	m_wndToolBar.m_wndsnap.GetWindowText(pszURL);

	CHttpConnection* pServer = NULL;
	CInternetSession	session;
	CHttpFile* pFile = NULL;
	try
	{
		// check to see if this is a reasonable URL

		CString strServerName;
		CString strObject;
		INTERNET_PORT nPort;
		DWORD dwServiceType;
	
		

		if (!AfxParseURL(pszURL, dwServiceType, strServerName, strObject, nPort) ||
			dwServiceType != INTERNET_SERVICE_HTTP)
		{
			//ThrowTearException(1);
		}
		pServer = session.GetHttpConnection(strServerName, nPort);

		pFile = pServer->OpenRequest(CHttpConnection::HTTP_VERB_GET,
			strObject, NULL, 1, NULL, NULL, dwHttpRequestFlags);
		//pFile->AddRequestHeaders(szHeaders);
		pFile->SendRequest();

		DWORD dwRet;
		pFile->QueryInfoStatusCode(dwRet);

		// if access was denied, prompt the user for the password

		if (dwRet == HTTP_STATUS_DENIED)
		{
			DWORD dwPrompt;
			dwPrompt = pFile->ErrorDlg(NULL, ERROR_INTERNET_INCORRECT_PASSWORD,
				FLAGS_ERROR_UI_FLAGS_GENERATE_DATA | FLAGS_ERROR_UI_FLAGS_CHANGE_OPTIONS, NULL);

			// if the user cancelled the dialog, bail out

			if (dwPrompt != ERROR_INTERNET_FORCE_RETRY)
			{
				//ThrowTearException(1);
			}

			pFile->SendRequest();
			pFile->QueryInfoStatusCode(dwRet);
		}

		CString strNewLocation;
		pFile->QueryInfo(HTTP_QUERY_RAW_HEADERS_CRLF, strNewLocation);
		//MessageBox(strNewLocation);

	

		TCHAR sz[1024];
		CString ls,ns("asdasda");
		int i=0;

		while (pFile->ReadString(sz, 1023))
		{
			ls=ls+CString(sz);
		}

		//ls.Replace("\r","\\r");
		ls.Replace("\n","\r\n");

		//ls.Replace("\r","\n");
		
		ls="<!--\r\n"+strNewLocation+"-->\r\n"+ls;


		pActiveView->GetEditCtrl ().SetWindowText(ls);


	}catch (CInternetException* pEx){
		// catch errors from WinINet

		TCHAR szErr[1024];
		pEx->GetErrorMessage(szErr, 1024);

		//cerr << _T("Error: (") << pEx->m_dwError << _T(") ");
		//cerr << szErr << endl;
		//MessageBox(pEx->m_dwError);

		//nRetCode = 2;
		pEx->Delete();
	}

	if (pFile != NULL)
		delete pFile;
	if (pServer != NULL)
		delete pServer;

	delete strLine;

	delete s;

}

//##ModelId=4095FA7C0282
void CMainFrame::OnCombo1() 
{
	// TODO: Add your command handler code here
	
}
