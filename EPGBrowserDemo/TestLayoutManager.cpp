// TestLayoutManager.cpp: implementation of the TestLayoutManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestLayoutManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TestLayoutManager::TestLayoutManager()
{

}

TestLayoutManager::~TestLayoutManager()
{

}

void TestLayoutManager::init(RECT *rect)
{
	currentIndex = 0;
	this->rect = *rect;
}

void TestLayoutManager::getRectByIndex(int index, RECT *rct)
{
	//·Ö³É9·Ý
	int h=index%3;
	int v=(index/3);
	int hr=(this->rect.right-this->rect.left)/3;
	int vr=(this->rect.bottom-this->rect.top)/3;


	rct->left=h*hr;
	rct->right=(h+1)*hr-1;

	rct->top=v*vr;
	rct->bottom=(v+1)*vr;


}
