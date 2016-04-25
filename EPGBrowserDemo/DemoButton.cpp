// DemoButton.cpp: implementation of the DemoButton class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DemoButton.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DemoButton::DemoButton()
{

}

DemoButton::~DemoButton()
{

}
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


void DemoButton::init()
{

}

void DemoButton::draw(HDC dc, int OrgX, int OrgY, int width, int height)
{

	::Rectangle(dc,OrgX+1,OrgY+1,OrgX+width-1,OrgY+height-1);
}

void DemoButton::focus(HDC dc, int OrgX, int OrgY, int width, int height)
{

	RECT rect;
	rect.left=OrgX+1;
	rect.top=OrgY+1;
	rect.right=OrgX+width-1;
	rect.bottom=OrgY+height-1;
	//Rectangle(dc,OrgX+1,OrgY+1,OrgX+width-1,OrgY+height-1);
	HBRUSH brush=CreateSolidBrush (RGB(100, 0, 0));;
	FillRect(dc,&rect,brush);
	DeleteObject(brush);
	
	//::Ellipse(dc,OrgX+1,OrgY+1,OrgX+width-1,OrgY+height-1);
	
}
void DemoButton::destroy()
{

}
