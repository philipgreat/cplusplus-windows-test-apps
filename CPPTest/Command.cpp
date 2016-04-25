// Command.cpp: implementation of the Command class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Command.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Command::Command()
{

}
Command::Command(char command)
{
	this->cmd=command;
	POINT  point;
	::GetCursorPos(&point);
	this->x=point.x;
	this->y=point.y;

}

Command::~Command()
{
	
}



Command* Command::getInstance(char cmd)
{
	
	return new Command(cmd);


}

void Command::show()
{
	printf("%c: %d, %d", this->cmd,this->x,this->y);
}
