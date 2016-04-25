// PowerScreenShot.cpp: implementation of the PowerScreenShot class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PowerScreenShot.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
enum SCREEN_STATE  { INIT=0, FIRST_W=1, FIRST_A=2, FOLLOW_A=3,FOLLOW_W=4,END_S};
PowerScreenShot::PowerScreenShot()
{
	this->currentStat=INIT;
}

PowerScreenShot::~PowerScreenShot()
{

}

static int getNextState(int currentState,int key)
{
	switch(currentState){
	case INIT:
		if(key=='W'){
			return FIRST_W;
		}
		
		if(key=='A'){
			return FIRST_A;
		}


		break;

	default:
		break;
	
	}


}

int PowerScreenShot::onKey(int keyValue)
{
	commandList.push_back(Command::getInstance(keyValue));

	return 0;
}

void PowerScreenShot::clearCommands()
{	
	vector<Command*>::iterator iter;
	for(iter=commandList.begin(); iter != commandList.end(); ++iter)
	{
		delete *iter;
	}
	commandList.clear();
	
	
	
}

void PowerScreenShot::reportCommands()
{
	vector<Command*>::iterator iter;
	for(iter=commandList.begin(); iter != commandList.end(); ++iter)
	{
		(*iter)->show();
		printf("\n");
	}
}

void PowerScreenShot::begin()
{
	this->clearCommands();
}

void PowerScreenShot::commit()
{
	//read from commands, very complex;

	



}

void PowerScreenShot::cancel()
{
	this->clearCommands();
}

void PowerScreenShot::remove()
{
	if(commandList.size()<0)return;	
	delete commandList[commandList.size()-1];	
	commandList.pop_back();
}
