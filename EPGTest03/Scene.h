// Scene.h: interface for the CScene class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCENE_H__EAAD8464_9AE6_4FD5_BA38_E7C4EDB1BFA0__INCLUDED_)
#define AFX_SCENE_H__EAAD8464_9AE6_4FD5_BA38_E7C4EDB1BFA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Activity.h"

class CScene  
{
private:
	list<CActivity> activityList;
	CActivity *currentActivity;
public:
	CScene();
	virtual ~CScene();
public:
	bool addActivity(CActivity &activity);
	void setCurrentAcvitity(CActivity *pAct);
	CActivity * procEvent(string event);
	CActivity * findActivity(string activityId);
	CActivity* gotoActivity(string name);
	CActivity* getCurrentActivity();
};

#endif // !defined(AFX_SCENE_H__EAAD8464_9AE6_4FD5_BA38_E7C4EDB1BFA0__INCLUDED_)
