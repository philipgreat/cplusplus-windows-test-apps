// FindResultView.cpp : implementation file
//

#include "stdafx.h"
#include "db.h"
#include "FindResultView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFindResultView

IMPLEMENT_DYNCREATE(CFindResultView, CListView)

//##ModelId=4095FA7E00DA
CFindResultView::CFindResultView()
{
}

//##ModelId=4095FA7E00FB
CFindResultView::~CFindResultView()
{
}


BEGIN_MESSAGE_MAP(CFindResultView, CListView)
//{{AFX_MSG_MAP(CFindResultView)
ON_WM_CREATE()
ON_NOTIFY_REFLECT(NM_CLICK, OnItemClick)
ON_WM_LBUTTONDOWN()
ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, OnItemchanged)
ON_NOTIFY_REFLECT(HDN_ITEMCHANGED, OnItemchanged)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFindResultView drawing

//##ModelId=4095FA7E00EC
void CFindResultView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CFindResultView diagnostics

#ifdef _DEBUG
//##ModelId=4095FA7E0109
void CFindResultView::AssertValid() const
{
	CListView::AssertValid();
}

//##ModelId=4095FA7E0119
void CFindResultView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFindResultView message handlers

//##ModelId=4095FA7E011C
int CFindResultView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;
	//
	
	// TODO: Add your specialized creation code here
	
	return 0;
}

//##ModelId=4095FA7E00EA
void CFindResultView::OnInitialUpdate() 
{
	CListView::OnInitialUpdate();
	
	//this->ModifyStyle (GetStyle() & LVS_REPORT);
	GetListCtrl ().ModifyStyle (0,LVS_REPORT|LVS_EX_FULLROWSELECT);
	GetListCtrl ().SetExtendedStyle (LVS_EX_FULLROWSELECT |LVS_EX_GRIDLINES |LVS_EX_INFOTIP);
	
	
	GetListCtrl ().InsertColumn (0,"行号",LVCFMT_RIGHT,50);
	GetListCtrl ().InsertColumn (1,"查找结果",LVCFMT_LEFT,150);
	//>GetListCtrl ().InsertColumn (
	
	
	
	
	// TODO: Add your specialized code here and/or call the base class
	
}

//##ModelId=4095FA7E012A
void CFindResultView::OnItemClick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	//int i=this->GetListCtrl ().
	//this->GetListCtrl ().GetItemText (
	*pResult = 0;
}

//##ModelId=4095FA7E0148
void CFindResultView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CListView::OnLButtonDown(nFlags, point);
	
	
	//   int ColNum;
    
}

//##ModelId=4095FA7E0157
void CFindResultView::OnItemchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	
	BOOL bMaximized = FALSE;
	CChildFrame* pActiveWnd = (CChildFrame*)((CMainFrame *)AfxGetMainWnd())->MDIGetActive(&bMaximized);
	CDbView *pActiveView = NULL;
	if (!pActiveWnd) 
	{
		return;
	}
	pActiveView = (CDbView *)pActiveWnd->GetActiveView();
	
	int Index;
	
	
	POSITION pos = this->GetListCtrl().GetFirstSelectedItemPosition();
	if (pos == NULL)
		TRACE0("No items were selected!\n");
	else{
		while (pos)
		{
			Index = this->GetListCtrl().GetNextSelectedItem(pos);
			CString content;
			pActiveView ->GetEditCtrl ().GetWindowText (content);
			int i=content.Find (this->GetListCtrl ().GetItemText (Index,1));
			if(i!=-1)
			{
				pActiveView ->GetEditCtrl ().SetSel (i,i+this->GetListCtrl().GetItemText (Index,1).GetLength ());
			}
			//TRACE1("Item %d was selected!\n", nItem);	
			// you could do your own processing on nItem here
		}
	}
	
	
	//   int ColNum;
    
	
	*pResult = 0;
}
