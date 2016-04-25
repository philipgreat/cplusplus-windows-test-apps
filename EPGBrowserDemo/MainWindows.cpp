// MainWindows.cpp: implementation of the MainWindows class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainWindows.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#include "RemoteLogger.h"
CRemoteLogger logger;
MainWindows::MainWindows()
{
	selected = 0;
}

MainWindows::~MainWindows()
{

}

void MainWindows::init()
{

}
#include "DemoButton.h"
#include "testlayoutmanager.h"
#include <stdio.h>
#include <stdlib.h>

void MainWindows::draw(HDC dc, int OrgX, int OrgY, int width, int height)
{
	RECT rect;
	rect.left=OrgX;
	rect.top=OrgY+1;
	rect.right=OrgX+width;
	rect.bottom=OrgY+height;

	TestLayoutManager layout;
	layout.init(&rect);

	//::Rectangle(dc,OrgX+1,OrgY+1,OrgX+width-1,OrgY+height-1);
	DemoButton button;
	char text[100];
	sprintf(text,"%d",selected);
	//::MessageBox(NULL,text,"TEXT",MB_OK);
	for(int i=0;i<9;i++)
	{
		layout.getRectByIndex(i,&rect);
		if(i!=selected){
			button.draw(dc,rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top);
		}else{
			button.focus(dc,rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top);
		}
	}



}

void MainWindows::destroy()
{

}
void MainWindows::onKey(int key)
{
	int c= selected;
	logger.Log(__FILE__,__LINE__,key);
	selected =c%9;

	switch (key) { 
	case VK_LEFT:
		if(selected>0) selected--;
		break;
	case VK_RIGHT:
		if(selected<8) selected++;
		break;
	case VK_UP:
		if(selected>=3) selected-=3;
		break;
	case VK_DOWN:
		if(selected<=5) selected+=3;
		break;
	default:
		break;
	}
	if(key>=0x61&&key<=0x69)
	{
		selected = key - 0x61;
	}
	if(key>=0x31&&key<=0x39)
	{
		selected = key - 0x31;
	}

}

char * MainWindows::toString()
{
	sprintf(describe,"selected %d",selected);
	return this->describe;
}
