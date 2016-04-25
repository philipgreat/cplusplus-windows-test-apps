// Activity.h: interface for the CActivity class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACTIVITY_H__CDD49499_D567_4D90_BC2E_5DA53D3EF769__INCLUDED_)
#define AFX_ACTIVITY_H__CDD49499_D567_4D90_BC2E_5DA53D3EF769__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <list>
#include "activity.h"
#include "input.h"
#include "action.h"
#include "ElementNotFoundException.h"

class CActivity  
{
private:
	string stringbuffer;
private:
	string id;
	string name;
	string extendsActivity;
	string layout;
private:
	list<CInput>inputList;
	list<CAction*>actionList;
public:
	int draw(CClientDC &dc, int orgX,int orgY, int width, int height);
	char * toString();
	string& getId();
	string& getName();
	bool addAction(string event,string name,string action);
	string &procEvent(string event);
	CActivity();
	CActivity(string id,string name);
	virtual ~CActivity();
protected:
	CAction *findAction(string eventName);
};

#endif // !defined(AFX_ACTIVITY_H__CDD49499_D567_4D90_BC2E_5DA53D3EF769__INCLUDED_)
