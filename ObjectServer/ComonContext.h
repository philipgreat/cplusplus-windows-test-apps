// ComonContext.h: interface for the CComonContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMONCONTEXT_H__22756F69_DFC7_4359_A17D_B6858AEDD678__INCLUDED_)
#define AFX_COMONCONTEXT_H__22756F69_DFC7_4359_A17D_B6858AEDD678__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CComonContext  
{
public:
	virtual char* GetEnvValue(const char *name)=0;
	CComonContext();
	virtual ~CComonContext();

};

#endif // !defined(AFX_COMONCONTEXT_H__22756F69_DFC7_4359_A17D_B6858AEDD678__INCLUDED_)
