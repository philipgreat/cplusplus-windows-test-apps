// EPGTest03View.cpp : implementation of the CEPGTest03View class
//

#include "stdafx.h"
#include "EPGTest03.h"

#include "EPGTest03Doc.h"
#include "EPGTest03View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "RemoteLogger.h"
static CRemoteLogger logger;
/////////////////////////////////////////////////////////////////////////////
// CEPGTest03View

IMPLEMENT_DYNCREATE(CEPGTest03View, CView)

BEGIN_MESSAGE_MAP(CEPGTest03View, CView)
	//{{AFX_MSG_MAP(CEPGTest03View)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEPGTest03View construction/destruction

CEPGTest03View::CEPGTest03View()
{
	// TODO: add construction code here

}

CEPGTest03View::~CEPGTest03View()
{
}

BOOL CEPGTest03View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEPGTest03View drawing

void CEPGTest03View::OnDraw(CDC* pDC)
{
	CEPGTest03Doc* pDoc = GetDocument();
	CActivity *p=pDoc->getCurrentActivity();
	
	drawActivity(*p);

	//logger.Log("draw");
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEPGTest03View diagnostics

#ifdef _DEBUG
void CEPGTest03View::AssertValid() const
{
	CView::AssertValid();
}

void CEPGTest03View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEPGTest03Doc* CEPGTest03View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEPGTest03Doc)));
	return (CEPGTest03Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEPGTest03View message handlers

void CEPGTest03View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default

	char c=(char)nChar;
	char message[10];
	message[0]=c;
	message[1]=0;

	string event(message);
	logger.Log(event.c_str());
	
	//event.append(c);
	CActivity *p=NULL;
	try{
		p=GetDocument()->procEvent(event);	
	}catch(CElementNotFoundException &e){
		logger.Log(e.getMessage());
	}catch(...){
		logger.Log("more exception");		
	}
	if(p!=NULL){
		drawActivity(*p);
		//this->SendMessage(WM_PAINT);
	
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CEPGTest03View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default

	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CEPGTest03View::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	CEPGTest03Doc* pDoc = GetDocument();
	CActivity *p=pDoc->getCurrentActivity();
	drawActivity(*p);

	// TODO: Add your message handler code here
	
	// Do not call CView::OnPaint() for painting messages
}

void CEPGTest03View::drawActivity(CActivity &p)
{
	CClientDC dc(this);
	CFont font;
	LOGFONT lf; //LOGFONT结构中的变量用于定义字体的各种特性
	memset(&lf,0,sizeof(lf));
	lf.lfCharSet = GB2312_CHARSET; //设置字符集
	lf.lfHeight = 16;
	
	//dc.SetBkColor(RGB(0,100,0));
	dc.SetBkMode(TRANSPARENT);
	strcpy(lf.lfFaceName,"宋体"); //设置字体名称 MingLiu为MS提供的BIG5字体
	font.CreateFontIndirect(&lf); //创建字体
	CFont* pF = (CFont*)dc.SelectObject(&font); //保存当前字体
	p.draw(dc,60,20,600,400);
	dc.SelectObject(pF); //恢复以前的字体
	

}	
