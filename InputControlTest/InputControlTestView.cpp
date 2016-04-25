// InputControlTestView.cpp : implementation of the CInputControlTestView class
//

#include "stdafx.h"
#include "InputControlTest.h"

#include "InputControlTestDoc.h"
#include "InputControlTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInputControlTestView

IMPLEMENT_DYNCREATE(CInputControlTestView, CView)

BEGIN_MESSAGE_MAP(CInputControlTestView, CView)
	//{{AFX_MSG_MAP(CInputControlTestView)
	ON_WM_KEYDOWN()
	ON_WM_MOUSEWHEEL()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInputControlTestView construction/destruction

CInputControlTestView::CInputControlTestView()
{
	// TODO: add construction code here

}

CInputControlTestView::~CInputControlTestView()
{
}

BOOL CInputControlTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CInputControlTestView drawing

#include "ListSelector.h"


void CInputControlTestView::OnDraw(CDC* pDC)
{
	CInputControlTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CListSelector *p=CListSelector::getSampleSelector();
	CClientDC dc(this);
	dc.SetBkMode(TRANSPARENT);
	//p->draw(dc,100,100,400,360);
	//this->Invalidate();


	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CInputControlTestView printing

BOOL CInputControlTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CInputControlTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CInputControlTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CInputControlTestView diagnostics

#ifdef _DEBUG
void CInputControlTestView::AssertValid() const
{
	CView::AssertValid();
}

void CInputControlTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CInputControlTestDoc* CInputControlTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CInputControlTestDoc)));
	return (CInputControlTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CInputControlTestView message handlers

void CInputControlTestView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	
	CListSelector *p=CListSelector::getSampleSelector();
	CClientDC dc(this);
	dc.SetBkMode(TRANSPARENT);
	
	char c=(char)nChar;
	this->Invalidate(FALSE);
	//if(c=='a'
	switch(c){
	case 38:
		p->focusNext();
		break;
	case 40:
		p->focusPrev();
		break;
	
	}
	p->draw(dc,200,20,200,360);
	this->Invalidate(FALSE);


	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CInputControlTestView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	CListSelector *p=CListSelector::getSampleSelector();
	CClientDC dc(this);
	dc.SetBkMode(TRANSPARENT);
	

	if(zDelta>0){
		p->focusNext();
	}else{
		p->focusPrev();
	}
	p->draw(dc,200,20,200,360);
	this->Invalidate(FALSE);
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}
