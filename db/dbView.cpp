// dbView.cpp : implementation of the CDbView class
//

#include "stdafx.h"
#include "db.h"

#include "dbDoc.h"
#include "dbView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDbView

IMPLEMENT_DYNCREATE(CDbView, CEditView)

BEGIN_MESSAGE_MAP(CDbView, CEditView)
	//{{AFX_MSG_MAP(CDbView)
	ON_MESSAGE(WM_MY_MESSAGE,OnSaveMessage)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_WM_CREATE()
	ON_COMMAND(ID_FILE_CLOSE, OnFileClose)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OnFilePrintPreview)
	ON_COMMAND(ID_APP_EXIT, OnAppExit)
	ON_COMMAND(ID_MENUITEM32782, OnMenuitem32782)
	ON_COMMAND(ID_BUTTON32783, OnButton32783)
	ON_COMMAND(ID_BUTTON32784, OnButton32784)
	ON_COMMAND(ID_BUTTON32785, OnButton32785)
	ON_COMMAND(ID_MENUITEM32781, OnMenuitem32781)
	ON_COMMAND(ID_MENUITEM32780, OnMenuitem32780)
	ON_COMMAND(ID_MENUITEM32790, OnMenuitem32790)
	ON_COMMAND(ID_MENUITEM32791, OnMenuitem32791)
	ON_COMMAND(ID_MENUITEM32792, OnMenuitem32792)
	ON_COMMAND(ID_MENUITEM32793, OnMenuitem32793)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDbView construction/destruction

//##ModelId=4095FA7E01A5
CDbView::CDbView()
{
	// TODO: add construction code here
	m_Font.CreatePointFont (90, _T("宋体"));
	m_Font1.CreatePointFont (110, _T("宋体"));
	m_Font2.CreatePointFont (120, _T("宋体"));// TODO: add construction code here
	m_Font3.CreatePointFont (90, _T("宋体"));//
	

}

//##ModelId=4095FA7E0280
CDbView::~CDbView()
{
	m_Font.DeleteObject ();
	m_Font1.DeleteObject ();
	m_Font2.DeleteObject ();
	m_Font3.DeleteObject ();



}

//##ModelId=4095FA7E0222
BOOL CDbView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CEditView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDbView drawing

//##ModelId=4095FA7E0213
void CDbView::OnDraw(CDC* pDC)
{
	CDbDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDbView printing

//##ModelId=4095FA7E0232
BOOL CDbView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

//##ModelId=4095FA7E0243
void CDbView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

//##ModelId=4095FA7E0261
void CDbView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDbView diagnostics

#ifdef _DEBUG
//##ModelId=4095FA7E0282
void CDbView::AssertValid() const
{
	CEditView::AssertValid();
}

//##ModelId=4095FA7E0290
void CDbView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

//##ModelId=4095FA7E01A6
CDbDoc* CDbView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDbDoc)));
	return (CDbDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDbView message handlers

//##ModelId=4095FA7E029F
void CDbView::OnFileSave() 
{
	//	MessageBox("asd");// TODO: Add your command handler code here
	fm *p=(fm*)((CMainFrame *)AfxGetMainWnd())->m_wndWorkspace.GetView (RUNTIME_CLASS(fm));
	look *pl=(look*)((CMainFrame *)AfxGetMainWnd())->m_wndWorkspace.GetView (RUNTIME_CLASS(look));
	
	
	

	if(additem) {
		
		MessageBox("请在搜索引擎中点击增加新内容完成");
		return;
	
	
	}
	if(p->title !=""&&p->type!="")
	{
	
	
	
		CString sql;
		CString content;
		p->m_button_add.GetWindowText (sql);
		if (sql=="增加完成") 
		{	
			//MessageBox("现在不能够更新。因为现在是添加的状态");
			return;
		}else{
		
			
			GetEditCtrl ().GetWindowText (content);
			pl->con.escape_string (content);
			pl->con.escape_string (p->title);
			pl->con.escape_string (p->type );
			//MessageBox(content);
			content.Replace ("\\","\\\\");

			content.Replace ("\'","\\\'");

			//m_button_add.SetWindowText ("增加新内容");
		
		
			sql="update help  set content='"+content+"\'  where title=\'"+p->title+"\' and type=\'"+p->type+"\'";
		

			if(pl->con.mysql_exec(pl->my,sql)!=0)  MessageBox ("执行错误");
			return;
		
		
		}
	
		//m_combo_type.GetWindowText(type);

		//m_text_content.GetWindowText (content);
	//	m_list_title.GetText(m_list_title.GetCurSel (),title);

	
	
	
	
	
	
	}
	





	
}

//##ModelId=4095FA7E02A1
void CDbView::OnFileNew() 
{
	// TODO: Add your command handler code here
	
}

//##ModelId=4095FA7E02B0
void CDbView::OnFileSaveAs() 
{
	// TODO: Add your command handler code here
	
}

//##ModelId=4095FA7E02BF
int CDbView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CEditView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	

	
	
	GetEditCtrl().SetFont(&m_Font);
	GetEditCtrl().SetMargins (20,0);
	//GetEditCtrl().SetWindowPos (
	//m_Font.DeleteObject ();
	
	GetEditCtrl().SetLimitText (10000000);
	//GetEditCtrl().ModifyStyle (
	additem=FALSE;
	//GetEditCtrl().GetMargins (
	//m_brBkgnd
	//GetEditCtrl().CreateSolidCaret 
	//GetEditCtrl().CreateGrayCaret (100,100);
	//::FillRect (GetEditCtrl().GetDC ()->m_hDC ,);
	
	//CBrush brush;
	//brush.CreateSolidBrush (RGB(128,128,128));
	//CRect r(0,0,100,100);
	
	//GetEditCtrl().GetWindowRect (&r);
	
	//r.right =20;

	//GetEditCtrl().GetDC()->FillRect(&r,&brush);
	//GetEditCtrl().GetDC()->SetBkColor (RGB(100,100,100));
	
	return 0;
}

