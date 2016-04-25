// CommonContext.h: interface for the CCommonContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMMONCONTEXT_H__E61386B1_EB56_4B6F_BDBE_DE56FB6ED0B4__INCLUDED_)
#define AFX_COMMONCONTEXT_H__E61386B1_EB56_4B6F_BDBE_DE56FB6ED0B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CCommonContext  
{
public:
	virtual char* GetEnvProperty(const char *name) = 0;
	CCommonContext();
	virtual ~CCommonContext();

};

#endif // !defined(AFX_COMMONCONTEXT_H__E61386B1_EB56_4B6F_BDBE_DE56FB6ED0B4__INCLUDED_)
