// EToolBar.cpp : implementation file
//

#include "stdafx.h"
#include "UTest2.h"
#include "EToolBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEToolBar

CEToolBar::CEToolBar()
{
}

CEToolBar::~CEToolBar()
{
}


BEGIN_MESSAGE_MAP(CEToolBar, CToolBar)
	//{{AFX_MSG_MAP(CEToolBar)
	ON_WM_CREATE()
	ON_WM_COPYDATA()
	ON_WM_KEYDOWN()
	ON_WM_DESTROY()
	ON_WM_ENABLE()
	ON_WM_PAINT()
	ON_WM_ACTIVATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEToolBar message handlers

int CEToolBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CToolBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	
	// TODO: Add your specialized creation code here
	
	return 0;

}
#define BUTTON_RESOURCE_ID 1000*1225-5
int CEToolBar::AddNewCombo(int index, int style)
{
	CRect rect;
	this->SetButtonInfo (index,BUTTON_RESOURCE_ID,TBBS_SEPARATOR,400);
	this->GetItemRect (index,&rect);
	rect.bottom +=300;
	
	
	m_snapFont.CreatePointFont (120, _T("ËÎÌו"));
	
	m_wndSnap.SetFont (&m_snapFont);
	
	m_wndSnap.GetDC()->SelectObject (&m_snapFont);
	
	//m_wndSnap.GetCl
	//m_wndSnap.GetDC


	if(m_wndSnap.Create (WS_CHILD|WS_VISIBLE|CBS_AUTOHSCROLL|
		CBS_DROPDOWN|CBS_HASSTRINGS,rect,this,BUTTON_RESOURCE_ID))
	{
	
	       TRACE0("FAIL TO CREATE IT!");

	}
	return 0;

}

BOOL CEToolBar::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	// TODO: Add your message handler code here and/or call default
	MessageBox("Message");

	return CToolBar::OnCopyData(pWnd, pCopyDataStruct);
}

void CEToolBar::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	MessageBox("void CEToolBar::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) ");
	CToolBar::OnKeyDown(nChar, nRepCnt, nFlags);
}

CString CEToolBar::GetFilText()
{
	
	//m_wndSnap.GetLBText(m_wndSnap.GetCurSel()
	CString ret="";
	m_wndSnap.GetWindowText(ret);
	//m_wndSnap.FindStringExact(
	if(m_wndSnap.FindStringExact (0,ret)<0&&ret!=""){
		m_wndSnap.AddString (ret);
	}
	return ret;

}


CString CEToolBar::GetTextByIndex(int index)
{
	
	//m_wndSnap.GetLBText(m_wndSnap.GetCurSel()
	CString ret="";
	m_wndSnap.GetLBText(index,ret);
	return ret;

}

int CEToolBar::GetComboItemCount()
{
	return m_wndSnap.GetCount();
}
#define		CONFIG_FILE_NAME	_T(".\\config.ini")
int CEToolBar::SaveFilters()
{
	CString m;
	int count=this->GetComboItemCount();
	for(int i=0;i<count;i++){
		m.Format("filter%d",i);
		//MessageBox(m);
		this->GetTextByIndex(i);
		::WritePrivateProfileString(
			_T("filter"),
			m,
			this->GetTextByIndex(i),
			CONFIG_FILE_NAME);
	}
		
	m.Format("%d",count);
	::WritePrivateProfileString(
		_T("filter"),
		_T("count"),
		m,
		CONFIG_FILE_NAME);


	/*
	::WritePrivateProfileString(
		_T("filter"),
		_T("maxlogsize"),
		m,
		CONFIG_FILE_NAME);
	*/
	m.Empty();
	return 0;
}

void CEToolBar::OnDestroy() 
{
	CToolBar::OnDestroy();
	this->SaveFilters();

	// TODO: Add your message handler code here
	
}

int CEToolBar::LoadSettings()
{
	CString m;
	CString filterValue;
	TCHAR *pCountStr=new TCHAR[81];
	int count=0;
	
	::GetPrivateProfileString(
		_T("filter"),				//section
		_T("count"),				//key
		_T("0"),					//default
		pCountStr,					//return string
		80,							//size
		CONFIG_FILE_NAME);			//filename

	count=atoi(pCountStr);
	//MessageBox("123",pCountStr);
	for(int i=0;i<count;i++){
		m.Format("filter%d",i);
		//MessageBox(m);
		this->GetTextByIndex(i);
		::GetPrivateProfileString(
			_T("filter"),				//section
			m,							//key
			_T("0"),					//default
			pCountStr,					//return string
			80,							//size
			CONFIG_FILE_NAME);			//filename
		
		CString str="";
		str.Format("%s",pCountStr);

		this->m_wndSnap.AddString(str);
		//m_wndSnap.AddString ("sdf");
		//MessageBox("123",pCountStr);

	}
		


	/*
	::WritePrivateProfileString(
		_T("filter"),
		_T("maxlogsize"),
		m,
		CONFIG_FILE_NAME);
	*/
	delete []pCountStr;

	m.Empty();
	return 0;
}

void CEToolBar::OnEnable(BOOL bEnable) 
{
	CToolBar::OnEnable(bEnable);

	// TODO: Add your message handler code here
	
}


void CEToolBar::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	CToolBar::OnActivate(nState, pWndOther, bMinimized);
	
	// TODO: Add your message handler code here
	
}


int CEToolBar::ClearComboBoxItems()
{
	
	int count=this->GetComboItemCount();
	for(int i=0;i<count;i++){
		this->m_wndSnap.DeleteString(0);
	}


	return 0;
}