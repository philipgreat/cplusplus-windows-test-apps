// look.cpp : implementation file
//

#include "stdafx.h"
#include "db.h"
#include "look.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// look

IMPLEMENT_DYNCREATE(look, CTreeView)

//##ModelId=4095FA7C02C0
look::look()
{
}

//##ModelId=4095FA7D0000
look::~look()
{
}


BEGIN_MESSAGE_MAP(look, CTreeView)
	//{{AFX_MSG_MAP(look)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	ON_NOTIFY_REFLECT(TVN_SELCHANGING, OnSelchanging)
	ON_NOTIFY_REFLECT(TVN_SETDISPINFO, OnSetdispinfo)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDED, OnItemexpanded)
	ON_WM_CREATE()
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
	ON_NOTIFY_REFLECT(NM_CLICK, OnClick)
	ON_COMMAND(ID_MENUITEM32777, OnMenuitem32777)
	ON_WM_KILLFOCUS()
	ON_NOTIFY_REFLECT(TVN_ENDLABELEDIT, OnEndlabeledit)
	ON_COMMAND(ID_MENUITEM32774, OnMenuitem32774)
	ON_COMMAND(ID_MENUITEM32775, OnMenuitem32775)
	ON_COMMAND(ID_MENUITEM32776, OnMenuitem32776)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// look drawing

//##ModelId=4095FA7C03CA
void look::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// look diagnostics

#ifdef _DEBUG
//##ModelId=4095FA7D000F
void look::AssertValid() const
{
	CTreeView::AssertValid();
}

//##ModelId=4095FA7D0011
void look::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// look message handlers
#include "childfrm.h"
//##ModelId=4095FA7D002E
void look::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	HTREEITEM s=m_TreeCtrl->GetSelectedItem ();
	HTREEITEM s1=m_TreeCtrl->GetSelectedItem ();
	fm *p=(fm*)((CMainFrame *)AfxGetMainWnd())->m_wndWorkspace.GetView (RUNTIME_CLASS(fm));
	CString str;
	CString str0;
	CString sql;




	//we willl save something before we lost it
////////////////////////////////////////////////////////////////////////////////
		BOOL bMaximized = FALSE;
		CChildFrame* pActiveWnd = (CChildFrame*)((CMainFrame *)AfxGetMainWnd())->MDIGetActive(&bMaximized);
		CDbView *pActiveView = NULL;
		if (!pActiveWnd) 
		{
			return;
		}
		pActiveView = (CDbView *)pActiveWnd->GetActiveView();

		//pActiveView ->SendMessage(WM_USER+100);

////////////////////////////////////////////////////////////////



	int i=0;

	str=m_TreeCtrl->GetItemText(s);
	CStatusBar *m=(CStatusBar *)((CMainFrame *)AfxGetMainWnd())->GetDescendantWindow (AFX_IDW_STATUS_BAR);
	while ((s=m_TreeCtrl->GetParentItem (s))!=NULL)
	{
		str0=m_TreeCtrl->GetItemText(s);
		
		i=i+1;
		//TRACE1("%d",i);


	}
	//TRACE1("%d",i);

	if(i)
	{
		sql=sql="select content from help where type=\'"+str0+"\'  and "+"title=\'"+str+"\'";
		if(con.mysql_exec(my,sql)!=0) 
		{
			//MessageBox("服务器可能已经关闭，请重试,如果问题仍然存在,请联系suddy_chang@sina.com");
			//AfxGetMainWnd()->PostMessage (WM_CLOSE);
			return;
		}
		rs_dad=con.store_result (my);
	//clear the list
		
		 
		if (row=mysql_fetch_row(rs_dad))
			pActiveView->GetEditCtrl().SetWindowText(row[0]);
		con.free_result (rs_dad);
	

		CString title_all;
		title_all="db - ["+str0+">>"+str+"]";
		SETTITLE(title_all.GetBuffer(title_all.GetLength ()));
		//(CMainFrame *)AfxGetMainWnd())->GetActiveWindow
		pActiveView->GetDocument()->SetTitle(str0+">>"+str);
		p->title=str;
		p->type=str0;



		
		
	
	
	}
	m->SetPaneText (0,str);

	*pResult = 0;
}

//##ModelId=4095FA7D005D
void look::OnSelchanging(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

//##ModelId=4095FA7D007D
void look::OnSetdispinfo(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	TRACE("ASD");


	*pResult = 0;
}

//##ModelId=4095FA7D00AB
void look::OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here

	SetRedraw();

	
	*pResult = 0;
}
#include <direct.h>
//##ModelId=4095FA7D00CB
int look::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_TreeCtrl = &GetTreeCtrl();
	m_TreeCtrl->ModifyStyle (0, WS_VISIBLE | TVS_HASBUTTONS|TVS_HASLINES|TVS_LINESATROOT);

	m_Font.CreatePointFont (95, _T("宋体"));
    m_TreeCtrl->SetFont (&m_Font);

	m_ImageList.Create(16, 16, true, 2, 1);
	HICON hIcon;
	
	
	hIcon= AfxGetApp()->LoadIcon (IDI_ICON2);
	m_ImageList.Add (hIcon);
	hIcon= AfxGetApp()->LoadIcon (IDI_ICON3);
	m_ImageList.Add (hIcon);

	m_TreeCtrl->SetImageList( &m_ImageList, TVSIL_NORMAL );
	


	//m_ini.
	
	char buffer[_MAX_PATH]; 
	char *pchToolHome=::getenv("TOOL_HOME");
	
	if(pchToolHome!=NULL){
		strcpy(buffer,pchToolHome);
		m_ini.file_path =strcat(buffer,"\\config.ini");
		

		
	}

	//my=(CMainFrame *)AfxGetMainfrm()->;
