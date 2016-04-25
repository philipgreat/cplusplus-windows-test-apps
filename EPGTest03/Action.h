// Action.h: interface for the CAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACTION_H__2AE431D9_96A7_4B0F_AA66_AE8C0A64B986__INCLUDED_)
#define AFX_ACTION_H__2AE431D9_96A7_4B0F_AA66_AE8C0A64B986__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using namespace std;

class CAction 
{
private:
	string event;
	string name;
	string action;
public:
	int draw(CClientDC &dc, int orgX, int orgY, int width, int height);
	string& getAction();
	string& getEvent();
	string& getName();
	CAction();
	CAction(string event,string name,string action);
	virtual ~CAction();

};

#endif // !defined(AFX_ACTION_H__2AE431D9_96A7_4B0F_AA66_AE8C0A64B986__INCLUDED_)
