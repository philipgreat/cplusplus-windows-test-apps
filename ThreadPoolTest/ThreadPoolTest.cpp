// ThreadPoolTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "threadpool.h"
#include "testtask.h"
#include "testtask3.h"
#include <windows.h>
int main(int argc, char* argv[])
{
	Task *tt=new TestTask();
	ThreadPool *tp = new ThreadPool();
	tp->runTask(tt);
	while(1)
	{
		Sleep(1000);
		tt->report();
	}

	delete tp;
	delete tt;
	return 0;
}

