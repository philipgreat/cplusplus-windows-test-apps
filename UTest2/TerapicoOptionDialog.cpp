// TerapicoOptionDialog.cpp : implementation file
//

#include "stdafx.h"
#include "UTest2.h"
#include "TerapicoOptionDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTerapicoOptionDialog dialog


CTerapicoOptionDialog::CTerapicoOptionDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CTerapicoOptionDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTerapicoOptionDialog)
	m_lngMaxLengh = 32*1024;
	//}}AFX_DATA_INIT
}


void CTerapicoOptionDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTerapicoOptionDialog)
	DDX_Text(pDX, IDC_EDIT_MAX_LENGH, m_lngMaxLengh);
	DDV_MinMaxLong(pDX, m_lngMaxLengh, 0, 600000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTerapicoOptionDialog, CDialog)
	//{{AFX_MSG_MAP(CTerapicoOptionDialog)
	ON_EN_CHANGE(IDC_EDIT_MAX_LENGH, OnChangeEditMaxLengh)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTerapicoOptionDialog message handlers

void CTerapicoOptionDialog::OnChangeEditMaxLengh() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here

}

int CTerapicoOptionDialog::GetMaxLength()
{
	return this->m_lngMaxLengh;
}

void CTerapicoOptionDialog::OnOK() 
{
	// TODO: Add extra validation here
	
	if(0==this->UpdateData(TRUE)){
		goto ENDOK;
	}

	this->SaveConfig();
	this->UpdateData(FALSE);

ENDOK:
	INT I=0;
	CDialog::OnOK();
}

void CTerapicoOptionDialog::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	this->UpdateData(TRUE);
	// TODO: Add your message handler code here
	CWnd *pw=this->GetDlgItem(IDC_EDIT_MAX_LENGH);
	pw->SetFocus();
	this->ReadConfig();
	this->UpdateData(FALSE);


	//::WritePrivateProfileString(

}

/*config.ini


[editview]
maxlogsize=585

*/
#define		CONFIG_FILE_NAME	_T(".\\config.ini")
int CTerapicoOptionDialog::SaveConfig()
{
		
	//F:\suddy\vc\UTest2

	CString m;
	m.Format("%d",this->m_lngMaxLengh);
	//MessageBox(m);
	

	::WritePrivateProfileString(
		_T("editview"),
		_T("maxlogsize"),
		m,
		CONFIG_FILE_NAME);
	
	m.Empty();


	return 0;

}

int CTerapicoOptionDialog::ReadConfig()
{
	CString m;
	m.Format("%d",this->m_lngMaxLengh);
	
	LPSTR pMaxValue=new TCHAR[21];

	
	::GetPrivateProfileString(
		_T("editview"),				//section
		_T("maxlogsize"),			//key
		_T("200"),					//default
		pMaxValue,					//return string
		20,							//size
		CONFIG_FILE_NAME);			//filename
	
	
	
	this->m_lngMaxLengh=atoi(pMaxValue);
	
	
	
	delete[] pMaxValue;
	

	//CString m;
	//m.Format("%d",this->m_lngMaxLengh);
	//MessageBox(m);
	
	
	//MessageBox(p);
	return 0;
}
