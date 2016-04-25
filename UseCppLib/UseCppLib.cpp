// UseCppLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\\cpplib\\cpplib.h"
int main(int argc, char* argv[])
{
	CCPPLib *p=new CCPPLib();
	
	printf("Hello World!%d \n",p->Add(1,0));
	return 0;
}

