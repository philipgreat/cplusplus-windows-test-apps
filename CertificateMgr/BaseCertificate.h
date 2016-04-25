// BaseCertificate.h: interface for the CBaseCertificate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASECERTIFICATE_H__4E6F5207_92B3_4ED5_829B_490C3A349EC8__INCLUDED_)
#define AFX_BASECERTIFICATE_H__4E6F5207_92B3_4ED5_829B_490C3A349EC8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <windows.h>
class CBaseCertificate  
{
protected:
	DWORD cwId;
	DWORD cw;
	DWORD streamId;
	DWORD issueDate;
public:
	virtual char*  ToString();
	virtual BOOL Store() = 0 ;
	DWORD GetCWId();
	DWORD GetCW();
	CBaseCertificate();
	CBaseCertificate(DWORD id, DWORD content);
	virtual ~CBaseCertificate();

};

#endif // !defined(AFX_BASECERTIFICATE_H__4E6F5207_92B3_4ED5_829B_490C3A349EC8__INCLUDED_)
