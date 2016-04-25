// DirectoryHelper.h: interface for the CDirectoryHelper class.
//
//////////////////////////////////////////////////////////////////////
/*===========================================================*\
  文件: DirectoryHelper.h	
  版权: 青牛(北京)技术有限公司
  日期: 2005-09-05
  描述: 操作文件和目录的基础类，包括了读写文件，枚举目录等功能该类,
		和平台相关(仅仅用于WINDOWS)
  参考: 
  作者: zhangxl@channel.com
  修订记录:	

\*===========================================================*/
#if !defined(AFX_DIRECTORYHELPER_H__DEC9D339_B154_426B_99F1_8331BCBAFBE2__INCLUDED_)
#define AFX_DIRECTORYHELPER_H__DEC9D339_B154_426B_99F1_8331BCBAFBE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <windows.h>

#include "FileListHandle.h"

class CDirectoryHelper 
{
private:
	static	BOOL IsFile(WIN32_FIND_DATA &findFileData);
	//char path[MAX_PATH];
public:
	static void ListFileName(const WCHAR *wildcard, CFileListHandle *handle);
	static BOOL Exists(const WCHAR *fileName);
	static BOOL WriteBinaryFile(const WCHAR *fileName, const BYTE *data, DWORD len);
	static BOOL ReadBinaryFile(const WCHAR *fileName,BYTE *recv,DWORD *len);
	static DWORD WriteTextFile(const WCHAR *fileName, char* text, DWORD len);
	static BOOL DeleteFile(const WCHAR* fileName);
	static char* ReadTextFile(const WCHAR* fileName,char *text, DWORD *len);
	static void ListFiles(const WCHAR* wildcard);
	CDirectoryHelper();
	virtual ~CDirectoryHelper();

};

#endif // !defined(AFX_DIRECTORYHELPER_H__DEC9D339_B154_426B_99F1_8331BCBAFBE2__INCLUDED_)
