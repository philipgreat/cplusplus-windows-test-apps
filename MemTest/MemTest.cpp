// MemTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <crtdbg.h>

inline void EnableMemLeakCheck()
{
   _CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
}

#ifdef _DEBUG
#define new   new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
int main(int argc, char* argv[])
{
	EnableMemLeakCheck();
	char *c=new char[10];
	int* leak = new int[10];
	printf("Hello World!\n");
	return 0;
}

