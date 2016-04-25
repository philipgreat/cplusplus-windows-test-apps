// LayoutManager.cpp: implementation of the CLayoutManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EPGTest03.h"
#include "LayoutManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//CLayoutManager(int orgX,int orgY,int width,int height);

CLayoutManager::CLayoutManager()
{

}
CLayoutManager::CLayoutManager(int orgX,int orgY,int width,int height)
:orgX(orgX),orgY(orgY),width(width),height(height)
{
	
}

CLayoutManager::~CLayoutManager()
{

}
