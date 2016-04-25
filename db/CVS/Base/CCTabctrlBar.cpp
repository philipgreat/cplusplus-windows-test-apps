
#include "stdafx.h"
#include "CCTabCtrlBar.h"
#include "mainfrm.h"
#include "ChildFrm.h"
//#include "lasview.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCTabCtrlBar

CCTabCtrlBar::CCTabCtrlBar()
{
	m_nActiveTab = 0;
}

CCTabCtrlBar::~CCTabCtrlBar()
{
	while(!m_views.IsEmpty())
	{
		TCB_ITEM *pMember=m_views.RemoveHead();
		delete pMember;
	}
}

#define IDC_TABCTRLBAR 1000

BEGIN_MESSAGE_MAP(CCTabCtrlBar, CCControlBar)
	//{{AFX_MSG_MAP(CCTabCtrlBar)
	ON_WM_CREATE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TABCTRLBAR, OnTabSelChange)
	ON_WM_WINDOWPOSCHANGED()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_EVENTSINK_MAP(CCTabCtrlBar, CCControlBar)
	//ON_EVENT(CLASView, 8810, MAPX_DISPID_TOOLUSED, OnToolUsed, VTS_I2 VTS_R8 VTS_R8 VTS_R8 VTS_R8 VTS_R8 VTS_BOOL VTS_BOOL VTS_PBOOL)
	//ON_EVENT(CCTabCtrlBar, 8810, -605 /* MouseDown */, OnMouseDownMap, VTS_PI2 VTS_PI2 VTS_PR4 VTS_PR4)
//	ON_EVENT(CLASView, 8810, -606 /* MouseMove */, OnMouseDownMap, VTS_PI2 VTS_PI2 VTS_PR4 VTS_PR4)
END_EVENTSINK_MAP()
/////////////////////////////////////////////////////////////////////////////
// CCTabCtrlBar message handlers
// 
// *** K.Stowell
void CCTabCtrlBar::OnWindowPosChanged(WINDOWPOS FAR* lpwndpos) 
{
	CWnd *pWnd;

	if (IsFloating()) 
	{
//		m_ctrlMapX.MoveWindow(5,3,lpwndpos->cx-10,lpwndpos->cx-40);
	/*	m_tabctrl.MoveWindow(3,3+lpwndpos->cx-38, lpwndpos->cx-6, lpwndpos->cy-lpwndpos->cx+33);
		for (POSITION pos=m_views.GetHeadPosition(); pos; m_views.GetNext(pos)) 
		{
			pWnd=m_views.GetAt(pos)->pWnd;
			pWnd->MoveWindow(10, 10+lpwndpos->cx-38, lpwndpos->cx-22, lpwndpos->cy-10-(lpwndpos->cx-6)-2);
		}*/

		CRect pRect;
		GetClientRect(&pRect);
	    switch (m_nDockBarID)
		{
	    case AFX_IDW_DOCKBAR_TOP:
			{
				pRect.DeflateRect(3,3+18,3,0);
				break;
			}
		case AFX_IDW_DOCKBAR_BOTTOM:
			{
				pRect.DeflateRect(3,0+18,6,3);
				break;
			}
		case AFX_IDW_DOCKBAR_LEFT:
			{
				pRect.DeflateRect(3,3+18,0,3);
				break;
			}
		case AFX_IDW_DOCKBAR_RIGHT:
			{
				pRect.DeflateRect(0,3+18,3,3);
				break;
			}
		}
//		m_ctrlMapX.MoveWindow(pRect.left+2,pRect.top,pRect.Width()-4,pRect.Width()-34);
		//m_tabctrl.MoveWindow(pRect.left,pRect.top+pRect.Width()-32,pRect.Width(),pRect.Height()-pRect.Width()+33);
		m_tabctrl.MoveWindow(pRect);
		
		pRect.left+=6;
		pRect.right-=6;
		pRect.top+=5;//+pRect.Width()-20;
		pRect.bottom-=28;
		if (pRect.right-pRect.left>400)
		{
		
			pRect.right=pRect.left+400;

		
		}
		for (POSITION pos=m_views.GetHeadPosition(); pos; m_views.GetNext(pos)) 
		{
			pWnd=m_views.GetAt(pos)->pWnd;
			pWnd->MoveWindow(pRect);
		}


	}
	else
	{
		CRect pRect;
		GetClientRect(&pRect);
	    switch (m_nDockBarID)
		{
	    case AFX_IDW_DOCKBAR_TOP:
			{
				pRect.DeflateRect(3,3+18,3,0);
				break;
			}
		case AFX_IDW_DOCKBAR_BOTTOM:
			{
				pRect.DeflateRect(3,0+18,6,3);
				break;
			}
		case AFX_IDW_DOCKBAR_LEFT:
			{
				pRect.DeflateRect(3,3+18,0,3);
				break;
			}
		case AFX_IDW_DOCKBAR_RIGHT:
			{
				pRect.DeflateRect(0,3+18,3,3);
				break;
			}
		}
//		m_ctrlMapX.MoveWindow(pRect.left+2,pRect.top,pRect.Width()-4,pRect.Width()-34);
		//m_tabctrl.MoveWindow(pRect.left,pRect.top+pRect.Width()-32,pRect.Width(),pRect.Height()-pRect.Width()+33);
		m_tabctrl.MoveWindow(pRect);
		
		pRect.left+=6;
		pRect.right-=6;
		pRect.top+=20;//+pRect.Width()-20;
		pRect.bottom-=28;
		if (pRect.right-pRect.left>400)
		{
		
			pRect.right=pRect.left+400;

		
		}
		for (POSITION pos=m_views.GetHeadPosition(); pos; m_views.GetNext(pos)) 
		{
			pWnd=m_views.GetAt(pos)->pWnd;
			pWnd->MoveWindow(pRect);
		}

	}
	CCControlBar::OnWindowPosChanged(lpwndpos);
}

