// GenericSAXParser.h: interface for the CGenericSAXParser class.
//
//////////////////////////////////////////////////////////////////////
/*===========================================================*\
  文件: DirectoryHelper.h	
  版权: 青牛(北京)技术有限公司
  日期: 2005-09-05
  描述: 通用的SAX解析器， 能够快速解析文件和内存数据， 速度快
  参考: CDirectoryHelper , CJavaScriptGenerator
  作者: zhangxl@channel.com
  修订记录:	

\*===========================================================*/
#if !defined(AFX_GENERICSAXPARSER_H__BA893C3B_81CF_427A_BBDF_0512231717B1__INCLUDED_)
#define AFX_GENERICSAXPARSER_H__BA893C3B_81CF_427A_BBDF_0512231717B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "AbstractHandle.h"

#include <iostream>
#include "atlbase.h"
#include <comutil.h>
#include <MSXML.h>
#include <MSXML2.h>
#pragma comment(lib, "MsXml2.Lib");
//#import "C:\WINNT\system32\MSXML4.DLL"
class CGenericSAXParser  
{
private:
	CAbstractHandle *handle;
	BOOL ForeachNode(IXMLDOMNode *node);
public:
	int Parse(const char* xmlText);
	BOOL SetHandle(CAbstractHandle *handle);
	CGenericSAXParser();
	virtual ~CGenericSAXParser();
};

#endif // !defined(AFX_GENERICSAXPARSER_H__BA893C3B_81CF_427A_BBDF_0512231717B1__INCLUDED_)
