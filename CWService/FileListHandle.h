// FileListHandle.h: interface for the CFileListHandle class.
//
//////////////////////////////////////////////////////////////////////
/*===========================================================*\
  �ļ�: DirectoryHelper.h	
  ��Ȩ: ��ţ(����)�������޹�˾
  ����: 2005-09-05
  ����: �����ļ��б��������࣬�����DirectoryHelper����������ļ����б��������ļ�
  �ο�: CDirectoryHelper , CJavaScriptGenerator
  ����: zhangxl@channel.com
  �޶���¼:	

\*===========================================================*/
#if !defined(AFX_FILELISTHANDLE_H__9CB95C86_4962_49F2_9B17_3691C70509F4__INCLUDED_)
#define AFX_FILELISTHANDLE_H__9CB95C86_4962_49F2_9B17_3691C70509F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <windows.h>
class CFileListHandle{
public:
	virtual void OnStart() = 0;
	virtual BOOL OnFileName(const WCHAR* fileName) =0 ;
	//unicode version
	virtual void OnEnd() = 0;

public:
	CFileListHandle(){}
	virtual ~CFileListHandle(){}
};

#endif // !defined(AFX_FILELISTHANDLE_H__9CB95C86_4962_49F2_9B17_3691C70509F4__INCLUDED_)
