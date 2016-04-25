// FileLogger.h: interface for the CFileLogger class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILELOGGER_H__3A5A1F35_1D05_4392_AE8D_17388DB5C179__INCLUDED_)
#define AFX_FILELOGGER_H__3A5A1F35_1D05_4392_AE8D_17388DB5C179__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <windows.h>
class CFileLogger  
{
private:
	HANDLE saveFile;
public:
	int Log(const char* content);
	int WriteFile(char *buffer,int length);
	int WriteHex(char *buffer,int length);

	BOOL OpenFile(char *fileName);
	CFileLogger(char *fileName);
	virtual ~CFileLogger();

};

#endif // !defined(AFX_FILELOGGER_H__3A5A1F35_1D05_4392_AE8D_17388DB5C179__INCLUDED_)
