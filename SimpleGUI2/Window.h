
#if !defined(WINDOW_HEAD)
#define WINDOW_HEAD
#include <windows.h>
typedef struct window{
	int orgX;
	int orgY;
	int width;
	int height;
	void (*draw)(struct window *p, HDC dc);
	void (*onChar)(struct window *p,HDC dc,char ch);
}Window,*PW;

void InitWindow(Window *p,int x,int y,int w, int h);


#endif // !defined(AFX_SIMPLEGUI2_H__B2B64EFA_7E06_46D2_9687_C5531CBE947B__INCLUDED_)

