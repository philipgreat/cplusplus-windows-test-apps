// FileListHandle.h: interface for the CFileListHandle class.
//
//////////////////////////////////////////////////////////////////////
/*===========================================================*\
  文件: DirectoryHelper.h	
  版权: 青牛(北京)技术有限公司
  日期: 2005-09-05
  描述: 定义文件列表侦听的类，该类和DirectoryHelper工作来针对文件名列表来处理文件
  参考: CDirectoryHelper , CJavaScriptGenerator
  作者: zhangxl@channel.com
  修订记录:	

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
