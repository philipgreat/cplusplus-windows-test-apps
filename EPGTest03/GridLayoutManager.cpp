// GridLayoutManager.cpp: implementation of the CGridLayoutManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EPGTest03.h"
#include "GridLayoutManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGridLayoutManager::CGridLayoutManager()
{

}
CGridLayoutManager::CGridLayoutManager(int orgX,int orgY,int width,int height)
:CLayoutManager(orgX, orgY, width, height)
{
	
}
CGridLayoutManager::~CGridLayoutManager()
{

}
