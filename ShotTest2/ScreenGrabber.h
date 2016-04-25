// ScreenGrabber.h: interface for the CScreenGrabber class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCREENGRABBER_H__DFD2267A_4756_4099_94B8_84BD1F2120B8__INCLUDED_)
#define AFX_SCREENGRABBER_H__DFD2267A_4756_4099_94B8_84BD1F2120B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CScreenGrabber  
{

private:
	ULONG_PTR gdiplusToken;
	char path[MAX_PATH];
	char prefix[MAX_PATH];
public:
	BOOL MakeActiveSnapshot();
	BOOL MakeSnapshot();
	char *GetFilePath();
	//void clearPathEndSlash(char *path);
	void LoadConfiguration();
	CScreenGrabber();
	virtual ~CScreenGrabber();

};

#endif // !defined(AFX_SCREENGRABBER_H__DFD2267A_4756_4099_94B8_84BD1F2120B8__INCLUDED_)
