// EPGTest03Doc.cpp : implementation of the CEPGTest03Doc class
//

#include "stdafx.h"
#include "EPGTest03.h"

#include "EPGTest03Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "RemoteLogger.h"
static CRemoteLogger logger;
/////////////////////////////////////////////////////////////////////////////
// CEPGTest03Doc

IMPLEMENT_DYNCREATE(CEPGTest03Doc, CDocument)

BEGIN_MESSAGE_MAP(CEPGTest03Doc, CDocument)
	//{{AFX_MSG_MAP(CEPGTest03Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEPGTest03Doc construction/destruction

CEPGTest03Doc::CEPGTest03Doc()
{
	// TODO: add one-time construction code here
	this->getSampleDoc();

}

CEPGTest03Doc::~CEPGTest03Doc()
{
	list<CActivity*>::iterator iter;
	iter = this->activityList.begin();
	while(iter!=this->activityList.end()){
		CActivity *p=(*(iter++));
		if(p)delete p;
	}
	this->activityList.clear();
}

BOOL CEPGTest03Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEPGTest03Doc serialization

void CEPGTest03Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEPGTest03Doc diagnostics

#ifdef _DEBUG
void CEPGTest03Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEPGTest03Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEPGTest03Doc commands

CActivity* CEPGTest03Doc::getCurrentActivity()
{
	return this->currentActivity;
}

CActivity* CEPGTest03Doc::gotoActivity(string activityId)
{
	CActivity* p=this->findActivity(activityId);

	if(NULL!=p){
		this->currentActivity=p;
		//logger.Log(__FILE__,__LINE__,"found activity");

	}else{

		string c=this->getCurrentActivity()->getId();
		logger.Log(activityId.c_str());
		throw  CElementNotFoundException("activity not found");
	}
	
	return p;
}

CActivity * CEPGTest03Doc::findActivity(string activityId)
{
	list<CActivity*>::iterator iter;

	for(iter=this->activityList.begin();iter!=this->activityList.end();iter++)
	{

		if( activityId==(*iter)->getId()){
			return (*iter);
		}	
	}
	return NULL;
}

CActivity * CEPGTest03Doc::procEvent(string event)
{
	logger.Log(__FILE__,__LINE__,event.c_str());
	string action;
	action=this->currentActivity->procEvent(event);
	return this->evalAction(action);	
}

void CEPGTest03Doc::setCurrentAcvitity(CActivity *pAct)
{
	this->currentActivity=pAct;
}

bool CEPGTest03Doc::addActivity(CActivity &activity)
{
	this->activityList.push_back(&activity);
	return true;
}

CActivity * CEPGTest03Doc::evalAction(string actionExpression)
{
	CActivity *ret;
	if(actionExpression.find("action:")==0){
		
		::MessageBox(NULL,"not defined","warn",MB_OK);
		ret = this->getCurrentActivity();

	}else{
		ret = this->gotoActivity(actionExpression);
	}


	return ret;
}

void CEPGTest03Doc::getSampleDoc()
{

	CActivity *pa=NULL;
	pa=new CActivity(string("1"),string("我是1号任务"));
	pa->addAction("1","确认","2");
	pa->addAction("2","取消","3");
	pa->addAction("3","刷新","action: message('love');");
	pa->addAction("4","刷新","4");
	pa->addAction("5","刷新","4");
	this->addActivity(*pa);


	this->setCurrentAcvitity(pa);
	pa=new CActivity("2","我是2号任务");
	pa->addAction("1","返回","1");
	pa->addAction("2","转移","3");

	this->addActivity(*pa);


	pa=new CActivity("3","我是3号任务");
	pa->addAction("1","转移","2");
	pa->addAction("2","返回","1");
	this->addActivity(*pa);

	pa=new CActivity("4","刷新到此");
	pa->addAction("1","转移","2");
	pa->addAction("2","返回","1");
	this->addActivity(*pa);
}
