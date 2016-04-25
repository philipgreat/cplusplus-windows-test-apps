// DemoButton.h: interface for the DemoButton class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMOBUTTON_H__3A5684AB_BFAD_47ED_92C8_C6F5BD813F3E__INCLUDED_)
#define AFX_DEMOBUTTON_H__3A5684AB_BFAD_47ED_92C8_C6F5BD813F3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XMLControl.h"

class DemoButton : public XMLControl  
{

public:
	void destroy();
	void draw(HDC dc, int orgX, int OrgY, int width, int height);
	void focus(HDC dc, int orgX, int OrgY, int width, int height);
	void init();

public:
	DemoButton();
	virtual ~DemoButton();

};

#endif // !defined(AFX_DEMOBUTTON_H__3A5684AB_BFAD_47ED_92C8_C6F5BD813F3E__INCLUDED_)
