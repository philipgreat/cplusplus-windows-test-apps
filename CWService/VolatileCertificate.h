// VolatileCertificate.h: interface for the CVolatileCertificate class.
//
//////////////////////////////////////////////////////////////////////
/*===========================================================*\
  文件: VolatileCertificate.h
  版权: 青牛(北京)技术有限公司
  日期: 2005-09-05
  描述: 临时证书类的实现，该证书类的业务相对简单
  参考: CBaseCertificate
  作者: zhangxl@channel.com
  修订记录:	
		2006-01-20  lifagen@channel.com 支持认证

\*===========================================================*/
#if !defined(AFX_VOLATILECERTIFICATE_H__D14CB9F3_15E4_4483_AA51_8AC703013C7E__INCLUDED_)
#define AFX_VOLATILECERTIFICATE_H__D14CB9F3_15E4_4483_AA51_8AC703013C7E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "BaseCertificate.h"

class CVolatileCertificate : public CBaseCertificate
{
public:
	void UpdateState();
	void Report();
	BOOL Store();
	CVolatileCertificate();
	virtual ~CVolatileCertificate();
};

#endif // !defined(AFX_VOLATILECERTIFICATE_H__D14CB9F3_15E4_4483_AA51_8AC703013C7E__INCLUDED_)
