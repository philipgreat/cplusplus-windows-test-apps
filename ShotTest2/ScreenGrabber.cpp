// ScreenGrabber.cpp: implementation of the CScreenGrabber class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ScreenGrabber.h"
#include <objbase.h>
#include <initguid.h>
#include <gdiplus.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#pragma comment(lib,"gdiplus")
using namespace Gdiplus;
CScreenGrabber::CScreenGrabber()
{
	//::MessageBoxA(NULL,"1","STEP",MB_OK);
	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	LoadConfiguration();
}

CScreenGrabber::~CScreenGrabber()
{
	GdiplusShutdown(gdiplusToken);
}
#include <stdio.h>
static int  replaceLastChars(const char *buffer, int length, const char *last)
{
	int replaceLength=strlen(last);
	if(replaceLength>=length){
		return -1;
	}
	char *p=(char*)(buffer+length-replaceLength);
	char *replace=(char*)last;
	for(int i=0;i<replaceLength;i++){		
		*p=	*replace;
		p++;
		replace++;
	}
	return 0;
}
static void clearPathEndSlash(char* path)
 {
	 char *p=path+strlen(path)-1;
	 //points the end of the string
	 while(*p=='\\'){	 
		*p=0;
		p--;	 
	 }
 }

void CScreenGrabber::LoadConfiguration()
{
	//char *pchToolHome=::getenv("TOOL_HOME");
	//char buffer[MAX_PATH];
	
	char modulePath[MAX_PATH];
	::GetModuleFileNameA(NULL,modulePath,MAX_PATH);
	//sprintf(buffer,"%s\\%s",pchToolHome,"\\config.ini");
	replaceLastChars(modulePath,strlen(modulePath),"ini");
	::GetPrivateProfileString("grabber","fileprefix","snap",this->prefix,MAX_PATH,modulePath);
	::GetPrivateProfileString("grabber","path","C:\\temp",this->path,MAX_PATH,modulePath);
	clearPathEndSlash(this->path);
	
}



static int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT  num = 10;          // number of image encoders
	UINT  size = 100;         // size of the image encoder array in bytes
	
	ImageCodecInfo* pImageCodecInfo = NULL;
	
	GetImageEncodersSize(&num, &size);
	
	if(size == 0)
		return -1;  // Failure
	
	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if(pImageCodecInfo == NULL)
		return -1;  // Failure
	
	GetImageEncoders(num, size, pImageCodecInfo);
	
	for(UINT j = 0; j < num; ++j)
	{
		if( wcscmp(pImageCodecInfo[j].MimeType, format) == 0 )
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;  // Success
		}    
	}
	
	free(pImageCodecInfo);
	return -1;  // Failure
}
#include <stdio.h>
#define A2W(W,A)     MultiByteToWideChar(936,0,(A),strlen((A))+1,(W),strlen((A))+1)
static void movePoint(POINT *pt,int num,int x, int y)
{
	
	if(num<1) return;
	for(int i=0;i<num;i++){
		(pt+i)->x+=x;
		(pt+i)->y+=y;

	}

}
static BOOL saveFilePathToClipboard(const WCHAR*filePath)
{
	if (!OpenClipboard(NULL)) 
        return FALSE; 
    EmptyClipboard(); 
	HGLOBAL hglbCopy = GlobalAlloc(GMEM_MOVEABLE,(wcslen(filePath) + 1) * sizeof(WCHAR)); 
    if (hglbCopy == NULL) 
    { 
		CloseClipboard(); 
        return FALSE; 
    } 
	void *lptstrCopy = GlobalLock(hglbCopy); 
    memcpy(lptstrCopy, filePath,(wcslen(filePath) + 1) * sizeof(WCHAR));     
    GlobalUnlock(hglbCopy);  
    // Place the handle on the clipboard.  
    SetClipboardData(CF_TEXT, hglbCopy); 
	::CloseClipboard();
	return TRUE;
}

