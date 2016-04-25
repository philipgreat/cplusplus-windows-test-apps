// fm.cpp : implementation file
//

#include "stdafx.h"
#include "db.h"
#include "fm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// fm

IMPLEMENT_DYNCREATE(fm, CFormView)

fm::fm()
	: CFormView(fm::IDD)
{
	//{{AFX_DATA_INIT(fm)
	//}}AFX_DATA_INIT
}

fm::~fm()
{
}

void fm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(fm)
	DDX_Control(pDX, IDC_BUTTON5, m_button_add);
	DDX_Control(pDX, IDC_LIST1, m_list_title);
	DDX_Control(pDX, IDC_EDIT2, m_add_title);
	DDX_Control(pDX, IDC_EDIT1, m_text_search);
	DDX_Control(pDX, IDC_COMBO1, m_combo_type);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(fm, CFormView)
	//{{AFX_MSG_MAP(fm)
	ON_BN_CLICKED(IDC_BUTTON1, Onsearch)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangetype)
	ON_WM_CREATE()
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2_sort_time)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5add)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4cancel)
	ON_WM_SHOWWINDOW()
	ON_WM_PAINT()
	ON_COMMAND(ID_APP_EXIT, OnAppExit)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// fm diagnostics

#ifdef _DEBUG
void fm::AssertValid() const
{
	CFormView::AssertValid();
}

void fm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// fm message handlers

void fm::Onsearch() 
{
	look *p=(look*)((CMainFrame *)AfxGetMainWnd())->m_wndWorkspace.GetView (RUNTIME_CLASS(look));

	m_combo_type.GetWindowText (type);

	m_list_title.AddString ("asd");

	while(m_list_title.DeleteString (0)){};

    CString str ;
	m_text_search.GetWindowText (str);

	//clear the content of list control 

	sql="select title from help where type=\'"+type+"\' and title like \'%"+str+"%'";
	if(p->con.mysql_exec(p->my,sql)!=0) 
	{
		MessageBox("服务器可能已经关闭，请重试,如果问题仍然存在,请联系suddy_chang@sina.com");
		return;
	}
	p->rs_dad=p->con.store_result (p->my);

	while((p->row=mysql_fetch_row(p->rs_dad))!=NULL) 
	{
		m_list_title.AddString (p->row[0]);
	}

	p->con.free_result (p->rs_dad);	// TODO: Add your control notification handler code here
	
}

void fm::OnSelchangetype() 
{
	look *p=(look*)((CMainFrame *)AfxGetMainWnd())->m_wndWorkspace.GetView (RUNTIME_CLASS(look));

	m_combo_type.GetWindowText (type);

	m_list_title.AddString ("asd");

	while(m_list_title.DeleteString (0)){};


	//clear the content of list control 

	sql="select title from help where type=\'"+type+"\'";
	if(p->con.mysql_exec(p->my,sql)!=0) 
	{
		MessageBox("服务器可能已经关闭，请重试,如果问题仍然存在,请联系suddy_chang@sina.com");
		
		return;
	}
	p->rs_dad=p->con.store_result (p->my);

	while((p->row=mysql_fetch_row(p->rs_dad))!=NULL) 
	{
	
		m_list_title.AddString (p->row[0]);

	}
	p->con.free_result (p->rs_dad);// TODO: Add your control notification handler code here
	
}

int fm::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;
	

	// TODO: Add your specialized creation code here
	
	return 0;
}

BOOL fm::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void fm::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	
	
	CFormView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}
