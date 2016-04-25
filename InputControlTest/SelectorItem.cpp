// SelectorItem.cpp: implementation of the CSelectorItem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "InputControlTest.h"
#include "SelectorItem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSelectorItem::CSelectorItem(int index, string describe, string value)
{
	this->index=index;
	this->describe.append(describe);
	this->value.append(value);
}

CSelectorItem::~CSelectorItem()
{

}

string& CSelectorItem::getDescribe()
{
	return this->describe;
}

string& CSelectorItem::getValue()
{
	return this->value;
}

int CSelectorItem::getIndex()  const
{
	return this->index;
}
