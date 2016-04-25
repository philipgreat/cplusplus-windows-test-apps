// Scene.cpp: implementation of the CScene class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EPGTest03.h"
#include "Scene.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#include "RemoteLogger.h"
static CRemoteLogger logger;
CScene::CScene()
{

}

CScene::~CScene()
{

}

CActivity* CScene::getCurrentActivity()
{
	return this->currentActivity;
}

CActivity* CScene::gotoActivity(string activityId)
{
	CActivity* p=this->findActivity(activityId);

	if(NULL!=p){
		this->currentActivity=p;
		logger.Log(__FILE__,__LINE__,"found activity");
		logger.Log(__FILE__,__LINE__,p->getId().c_str());
	}else{
		throw  CElementNotFoundException("activity not found");
	}
	
	return p;
}

CActivity * CScene::findActivity(string activityId)
{
	list<CActivity>::iterator iter;

	for(iter=this->activityList.begin();iter!=this->activityList.end();iter++)
	{
		if( activityId==iter->getId() ){
			return &(*iter);
		}		
	}
	return NULL;
}

CActivity * CScene::procEvent(string event)
{
	logger.Log(__FILE__,__LINE__,event.c_str());
	string postActivity;
	postActivity=this->currentActivity->procEvent(event);
	return this->gotoActivity(postActivity);	

}

void CScene::setCurrentAcvitity(CActivity *pAct)
{
	this->currentActivity=pAct;

}
bool CScene::addActivity(CActivity &activity)
{
	this->activityList.push_back(activity);
	return true;
}
