// Action.cpp: implementation of the CAction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EPGTest03.h"
#include "Action.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAction::CAction()
{

}
CAction::CAction(string event,string name,string action)
{
	this->action.append(action);
	this->name.append(name);
	this->event.append(event);

}
CAction::~CAction()
{
	
}

string& CAction::getName()
{
	return this->name;
}

string& CAction::getEvent()
{	
	return this->event;
}

string& CAction::getAction()
{
	return this->action;
}

int CAction::draw(CClientDC &dc, int orgX, int orgY, int width, int height)
{
	return 0;
}
