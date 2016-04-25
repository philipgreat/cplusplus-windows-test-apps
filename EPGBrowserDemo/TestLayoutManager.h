// TestLayoutManager.h: interface for the TestLayoutManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTLAYOUTMANAGER_H__DAED61A2_FB5B_4041_A193_36394732C4D4__INCLUDED_)
#define AFX_TESTLAYOUTMANAGER_H__DAED61A2_FB5B_4041_A193_36394732C4D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class TestLayoutManager  
{
private:
	RECT rect;
	int currentIndex;
public:
	//void init(RECT rect);
	//void getRectByIndex(int index,RECT *rect);

public:
	void getRectByIndex(int index,RECT *rect);
	void init(RECT *rect);
	TestLayoutManager();
	virtual ~TestLayoutManager();

};

#endif // !defined(AFX_TESTLAYOUTMANAGER_H__DAED61A2_FB5B_4041_A193_36394732C4D4__INCLUDED_)
