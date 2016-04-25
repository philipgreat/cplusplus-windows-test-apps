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

//##ModelId=4095FA7D0213
inifile::inifile()
{
	file_path="";



}
//##ModelId=4095FA7D0214
inifile::inifile(LPCSTR filename)
{
	file_path=filename;


}

//##ModelId=4095FA7D0222
inifile::~inifile()
{
	//delete []m_buf;

}

//##ModelId=4095FA7D01F6
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

//##ModelId=4095FA7D01E4
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
