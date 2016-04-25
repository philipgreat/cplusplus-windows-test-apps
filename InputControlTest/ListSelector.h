// ListSelector.h: interface for the ListSelector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTSELECTOR_H__CBC67F3F_5A4D_458E_9761_2F57518B8E1C__INCLUDED_)
#define AFX_LISTSELECTOR_H__CBC67F3F_5A4D_458E_9761_2F57518B8E1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SelectorItem.h"
class CListSelector  
{
private:
	int itemCount;
	int focusIndex;
	vector<CSelectorItem>itemList;
	int index;
	string value;
public:
	int getItemCount();
	void focusPrev();
	void focusNext();
	static CListSelector* getSampleSelector();
	void addItem(string name,string value);
	void addItem(CSelectorItem &item);
	void draw(CClientDC &dc,int orgX, int orgY, int width, int height);
	CListSelector();	
	virtual ~CListSelector();

};

#endif // !defined(AFX_LISTSELECTOR_H__CBC67F3F_5A4D_458E_9761_2F57518B8E1C__INCLUDED_)
