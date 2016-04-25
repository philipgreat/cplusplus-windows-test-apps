// inifile.cpp: implementation of the inifile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "inifile.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

inifile::inifile()
{
	file_path="";



}
inifile::inifile(LPCSTR filename)
{
	file_path=filename;


}

inifile::~inifile()
{
	//delete []m_buf;

}

LPTSTR inifile::getvalue(CString section, CString keyname)
{
	
	m_buf=new  char[50];
	if(file_path!="")
	{
	
		//char *buf;
		//buf=(char*)malloc(50);
		::GetPrivateProfileString (section ,keyname,"<NULL>",m_buf,20,file_path);
		return m_buf;
	
	}else{
		AfxMessageBox("文件名不能够为空或者无此文件");
		return "<NULL>";
	}
	
}

BOOL inifile::putvalue(CString section, CString keyname, CString value)

{
	if(file_path!=""){
		//::GetPrivateProfileString (section ,keyname,"<NULL>",buf,20,file_path);
		::WritePrivateProfileString (section,keyname,value,file_path);
			
		return TRUE;
	}else{
		AfxMessageBox("文件名不能够为空或者无此文件");
		return FALSE;
	}
	
}