#include "childfrm.h"
void fm::OnSelchangeList1() 
{
	// TODO: Add your control notification handler code here
		look *p=(look*)((CMainFrame *)AfxGetMainWnd())->m_wndWorkspace.GetView (RUNTIME_CLASS(look));
		
		BOOL bMaximized = FALSE;
		CChildFrame* pActiveWnd = (CChildFrame*)((CMainFrame *)AfxGetMainWnd())->MDIGetActive(&bMaximized);
		CDbView *pActiveView = NULL;
		if (!pActiveWnd) 
		{
			return;
		}
		pActiveView = (CDbView *)pActiveWnd->GetActiveView();

		if (!pActiveView) 
		{
			return;
		}
		
		//pActiveView ->PostMessage(WM_USER+100);

		
		
		m_list_title.GetText(m_list_title.GetCurSel (),title);
		m_combo_type.GetWindowText (type);
		sql="select content from help where type=\'"+type+"\'  and "+"title=\'"+title+"\'";
		if(p->con.mysql_exec(p->my,sql)!=0) 
		{
			//MessageBox("服务器可能已经关闭，请重试,如果问题仍然存在,请联系suddy_chang@sina.com");
			//AfxGetMainWnd()->PostMessage (WM_CLOSE);
			return;
		}
		p->rs_dad=p->con.store_result (p->my);
		//clear the list
		



		 
		if (p->row=mysql_fetch_row(p->rs_dad))
			pActiveView->GetEditCtrl().SetWindowText(p->row[0]);
		p->con.free_result (p->rs_dad);
		p->title =title;
		p->type=type;

		CString title_all;
		title_all="db - ["+type+">>"+title+"]";
		SETTITLE(title_all.GetBuffer(title_all.GetLength ()));
		pActiveView->GetDocument()->SetTitle(type+">>"+title);

	
}

void fm::OnButton2_sort_time() 
{
	// TODO: Add your control notification handler code here

	look *p=(look*)((CMainFrame *)AfxGetMainWnd())->m_wndWorkspace.GetView (RUNTIME_CLASS(look));

	m_combo_type.GetWindowText (type);

	///////////////////////////////////////////////////////

	m_list_title.AddString ("asd");
	while(m_list_title.DeleteString (0)){};
	
	//clear the content of list control 

	sql="select title from help where type=\'"+type+"\' order by time_up desc";
	if(p->con.mysql_exec(p->my,sql)!=0) 
	{
		//MessageBox("服务器可能已经关闭，请重试,如果问题仍然存在,请联系suddy_chang@sina.com");
		return;
	}
	p->rs_dad=p->con.store_result (p->my);

	while((p->row=mysql_fetch_row(p->rs_dad))!=NULL) 
	{
	
		m_list_title.AddString (p->row[0]);

	}
	p->con.free_result (p->rs_dad);
	
}

void fm::OnButton5add() 
{
	CString ca;
	//this record the button capition 

	CString sql;
	//
	CString title_add;
	CString content;
	//
	m_combo_type.GetWindowText(type);
	
	//m_text_content.GetWindowText (content);

	//strcat(d,m_combo_type.GetWindowText ());
	//MessageBox(sql);
	//this ->MessageBox (sql);
	look *p=(look*)((CMainFrame *)AfxGetMainWnd())->m_wndWorkspace.GetView (RUNTIME_CLASS(look));
	BOOL bMaximized = FALSE;
	CChildFrame* pActiveWnd = (CChildFrame*)((CMainFrame *)AfxGetMainWnd())->MDIGetActive(&bMaximized);
	CDbView *pActiveView = NULL;
	if (!pActiveWnd) 
	{
		return;
	}
	pActiveView = (CDbView *)pActiveWnd->GetActiveView();
	
	//Get the point to the two view and do something on i t

	m_button_add.GetWindowText(ca);
	if(ca=="增加新内容")
	{
		m_button_add.SetWindowText ("增加完成");
		m_list_title.EnableWindow (FALSE);
		m_add_title.EnableWindow (TRUE);
		pActiveView->GetEditCtrl ().SetWindowText("");	
		//delete content;
		pActiveView ->additem =TRUE;
		return;
	}else{	
		
		m_add_title.GetWindowText (title_add);
		if(m_list_title.FindString (0,title_add)!=-1)
		{
			AfxMessageBox("不行,请仔细检查你的标题是否正确.或者在原来的标题内添加");
			return ;
		}

		pActiveView->GetEditCtrl ().GetWindowText(content);
		
		m_button_add.SetWindowText ("增加新内容");
		
		p->con.escape_string (title_add);
		p->con.escape_string (content);
		p->con.escape_string (type);
		pActiveView ->additem =FALSE;		
		//title.Replace("\\","\\\\");
		//type.Replace ("\","\\");
		content.Replace ("\\","\\\\");
		content.Replace ("\'","\\\'");

		sql="insert into help values('"+type+"',now(),'"+title_add+"','"+content+"')";
		//MessageBox(sql);

		if (p->con.mysql_exec(p->my,sql)!=0) MessageBox("执行失败!!");

		m_add_title.EnableWindow (FALSE);

		m_list_title.EnableWindow (TRUE);
		p->title =title_add;
		p->type=type;

		CString title_all;
		title_all="db - ["+type+">>"+title+"]";
		SETTITLE(title_all.GetBuffer(title_all.GetLength ()));
		pActiveView->GetDocument ()->SetTitle (type+">>"+title_add);

		OnSelchangetype ();

		return;
	}// end if ca=="xxxxxxx"

// TODO: Add your control notification handler code here
	
}