//##ModelId=4095FA7E02CE
void CDbView::OnFileClose() 
{
	// TODO: Add your command handler code here
	
}

//##ModelId=4095FA7E02DE
void CDbView::OnFilePrintPreview() 
{
	// TODO: Add your command handler code here
	
}

//##ModelId=4095FA7E02E0
void CDbView::OnAppExit() 
{
	// TODO: Add your command handler code here
	
}

//##ModelId=4095FA7E035C
void CDbView::OnSaveMessage() 
{
	this->OnFileSave();

	// TODO: Add your command handler code here
	
}
//##ModelId=4095FA7E02EF
void CDbView::OnMenuitem32782() 
{
	
	
	CString s;
	this->GetEditCtrl().GetWindowText (s);
	this->GetEditCtrl().SetSel(0,s.GetLength ());

	// TODO: Add your command handler code here
	
}

//##ModelId=4095FA7E02FD
void CDbView::OnButton32783() 
{
	// TODO: Add your command handler code here
	//m_Font.CreatePointFont (95, _T("宋体"));
	
	
	GetEditCtrl().SetFont(&m_Font2);
	//m_Font.DeleteObject ();

	
}

//##ModelId=4095FA7E030D
void CDbView::OnButton32784() 
{
	// TODO: Add your command handler code here
	
	
	
	GetEditCtrl().SetFont(&m_Font1);
	//m_Font.DeleteObject ();
}

//##ModelId=4095FA7E030F
void CDbView::OnButton32785() 
{
	// TODO: Add your command handler code here
	//m_Font.CreatePointFont (60, _T("宋体"));
	
	GetEditCtrl().SetFont(&m_Font3);
	m_Font.DeleteObject ();
	
}

//##ModelId=4095FA7E031C
void CDbView::OnMenuitem32781() 
{
	// TODO: Add your command handler code here
	
}

//##ModelId=4095FA7E032C
void CDbView::OnMenuitem32780() 
{
	// TODO: Add your command handler code here
	//MessageBox("asd");	
}

//##ModelId=4095FA7E032E
void CDbView::OnMenuitem32790() 
{
	// TODO: Add your command handler code here
	
}

//##ModelId=4095FA7E033D
void CDbView::OnMenuitem32791() 
{
	// TODO: Add your command handler code here
	
}

//##ModelId=4095FA7E034B
void CDbView::OnMenuitem32792() 
{
	// TODO: Add your command handler code here
	
}

//##ModelId=4095FA7E034D
void CDbView::OnMenuitem32793() 
{
	// TODO: Add your command handler code here


	
}