static BOOL saveFilePathToClipboard(const char*filePath)
{
	if (!OpenClipboard(NULL)) 
        return FALSE; 
    EmptyClipboard(); 
	HGLOBAL hglbCopy = GlobalAlloc(GMEM_MOVEABLE,(strlen(filePath) + 1) * sizeof(char)); 
    if (hglbCopy == NULL) 
    { 
		CloseClipboard(); 
        return FALSE; 
    } 
	void *lptstrCopy = GlobalLock(hglbCopy); 
    memcpy(lptstrCopy, filePath,(strlen(filePath) + 1) * sizeof(char));     
    GlobalUnlock(hglbCopy);  
    // Place the handle on the clipboard.  
    SetClipboardData(CF_TEXT, hglbCopy); 
	::CloseClipboard();
	return TRUE;
}



static BOOL makeSnapshot(char *filePath,RECT *rect)
{
	HDC MemoryDC;
	HBITMAP hBitmap;
	POINT  point;
	
	HDC screenDC ;

	screenDC = CreateDC("DISPLAY", NULL, NULL, NULL);
	::GetCursorPos(&point);

	hBitmap = CreateCompatibleBitmap(screenDC,
		rect->right-rect->left,
		rect->bottom-rect->top);
	MemoryDC = CreateCompatibleDC(screenDC);
	HBRUSH brush = CreateSolidBrush(RGB(128,0,0));
	HPEN pen=::CreatePen(1,2,RGB(255,0,0));


	SelectObject(MemoryDC, hBitmap);
	::SelectObject(MemoryDC,brush);
	::SelectObject(MemoryDC,pen);
	BitBlt(MemoryDC, 0, 0, 
		rect->right-rect->left,
		rect->bottom-rect->top,
		//GetDeviceCaps(ScreenDC, HORZRES), 
		//GetDeviceCaps(ScreenDC, VERTRES), 
		screenDC, rect->left, rect->top, SRCCOPY);
	::SetBkMode(MemoryDC,TRANSPARENT);
	//::Ellipse(MemoryDC,	point.x-rect->left-10,point.y-rect->top-10,	point.x-rect->left+10,point.y-rect->top+10);
	POINT pt[4];
	pt[0].x=point.x;
	pt[0].y=point.y;
	pt[1].x=point.x+20;
	pt[1].y=point.y+20;
	pt[2].x=point.x;
	pt[2].y=point.y+28;
	pt[3].x=point.x;
	pt[3].y=point.y;
	movePoint(pt,4,-rect->left,-rect->top);
	
	::Polyline(MemoryDC, pt,4);

	//::Ellipse(
    Bitmap bitmap(hBitmap, DIB_RGB_COLORS);
	CLSID   encoderClsid;
	Status  stat;	
	// Get the CLSID of the PNG encoder.
	//GetEncoderClsid(L"image/jpeg", &encoderClsid);
	//stat=bitmap.Save(L"f:\\newImage.jpg",&encoderClsid,NULL);
	GetEncoderClsid(L"image/png", &encoderClsid);

	SYSTEMTIME time;
	::GetLocalTime(&time);
	WCHAR wfilePath[MAX_PATH];

	A2W(wfilePath,filePath);
	::DeleteObject(brush);
	//::MessageBoxW(NULL,wfilePath,wfilePath,MB_OK);
	::DeleteObject(hBitmap);
	::DeleteObject(screenDC);
	::DeleteObject(MemoryDC);
	::DeleteObject(pen);
	stat=bitmap.Save(wfilePath,&encoderClsid,NULL);
	//delete newImage;
	saveFilePathToClipboard(filePath);
	return TRUE;
}
char* CScreenGrabber::GetFilePath(){
	return this->path;;

}
BOOL CScreenGrabber::MakeSnapshot()
{
	HDC screenDC;

	char filePath[MAX_PATH];

	SYSTEMTIME time;
	::GetLocalTime(&time);
	sprintf(filePath,"%s\\%s_%04u_%02u_%02uT%02u_%02u_%02u_%04u.png",
		this->path,
		this->prefix,
		time.wYear,time.wMonth,time.wDay,time.wHour,time.wMinute,time.wSecond,time.wMilliseconds);

	screenDC = CreateDC("DISPLAY", NULL, NULL, NULL);
	RECT rect;
	rect.left = rect.top = 0;
    rect.right = GetDeviceCaps(screenDC, HORZRES);
    rect.bottom = GetDeviceCaps(screenDC, VERTRES);

	makeSnapshot(filePath,&rect);


	DeleteDC(screenDC);
	return TRUE;
}