CImageList* CCTabCtrlBar::SetTabImageList(CImageList *pImageList)
{
	return m_tabctrl.SetImageList (pImageList);
}

BOOL CCTabCtrlBar::ModifyTabStyle(DWORD dwRemove, DWORD dwAdd, UINT nFlags)
{
	return m_tabctrl.ModifyStyle(dwRemove, dwAdd);
}

int CCTabCtrlBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CCControlBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	//Create the Tab Control
	if (!m_tabctrl.Create(WS_VISIBLE|WS_CHILD|TCS_BOTTOM|TCS_TOOLTIPS, 
		CRect(0,0,0,0), this, IDC_TABCTRLBAR))
	{
		TRACE0("Unable to create tab control bar\n");
		return -1;
	}



	//m_ctrlMapX.GetLayers ().Item ("最优路径路口").SetVisible (FALSE);



	// set "normal" GUI-font
	CFont *font = CFont::FromHandle((HFONT)::GetStockObject(DEFAULT_GUI_FONT));
	m_tabctrl.SetFont(font);

// VC5 Support.
#if _MSC_VER >= 1200
	m_ToolTip = m_tabctrl.GetToolTips();
	m_tabctrl.SetToolTips(m_ToolTip);
#else
	m_ToolTip = m_tabctrl.GetTooltips();
	m_tabctrl.SetTooltips(m_ToolTip);
#endif
	return 0;
}

// *** KStowell
void CCTabCtrlBar::OnTabSelChange(NMHDR* pNMHDR, LRESULT* pResult)
{
	SetActiveView(m_tabctrl.GetCurSel());
	Invalidate();
}

//////////////////////////////////////////////////
// The remainder of this class was written by Dirk Clemens...

BOOL CCTabCtrlBar::AddView(LPCTSTR lpszLabel, CRuntimeClass *pViewClass, CCreateContext *pContext)
{	

#ifdef _DEBUG
	ASSERT_VALID(this);
	ASSERT(pViewClass != NULL);
	ASSERT(pViewClass->IsDerivedFrom(RUNTIME_CLASS(CWnd)));
	ASSERT(AfxIsValidAddress(pViewClass, sizeof(CRuntimeClass), FALSE));
#endif

	CCreateContext context;
	if (pContext == NULL)
	{
		// if no context specified, generate one from the currently selected
		//  client if possible
		CView* pOldView = NULL;
		if (pOldView != NULL && pOldView->IsKindOf(RUNTIME_CLASS(CView)))
		{
			// set info about last pane
			ASSERT(context.m_pCurrentFrame == NULL);
			context.m_pLastView = pOldView;
			context.m_pCurrentDoc = pOldView->GetDocument();
			if (context.m_pCurrentDoc != NULL)
				context.m_pNewDocTemplate =
				context.m_pCurrentDoc->GetDocTemplate();
		}
		pContext = &context;
	}
	
	CWnd* pWnd;
	TRY
	{
		pWnd = (CWnd*)pViewClass->CreateObject();
		if (pWnd == NULL)
			AfxThrowMemoryException();
	}
	CATCH_ALL(e)
	{
		TRACE0("Out of memory creating a view.\n");
		// Note: DELETE_EXCEPTION(e) not required
		return FALSE;
	}
	END_CATCH_ALL
		
    ASSERT_KINDOF(CWnd, pWnd);
	ASSERT(pWnd->m_hWnd == NULL);       // not yet created
	
	DWORD dwStyle = AFX_WS_DEFAULT_VIEW;
	CRect rect;
	// Create with the right size and position
	if (!pWnd->Create(NULL, NULL, dwStyle, rect, this, 0, pContext))
	{
		TRACE0("Warning: couldn't create client pane for view.\n");
		// pWnd will be cleaned up by PostNcDestroy
		return FALSE;
	}
	m_pActiveView = (CView*) pWnd;

	TCB_ITEM *pMember=new TCB_ITEM;
	pMember->pWnd=pWnd;
	strcpy(pMember->szLabel, lpszLabel);
	m_views.AddTail(pMember);

	// ToolTip support for tabs.
	if((m_views.GetCount()-1)==0) 
	{
		m_ToolTip->AddTool( &m_tabctrl, lpszLabel,
			NULL, m_views.GetCount()-1 );
	}
	else {
		m_ToolTip->AddTool( &m_tabctrl, lpszLabel,
			CRect(0,0,0,0), m_views.GetCount()-1 );
	}
	
	int nViews = m_views.GetCount();
	if (nViews!=1)
	{
		pWnd->EnableWindow(FALSE);
		pWnd->ShowWindow(SW_HIDE);
	}else{
	
	}

	TC_ITEM tci;
	tci.mask = TCIF_TEXT | TCIF_IMAGE;
	tci.pszText = (LPTSTR)(LPCTSTR)lpszLabel;
	tci.iImage = nViews-1;
	m_tabctrl.InsertItem(nViews, &tci);

	return TRUE;
}

