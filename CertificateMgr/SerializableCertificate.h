// SerializableCertificate.h: interface for the CSerializableCertificate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERIALIZABLECERTIFICATE_H__E9E1767C_8659_4B65_9D9D_FBF84944EEAE__INCLUDED_)
#define AFX_SERIALIZABLECERTIFICATE_H__E9E1767C_8659_4B65_9D9D_FBF84944EEAE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "BaseCertificate.h"
class CSerializableCertificate : public CBaseCertificate 
{
public:
	BOOL Store();
	CSerializableCertificate();
	virtual ~CSerializableCertificate();

};

#endif // !defined(AFX_SERIALIZABLECERTIFICATE_H__E9E1767C_8659_4B65_9D9D_FBF84944EEAE__INCLUDED_)
