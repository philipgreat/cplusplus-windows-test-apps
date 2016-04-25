// VolatileCertificate.h: interface for the CVolatileCertificate class.
//
//////////////////////////////////////////////////////////////////////
/*===========================================================*\
  �ļ�: VolatileCertificate.h
  ��Ȩ: ��ţ(����)�������޹�˾
  ����: 2005-09-05
  ����: ��ʱ֤�����ʵ�֣���֤�����ҵ����Լ�
  �ο�: CBaseCertificate
  ����: zhangxl@channel.com
  �޶���¼:	
		2006-01-20  lifagen@channel.com ֧����֤

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
