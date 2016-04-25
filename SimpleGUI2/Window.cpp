#include "Window.h"
#include <windows.h>
static void WindowDraw(Window *p,HDC dc);
static void WindowOnChar(Window *pw,HDC dc,char ch);
void InitWindow(Window *p,int x,int y,int w, int h)
{
	p->orgX=x;
	p->orgY=y;
	p->width=w;
	p->height=h;
	p->draw=WindowDraw;
	p->onChar=WindowOnChar;
}
static void WindowDraw(Window *pw,HDC dc)
{
	Window *p=(Window*)pw;
	::Rectangle(dc,p->orgX,p->orgY,p->width+p->orgX,p->height+p->orgY);
	RECT rt;
	rt.top=p->orgX+2;
	rt.left=p->orgY;
	rt.right=p->width+p->orgX;
	rt.bottom=p->height+p->orgY;
	DrawText(dc, "´°¿Ú", strlen("´°¿Ú"), &rt, DT_CENTER);
}
static void WindowOnChar(Window *pw,HDC dc,char ch)
{
	Window *p=(Window*)pw;
	RECT rt;
	rt.top=p->orgX+2;
	rt.left=p->orgY;
	rt.right=p->width+p->orgX;
	rt.bottom=p->height+p->orgY;
	DrawText(dc, &ch, 1, &rt, DT_CENTER);
	
}