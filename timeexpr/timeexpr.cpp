// timeexpr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
int main(int argc, char* argv[])
{
	printf("Hello World!\n");
	SetSystemEnvironmentVariable("XYZ","我的变量");
	return 0;
}

