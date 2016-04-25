// inifile.h: interface for the inifile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INIFILE_H__83EE9981_D89D_11D4_9393_0000E8233645__INCLUDED_)
#define AFX_INIFILE_H__83EE9981_D89D_11D4_9393_0000E8233645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//##ModelId=4095FA7D01C5
class inifile  
{
protected:

	//##ModelId=4095FA7D01D4
	char *m_buf;

public:
	//##ModelId=4095FA7D01E4
	BOOL putvalue(CString section,CString keyname,CString value);
	//##ModelId=4095FA7D01F6
	LPTSTR getvalue(CString section,CString keyname);
	
	//##ModelId=4095FA7D0205
	LPCTSTR file_path;

	//##ModelId=4095FA7D0213
	inifile();
	//##ModelId=4095FA7D0214
	inifile(LPCSTR filename);

	//##ModelId=4095FA7D0222
	virtual ~inifile();

};

#endif // !defined(AFX_INIFILE_H__83EE9981_D89D_11D4_9393_0000E8233645__INCLUDED_)
