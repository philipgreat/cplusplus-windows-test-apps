// FackHandle.cpp: implementation of the CFackHandle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FackHandle.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFackHandle::CFackHandle()
{

}

CFackHandle::~CFackHandle()
{

}

void CFackHandle::OnStart()
{

}

void CFackHandle::OnEnd()
{

}

BOOL CFackHandle::OnFileName(const char *filename)
{
	printf("this is a bad thing");
	return TRUE;
	//return 
}

BOOL CFackHandle::OnFileName(const WCHAR *fileName)
{
	wprintf(L"this is a bad OnFileName: %s\n",fileName);
	return TRUE;
	
}
