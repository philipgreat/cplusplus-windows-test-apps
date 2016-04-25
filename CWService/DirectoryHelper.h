// DirectoryHelper.h: interface for the CDirectoryHelper class.
//
//////////////////////////////////////////////////////////////////////
/*===========================================================*\
  �ļ�: DirectoryHelper.h	
  ��Ȩ: ��ţ(����)�������޹�˾
  ����: 2005-09-05
  ����: �����ļ���Ŀ¼�Ļ����࣬�����˶�д�ļ���ö��Ŀ¼�ȹ��ܸ���,
		��ƽ̨���(��������WINDOWS)
  �ο�: 
  ����: zhangxl@channel.com
  �޶���¼:	

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
