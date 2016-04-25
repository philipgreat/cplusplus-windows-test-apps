// Activity.cpp: implementation of the CActivity class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Activity.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CActivity::CActivity()
{

}
CActivity::CActivity(string id,string name)
{
	this->id.append(id);
	this->name.append(name);

}
CActivity::~CActivity()
{
	this->inputList.clear();

	list<CAction*>::iterator iter;
	iter = this->actionList.begin();
	while(iter!=this->actionList.end()){
		CAction *p=(*(iter++));
		if(p)delete p;
	}

 	this->actionList.clear();
}

string &CActivity::procEvent(string event)
{
	CAction *p=findAction(event);
	if(NULL!=p){
		return p->getAction();
	}else{
		throw  CElementNotFoundException("action not found");
	}
	//change this to action
}

CAction *CActivity::findAction(string eventName)
{
	//io fact, the algorithm is very complex
	//this code should search the corresponding action in to its parents

	list<CAction*>::iterator iter;
	int i=actionList.size();

	for(iter=this->actionList.begin();iter!=this->actionList.end();iter++)
	{
		if( eventName==(*iter)->getEvent() ){
			return (*iter);
		}
	}

	//if we can't find it , we should continue to search the parent!
	return NULL;
}

bool CActivity::addAction(string event, string name, string action)
{
	CAction *pAction=new CAction(event,name,action);
	this->actionList.push_back(pAction);
	return true;
}

string& CActivity::getName()
{
	return this->name;
}

string& CActivity::getId()
{
	return this->id;
}

char * CActivity::toString()
{
	stringbuffer="";
	stringbuffer.append(this->id);
	stringbuffer.append(":");
	stringbuffer.append(this->name);

	list<CAction*>::iterator iter;
	int i=actionList.size();

	stringbuffer.append("\r\n\r\n");

	for(iter=this->actionList.begin();iter!=this->actionList.end();iter++)
	{
		stringbuffer.append("[");
		stringbuffer.append((*iter)->getEvent());
		stringbuffer.append("/");
		stringbuffer.append((*iter)->getName());
		stringbuffer.append("/");
		stringbuffer.append((*iter)->getAction());
		stringbuffer.append("]");

	}
	return (char*)stringbuffer.c_str();
}

int CActivity::draw(CClientDC &dc, int orgX, int orgY, int width, int height)
{

	list<CAction*>::iterator iter;

	dc.Rectangle(orgX,orgY,width+orgX,height+orgY);

	CString str(this->toString());
	CRect rectName(orgX, 
			orgY+4,
			orgX+width,
			orgY+height+4); 
	
	dc.DrawText(str,&rectName,DT_CENTER|DT_VCENTER);

	int i=1;
	stringbuffer="";


	int size=actionList.size();


	for(iter=this->actionList.begin();iter!=this->actionList.end();iter++)
	{

		stringbuffer="";
		CString buttonText((*iter)->getName().c_str());
		buttonText=buttonText+"("+(*iter)->getEvent().c_str()+")";

		int x0 = (i - 1) * width / size + orgX;
		int x1 =  i * width / size + orgX;

		CRect rectButton(x0 + 5,
			orgY + height - 30 - 4,
			x1 - 5,
			orgY + height - 10 			
			);

		//dc.Rectangle(& rectButton);
		
		CBrush *p=new CBrush();
		p->CreateSolidBrush(RGB(200,200,200));
		dc.FillRect(&rectButton,p);
		delete p;
		//dc.Rectangle(&rectButton);
		dc.DrawFocusRect(&rectButton);
		//dc.DrawFocusRect(&rectButton);

		CRect rectText(x0 + 5, 
			orgY + height - 30,
			x1 - 5,
			orgY + height - 10);

		dc.DrawText(buttonText,&rectText,DT_CENTER);
		//dc.TextOut(orgX+100*i,orgY+100,buttonText);
		i++;
		//stringbuffer.append(iter->getEvent());		
		//stringbuffer.append(iter->getAction());

	}

	return 0;
}