void fm::OnButton4cancel() 
{
	// TODO: Add your control notification handler code here
	m_list_title.EnableWindow (TRUE);
	BOOL bMaximized = FALSE;
	CChildFrame* pActiveWnd = (CChildFrame*)((CMainFrame *)AfxGetMainWnd())->MDIGetActive(&bMaximized);
	CDbView *pActiveView = NULL;
	if (!pActiveWnd) 
	{
		return;
	}
	pActiveView = (CDbView *)pActiveWnd->GetActiveView();
	
	pActiveView->additem=FALSE;

	
	m_add_title.EnableWindow (FALSE);
	m_button_add.SetWindowText ("增加新内容");
	
}

void fm::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CFormView::OnShowWindow(bShow, nStatus);
	
}

void fm::OnDraw(CDC* pDC) 
{
	// TODO: Add your specialized code here and/or call the base class
	//m_combo_type.SetCurSel (0);
	m_add_title.EnableWindow (FALSE);

	look *p=(look*)((CMainFrame *)AfxGetMainWnd())->m_wndWorkspace.GetView (RUNTIME_CLASS(look));

	m_combo_type.GetWindowText (type);

	m_list_title.AddString ("asd");

	while(m_list_title.DeleteString (0)){};


	//clear the content of list control 

	sql="select title from help where type=\'"+type+"\'";
	if(p->con.mysql_exec(p->my,sql)!=0){
		MessageBox("服务器可能已经关闭，请重试,如果问题仍然存在,请联系suddy_chang@sina.com");
		
		return;
	}
	p->rs_dad=p->con.store_result (p->my);

	while((p->row=mysql_fetch_row(p->rs_dad))!=NULL) {
	
		m_list_title.AddString (p->row[0]);

	}
	p->con.free_result (p->rs_dad);
	
	
}

void fm::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CFormView::OnPaint() for painting messages
}

void fm::OnAppExit() 
{
	// TODO: Add your command handler code here
	
}

void fm::OnButton3() 
{
	look *p=(look*)((CMainFrame *)AfxGetMainWnd())->m_wndWorkspace.GetView (RUNTIME_CLASS(look));

	m_combo_type.GetWindowText (type);

	///////////////////////////////////////////////////////

	m_list_title.AddString ("asd");
	while(m_list_title.DeleteString (0)){};
	
	//clear the content of list control 

	sql="select title from help where type=\'"+type+"\' order by title ";
	if(p->con.mysql_exec(p->my,sql)!=0) {
		//MessageBox("服务器可能已经关闭，请重试,如果问题仍然存在,请联系suddy_chang@sina.com");
		return;
	}
	p->rs_dad=p->con.store_result (p->my);

	while((p->row=mysql_fetch_row(p->rs_dad))!=NULL){
	
		m_list_title.AddString (p->row[0]);

	}
	p->con.free_result (p->rs_dad);
	// TODO: Add your control notification handler code here
	
}