BOOL CScreenGrabber::MakeActiveSnapshot()
{

	HWND hWndSelect = GetForegroundWindow();
	//ScreenDC;
	

	char filePath[MAX_PATH];

	SYSTEMTIME time;
	::GetLocalTime(&time);
	sprintf(filePath,"%s\\%s_%04u_%02u_%02uT%02u_%02u_%02u_%04u.png",
		this->path,
		this->prefix,
		time.wYear,time.wMonth,time.wDay,time.wHour,time.wMinute,time.wSecond,time.wMilliseconds);


	RECT rect;
	GetWindowRect(hWndSelect,&rect);

	
	makeSnapshot(filePath,&rect);
	


	return TRUE;
}













#if 0 
	HANDLE hFile;
	BITMAPINFO bmi;
	BITMAPINFOHEADER bm;
	BITMAPFILEHEADER hdr;
	LPBYTE lpBits;
	DWORD dwTemp;


	bm.biSize = sizeof (BITMAPINFOHEADER);
	bm.biWidth = GetDeviceCaps(MemoryDC, HORZRES);
	bm.biHeight = GetDeviceCaps(MemoryDC, VERTRES);
	bm.biPlanes = 1;
	bm.biBitCount = GetDeviceCaps(MemoryDC, BITSPIXEL);
	bm.biCompression = BI_RGB;
	bm.biSizeImage = 0;
	bm.biXPelsPerMeter = 0;
	bm.biYPelsPerMeter = 0;
	bm.biClrUsed = 0;
	bm.biClrImportant = 0;
	bmi.bmiHeader = bm;
	//    bmi.bmiColors[0] = NULL;
	lpBits = (LPBYTE) GlobalAlloc(GMEM_FIXED, bm.biWidth * bm.biHeight * (bm.biBitCount / 8));
	GetDIBits(MemoryDC, hBitmap, 0, (WORD) bm.biHeight, lpBits, &bmi, DIB_RGB_COLORS);
	hFile = CreateFile("c:/captured.bmp", GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	hdr.bfType = 0x4d42;
	hdr.bfSize = (DWORD) sizeof (BITMAPFILEHEADER) + sizeof (BITMAPINFOHEADER) + bm.biWidth * bm.biHeight * (bm.biBitCount / 8);
	hdr.bfReserved1 = 0;
	hdr.bfReserved2 = 0;
	hdr.bfOffBits = (DWORD) sizeof (BITMAPFILEHEADER) + sizeof (BITMAPINFOHEADER);
	WriteFile(hFile, (LPVOID) &hdr, sizeof (BITMAPFILEHEADER), (LPDWORD) &dwTemp, NULL);
	WriteFile(hFile, (LPVOID) &bm, sizeof (BITMAPINFOHEADER), (LPDWORD) &dwTemp, NULL);
	WriteFile(hFile, (LPVOID) lpBits, bm.biWidth * bm.biHeight * (bm.biBitCount / 8), (LPDWORD) &dwTemp, NULL);
	CloseHandle(hFile);
#endif


#if 0 
	hBitmap = CreateCompatibleBitmap(ScreenDC, GetDeviceCaps(ScreenDC, HORZRES), GetDeviceCaps(ScreenDC, VERTRES));
	MemoryDC = CreateCompatibleDC(ScreenDC);
	SelectObject(MemoryDC, hBitmap);
	BitBlt(MemoryDC, 0, 0, GetDeviceCaps(ScreenDC, HORZRES), GetDeviceCaps(ScreenDC, VERTRES), ScreenDC, 0, 0, SRCCOPY);

    Bitmap bitmap(hBitmap, DIB_RGB_COLORS);
	CLSID   encoderClsid;
	Status  stat;	
	// Get the CLSID of the PNG encoder.
	//GetEncoderClsid(L"image/jpeg", &encoderClsid);
	//stat=bitmap.Save(L"f:\\newImage.jpg",&encoderClsid,NULL);
	GetEncoderClsid(L"image/jpg", &encoderClsid);

	A2W(wfilePath,filePath);

	stat=bitmap.Save(wfilePath,&encoderClsid,NULL);
	//delete newImage;
#endif	