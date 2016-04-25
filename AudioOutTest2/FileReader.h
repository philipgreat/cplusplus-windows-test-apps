// FileReader.h: interface for the CFileReader class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILEREADER_H__D4489067_D150_438A_A9CF_F67F338315E9__INCLUDED_)
#define AFX_FILEREADER_H__D4489067_D150_438A_A9CF_F67F338315E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <windows.h>
class CFileReader  
{
private:
	HANDLE saveFile;
public:
	BOOL OpenFile(char *fileName);
public:
	int SeekAbsolutePosition(int pos);
	int Seek(int pos);
	int ReadFile(char *buffer, int length);
	CFileReader(char *fileName);
	virtual ~CFileReader();

};

#endif // !defined(AFX_FILEREADER_H__D4489067_D150_438A_A9CF_F67F338315E9__INCLUDED_)
