// EComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "UTest2.h"
#include "EComboBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEComboBox

CEComboBox::CEComboBox()
{
}

CEComboBox::~CEComboBox()
{
}


BEGIN_MESSAGE_MAP(CEComboBox, CComboBox)
	//{{AFX_MSG_MAP(CEComboBox)
	ON_WM_COPYDATA()
	ON_WM_CREATE()
	ON_WM_MOUSEMOVE()
	ON_WM_DROPFILES()
	ON_CONTROL_REFLECT(CBN_EDITCHANGE, OnEditchange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEComboBox message handlers

BOOL CEComboBox::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	// TODO: Add your message handler code here and/or call default
	//pCopyDataStruct->
	MessageBox("BOOL CEComboBox::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)");

	return CComboBox::OnCopyData(pWnd, pCopyDataStruct);
}

int CEComboBox::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CComboBox::OnCreate(lpCreateStruct) == -1)
		return -1;
	//MessageBox("BOOL CEComboBox::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)");
	// TODO: Add your specialized creation code here
	
	return 0;
}

void CEComboBox::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//MessageBox("BOOL CEComboBox::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)");
	CComboBox::OnMouseMove(nFlags, point);
}

void CEComboBox::OnDropFiles(HDROP hDropInfo) 
{
	// TODO: Add your message handler code here and/or call default
	MessageBox("BOOL CEComboBox::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)");
	CComboBox::OnDropFiles(hDropInfo);
}

void CEComboBox::OnEditchange() 
{
	// TODO: Add your control notification handler code here
	//MessageBox("BOOL CEComboBox::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)");
}
