// VolatileCertificate.h: interface for the CVolatileCertificate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VOLATILECERTIFICATE_H__D14CB9F3_15E4_4483_AA51_8AC703013C7E__INCLUDED_)
#define AFX_VOLATILECERTIFICATE_H__D14CB9F3_15E4_4483_AA51_8AC703013C7E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "BaseCertificate.h"
class CVolatileCertificate : public CBaseCertificate
{
public:
	BOOL Store();
	CVolatileCertificate();
	CVolatileCertificate(DWORD cwid,DWORD cw);
	virtual ~CVolatileCertificate();

};

#endif // !defined(AFX_VOLATILECERTIFICATE_H__D14CB9F3_15E4_4483_AA51_8AC703013C7E__INCLUDED_)
