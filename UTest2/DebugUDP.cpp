// DebugUDP.cpp : implementation file
//

#include "stdafx.h"
#include "UTest2.h"
#include "DebugUDP.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDebugUDP

CDebugUDP::CDebugUDP()
{
	time1=0;
}

CDebugUDP::~CDebugUDP()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CDebugUDP, CSocket)
//{{AFX_MSG_MAP(CDebugUDP)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CDebugUDP member functions
#include "mainfrm.h"
static BOOL IsMatchExp(CString pattern, CString testString)
{
	int orpos=pattern.Find("|");
	int andpos=pattern.Find("&");
	int notpos=pattern.Find("!")
	/*
	abcd|12312
	01234567890123456789
	    ^ 
	*/

	if(orpos<1&&andpos<1){
		//-1 or zero
		return (testString.Find(pattern)>=0);
	}
	if(orpos>0){
		CString str1=pattern.Mid(0,orpos);
		CString str2=pattern.Mid(orpos+1);
		return (testString.Find(str1)>=0||testString.Find(str2)>=0);
	}
	if(andpos>0){
		CString str1=pattern.Mid(0,andpos);
		CString str2=pattern.Mid(andpos+1);
		return (testString.Find(str1)>=0&&testString.Find(str2)>=0);
	}
	if(notpos=0){		
		return !(testString.Find(str1)>=0);
	}

	return FALSE;

}

void CDebugUDP::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	char szSend[1024]={0};
	
	CString clientAddr("127.0.0.1");
	
	UINT port=0;
	int iSend=0;
	
	//sprintf(szSend,"%010d",iIndex++);
	//int iSend= m_sockSend.SendTo(szSend,10,6801,"127.0.0.1",0);
	//memset(szSend,0,20);
	
	iSend=this->ReceiveFrom (szSend,1024,clientAddr,port);	
	CMainFrame *mf=(CMainFrame *)AfxGetMainWnd();


	CEditView *pView=(CEditView *)mf->GetActiveView ();
	
	CString edittext="00000000000000000000000000000000000000000";
	
	//pView->GetEditCtrl().GetWindowText (c);
	
	pView->GetEditCtrl().GetWindowText(edittext);
	
	CString pattern=((CMainFrame *)AfxGetMainWnd())->GetToolBarText();
	//Get pattern
	CString showtext=(CString)(szSend);
	//if the pattern not found, add it;

	

	if(IsMatchExp(pattern,showtext)){
		c=showtext+edittext;		
		pView->GetEditCtrl().SetWindowText(c.Mid(0,mf->GetMaxLogLength()));

	}
	
	mf->SetWindowText ((CString)szSend);
	
}
//MessageBox(NULL,szSend,"Nome",MB_OK);