void CCTabCtrlBar::RemoveView(int nView)
{
	ASSERT_VALID(this);
	ASSERT(nView >= 0);

	// remove the page from internal list
	m_views.RemoveAt(m_views.FindIndex(nView));
}

void CCTabCtrlBar::SetActiveView(int nNewTab)
{
	ASSERT_VALID(this);
	ASSERT(nNewTab >= 0);

	if (nNewTab!=-1 && nNewTab!=m_nActiveTab)
	{
        TCB_ITEM *newMember=m_views.GetAt(m_views.FindIndex(nNewTab));
        TCB_ITEM *oldMember=NULL;
		
        if (m_nActiveTab!=-1)
        {
            oldMember=m_views.GetAt(m_views.FindIndex(m_nActiveTab));
            oldMember->pWnd->EnableWindow(FALSE);
            oldMember->pWnd->ShowWindow(SW_HIDE);
        }
        newMember->pWnd->EnableWindow(TRUE);
        newMember->pWnd->ShowWindow(SW_SHOW);
        newMember->pWnd->SetFocus();

        m_pActiveView = (CView *)newMember->pWnd;

        m_nActiveTab = nNewTab;
		// select the tab (if tab programmatically changed)
		m_tabctrl.SetCurSel(m_nActiveTab);
    }
}

void CCTabCtrlBar::SetActiveView(CRuntimeClass *pViewClass)
{
	ASSERT_VALID(this);
	ASSERT(pViewClass != NULL);
	ASSERT(pViewClass->IsDerivedFrom(RUNTIME_CLASS(CWnd)));
	ASSERT(AfxIsValidAddress(pViewClass, sizeof(CRuntimeClass), FALSE));

	int nNewTab = 0;
	for (POSITION pos=m_views.GetHeadPosition(); pos; m_views.GetNext(pos))
	{
		TCB_ITEM *pMember=m_views.GetAt(pos);
		if (pMember->pWnd->IsKindOf(pViewClass))
		{
            m_pActiveView->EnableWindow(FALSE);
            m_pActiveView->ShowWindow(SW_HIDE);
			
			m_pActiveView = (CView*)pMember->pWnd;
			m_pActiveView->EnableWindow(TRUE);
			m_pActiveView->ShowWindow(SW_SHOW);
			m_pActiveView->SetFocus();
			
	        m_nActiveTab = nNewTab;
			m_tabctrl.SetCurSel(m_nActiveTab);

			break;
		}
		nNewTab++;
    }
}

CView* CCTabCtrlBar::GetActiveView()
{
	return m_pActiveView;
}

CView* CCTabCtrlBar::GetView(int nView)
{
	ASSERT_VALID(this);
	ASSERT(nView >= 0);
	

	if (nView!=-1)
	{
        TCB_ITEM *pMember=m_views.GetAt(m_views.FindIndex(nView));
		return (CView*)pMember->pWnd;
	}
	else
		return NULL;
}

CView* CCTabCtrlBar::GetView(CRuntimeClass *pViewClass)
{
	ASSERT_VALID(this);
	ASSERT(pViewClass != NULL);
	ASSERT(pViewClass->IsDerivedFrom(RUNTIME_CLASS(CWnd)));
	ASSERT(AfxIsValidAddress(pViewClass, sizeof(CRuntimeClass), FALSE));

	for (POSITION pos=m_views.GetHeadPosition(); pos; m_views.GetNext(pos))
	{
		TCB_ITEM *pMember=m_views.GetAt(pos);
		if (pMember->pWnd->IsKindOf(pViewClass))
		{
			return (CView*)pMember->pWnd;
		}
    }
	return NULL;
}


