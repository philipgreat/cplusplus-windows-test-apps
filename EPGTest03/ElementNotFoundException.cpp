// ElementNotFoundException.cpp: implementation of the CElementNotFoundException class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EPGTest03.h"
#include "ElementNotFoundException.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CElementNotFoundException::CElementNotFoundException()
{

}

CElementNotFoundException::CElementNotFoundException(char *message)
{
	strncpy(this->message,message,1024-1);

}
CElementNotFoundException::~CElementNotFoundException()
{

}

char * CElementNotFoundException::getMessage()
{
	return message;
}
