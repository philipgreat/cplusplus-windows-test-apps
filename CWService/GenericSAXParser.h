// GenericSAXParser.h: interface for the CGenericSAXParser class.
//
//////////////////////////////////////////////////////////////////////
/*===========================================================*\
  �ļ�: DirectoryHelper.h	
  ��Ȩ: ��ţ(����)�������޹�˾
  ����: 2005-09-05
  ����: ͨ�õ�SAX�������� �ܹ����ٽ����ļ����ڴ����ݣ� �ٶȿ�
  �ο�: CDirectoryHelper , CJavaScriptGenerator
  ����: zhangxl@channel.com
  �޶���¼:	

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
