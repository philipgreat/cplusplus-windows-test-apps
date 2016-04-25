// MainWindows.h: interface for the MainWindows class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINWINDOWS_H__4C5F602B_8C25_41AF_8EB5_E34E9C0BB111__INCLUDED_)
#define AFX_MAINWINDOWS_H__4C5F602B_8C25_41AF_8EB5_E34E9C0BB111__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XMLControl.h"

class MainWindows : public XMLControl  
{
private:
	char describe[1024];
	int selected ;
public:
	char * toString();
	void onKey(int key);
	void destroy();
	void draw(HDC dc, int orgX=0, int OrgY=0, int width=400, int height=300);
	void init();
	MainWindows();
	virtual ~MainWindows();

};

#endif // !defined(AFX_MAINWINDOWS_H__4C5F602B_8C25_41AF_8EB5_E34E9C0BB111__INCLUDED_)
