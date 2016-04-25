// UTest2View.cpp : implementation of the CUTest2View class
//

#include "stdafx.h"
#include "UTest2.h"

#include "UTest2Doc.h"
#include "UTest2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUTest2View

IMPLEMENT_DYNCREATE(CUTest2View, CEditView)

BEGIN_MESSAGE_MAP(CUTest2View, CEditView)
	//{{AFX_MSG_MAP(CUTest2View)
	ON_WM_CREATE()
	ON_COMMAND(ID_EDIT_SELECT_ALL, OnEditSelectAll)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUTest2View construction/destruction

CUTest2View::CUTest2View()
{
	// TODO: add construction code here

}

CUTest2View::~CUTest2View()
{
}

BOOL CUTest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CUTest2View drawing

void CUTest2View::OnDraw(CDC* pDC)
{
	CUTest2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CUTest2View printing

BOOL CUTest2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CUTest2View::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing.
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CUTest2View::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CUTest2View diagnostics

#ifdef _DEBUG
void CUTest2View::AssertValid() const
{
	CEditView::AssertValid();
}

void CUTest2View::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CUTest2Doc* CUTest2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUTest2Doc)));
	return (CUTest2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUTest2View message handlers

int CUTest2View::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CEditView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_sockSend.Create(SOCK_DGRAM);
	m_sockSend.Bind(67,"127.0.0.1");
	//set margins 
	GetEditCtrl().SetMargins (20,0);
	//m_Font.CreatePointFont (95, _T("ËÎÌו"));
	m_Font.CreatePointFont (110, _T("ËÎÌו"));
	this->GetEditCtrl().SetFont (&m_Font);
	
	this->GetEditCtrl().EnableScrollBarCtrl(SB_HORZ, TRUE);
#if 1
	this->GetEditCtrl().EnableScrollBarCtrl(SB_HORZ, TRUE);
	SCROLLINFO si;
	ZeroMemory(&si, sizeof(SCROLLINFO));
	si.cbSize = sizeof(si);
	si.fMask = SIF_ALL;
	si.nMin = 0; si.nMax = 100000; // width/height of wnd //
	si.nPos = 0;
	si.nPage = 1000; // page width
	si.nTrackPos = 0; // no tracking, ignored
	
	this->GetEditCtrl().SetScrollInfo(SB_HORZ, &si);
	this->SetScrollRange(SB_HORZ,20,1400);
#endif
	//this->GetEditCtrl().SetScrollRange

	return 0;
}

void CUTest2View::OnEditSelectAll() 
{
	// TODO: Add your command handler code here
	CString s;
	this->GetEditCtrl().GetWindowText (s);
	this->GetEditCtrl().SetSel(0,s.GetLength ());

	
}

void CUTest2View::OnFileSave() 
{
	// TODO: Add your command handler code here
		
	
}
