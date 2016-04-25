// HaspKey.h: interface for the HaspKey class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HASPKEY_H__522A6A69_67EB_44F1_9F61_ADA7CC1A23C2__INCLUDED_)
#define AFX_HASPKEY_H__522A6A69_67EB_44F1_9F61_ADA7CC1A23C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class HaspKey  
{
private:
	int portNumber;
	int password1;
	int password2;

public:
	int write(const char *buffer, int length);
	int read(char *buffer, int length);
	long getHaspId();
	void login(int password1,int password2);
	bool isHasp();
	HaspKey();
	virtual ~HaspKey();

};

#endif // !defined(AFX_HASPKEY_H__522A6A69_67EB_44F1_9F61_ADA7CC1A23C2__INCLUDED_)
