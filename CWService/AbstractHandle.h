// AbstractHandle.h: interface for the CAbstractHandle class.
//
//////////////////////////////////////////////////////////////////////
/*===========================================================*\
  文件: BaseCertificate.h	
  版权: 青牛(北京)技术有限公司
  日期: 2005-09-05
  描述: 对于一个sax的内容处理的handle, 声明接口
  参考: CGenericSaxParser, CCertificateParserHelper
  作者: zhangxl@channel.com
  修订记录:	

\*===========================================================*/
#if !defined(AFX_ABSTRACTHANDLE_H__46C82BBD_C2DA_47E8_B3DF_5BE2CFF7B101__INCLUDED_)
#define AFX_ABSTRACTHANDLE_H__46C82BBD_C2DA_47E8_B3DF_5BE2CFF7B101__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef _WIN32
	#include <windows.h>
#else //for unixes
	typedef  unsigned long       DWORD;
	typedef  int				 BOOL;
	#define  TRUE				(int)1;
	#define  FALSE				(int)0;
#endif

class CAbstractHandle  
{
public:
	virtual int StartDocument() = 0; 
	virtual int EndDocument() = 0;
	virtual int StartElement(const char *element) = 0;
	virtual int EndElement() = 0;
	virtual int OnProperty(const char* element, const char* name, const char*value) = 0; 
	virtual int OnError(const char* element, const char* name, const char*value) = 0;
	CAbstractHandle();
	virtual ~CAbstractHandle();
};

#endif // !defined(AFX_ABSTRACTHANDLE_H__46C82BBD_C2DA_47E8_B3DF_5BE2CFF7B101__INCLUDED_)


