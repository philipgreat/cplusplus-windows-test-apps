// XMLControl.h: interface for the XMLControl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XMLCONTROL_H__295502B9_F13C_410B_80E3_2AE3F2D1B56E__INCLUDED_)
#define AFX_XMLCONTROL_H__295502B9_F13C_410B_80E3_2AE3F2D1B56E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class XMLControl  
{
private:
	int orgX;
	int orgY;
	int width;
	int height;
public:
	virtual void init() = 0;
	virtual void destroy() = 0;
	virtual void draw(HDC dc, int orgX=0, int OrgY=0, int width=400, int height=300) = 0;
public:
	XMLControl();
	virtual ~XMLControl();

};

#endif // !defined(AFX_XMLCONTROL_H__295502B9_F13C_410B_80E3_2AE3F2D1B56E__INCLUDED_)
