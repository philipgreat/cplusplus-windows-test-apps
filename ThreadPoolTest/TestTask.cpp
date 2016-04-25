// TestTask.cpp: implementation of the TestTask class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestTask.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TestTask::TestTask()
{
	counter = 0;
}

TestTask::~TestTask()
{

}

void TestTask::execute()
{
	printf("execute the task\n");
	while(1){	
		counter++;
		//250 mil a second
	}
	//while(1){;}
}

void TestTask::report()
{
	printf("%d\n",counter);
}
