// NamedObject.h: interface for the CNamedObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NAMEDOBJECT_H__859B02C9_CC22_4715_9049_EA786BA9FD5A__INCLUDED_)
#define AFX_NAMEDOBJECT_H__859B02C9_CC22_4715_9049_EA786BA9FD5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <string>
using namespace std;
class CNamedObject  
{
private:
	string name;
	string describe;
public:
	virtual string& toString(){ return describe;};
	virtual CNamedObject *clone(){ return new CNamedObject();};
	CNamedObject();
	virtual ~CNamedObject();

};

#endif // !defined(AFX_NAMEDOBJECT_H__859B02C9_CC22_4715_9049_EA786BA9FD5A__INCLUDED_)