#define SUDDY
//	my=my_connection;
//	char *
#ifdef PEARL
	
	my=con.connect ("192.168.0.10", "root","3123", "caixia", 0, "csi04", 0 );
#endif	//my=con.connect ("192.168.0.10", "root","3123", "wangyu", 0, "csi04", 0 );
#ifdef SUDDY


	my=con.connect (
		m_ini.getvalue ("mysql","host"),
		m_ini.getvalue ("mysql","user"),
		m_ini.getvalue ("mysql","password"), 
		m_ini.getvalue ("mysql","database"),
		0,
		"csi04", 
		0 );

#endif

	if (my==NULL) 
	{
	
		MessageBox("连接失败!\r\n请和管理员Suddy_chang@sina.com 联系,\r\nPlease Contact to Adimistrator Suddy_chang@sina.com");
		AfxGetMainWnd()->PostMessage (WM_CLOSE);
		return FALSE;
	}

	CString sql;
	sql="select distinct type from help order by type";
	//MessageBox(sql);

	if(con.mysql_exec(my,sql)!=0) 
	{
		char *s=(char *)malloc(1024);
		
		
		sprintf(s,"发生错误：%s",con.error(my));
		//s=con.error(my);

		MessageBox(s);
		free(s);
		return 0;
	}
	rs_dad=con.store_result (my);
	while((row=mysql_fetch_row(rs_dad))!=NULL) 

	{
		
		dad=m_TreeCtrl->InsertItem (row[0],1,0);
		sql="select title from help where type=\'"+(CString)row[0]+"\'";

	//MessageBox(sql);

		if(con.mysql_exec(my,sql)!=0) 
		{
		//MessageBox("服务器可能已经关闭，请重试,如果问题仍然存在,请联系suddy_chang@sina.com");
		
			return 0;
		}
		
		rs_son=con.store_result (my);
		while((row_son=mysql_fetch_row(rs_son))!=NULL)
		{
		
			m_TreeCtrl->InsertItem (row_son[0],1,0,dad);
		
		
		}
		con.free_result (rs_son);

		
	}
	con.free_result (rs_dad);
	
	return 0;
}

//##ModelId=4095FA7D00FA
void look::OnRclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	    CMenu menu;            // top-level menu 
		CMenu *pMenu=NULL;  // pop-up menu 

		menu.LoadMenu(IDR_MENU2); 
		pMenu = menu.GetSubMenu(0);
		if (!pMenu)
			return ;

		POINT pt;
		GetCursorPos(&pt);
		pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, pt.x, pt.y, this, NULL); 
		menu.DestroyMenu(); 
	*pResult = 0;
}

//##ModelId=4095FA7D0119
void look::OnClick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

}

//##ModelId=4095FA7D0139
void look::OnMenuitem32777() 
{
	// TODO: Add your command handler code here
	
	//m_TreeCtrl->GetEditControl ()->SetModify();
	//CRect ClientRect;
    //GetClientRect (&ClientRect);
	//m_TreeCtrl->GetEditControl ()->Create (ES_LEFT,ClientRect,this,10011);
	//m_TreeCtrl->
	m_TreeCtrl->EditLabel(m_TreeCtrl->GetSelectedItem ());

	//rm.DoModel();

		//MessageBox("ad");

}

//##ModelId=4095FA7D0149
void look::OnKillFocus(CWnd* pNewWnd) 
{
	CTreeView::OnKillFocus(pNewWnd);
	
	//MessageBox(m_TreeCtrl->GetItemText (m_TreeCtrl->GetSelectedItem ()));

	// TODO: Add your message handler code here
	
}

//##ModelId=4095FA7D0167
void look::OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	CString s;
	m_TreeCtrl->GetEditControl ()->GetWindowText (s);

	m_TreeCtrl->SetItemText (m_TreeCtrl->GetSelectedItem (),s);

	*pResult = 0;
}

//##ModelId=4095FA7D0186
void look::OnMenuitem32774() 
{
	// TODO: Add your command handler code here

	HTREEITEM s=m_TreeCtrl->GetParentItem (m_TreeCtrl->GetSelectedItem ());
	
	s=m_TreeCtrl->InsertItem ("新建兄弟项",1,0,s);
	m_TreeCtrl->SelectItem (s);
	m_TreeCtrl->EditLabel (s);
}

//##ModelId=4095FA7D0196
void look::OnMenuitem32775() 
{
	HTREEITEM s=m_TreeCtrl->GetSelectedItem ();
	s=m_TreeCtrl->InsertItem ("新建子项",1,0,s);
	//InsertItem ("新建子项",1,0,s);
	
	m_TreeCtrl->SelectItem (s);
	m_TreeCtrl->EditLabel (s);

}

//##ModelId=4095FA7D0198
void look::OnMenuitem32776() 
{
	HTREEITEM s=m_TreeCtrl->GetSelectedItem ();
	
	//m_TreeCtrl->DeleteItem(s);// TODO: Add your command handler code here
	
}

//##ModelId=4095FA7D01A6
BOOL look::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	
	return CTreeView::OnEraseBkgnd(pDC);
}
