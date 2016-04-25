// CListSelector.cpp: implementation of the CListSelector class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "InputControlTest.h"
#include "ListSelector.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CListSelector::CListSelector()
{
	focusIndex = 0;
	index = 0;
	itemCount=0;
}

CListSelector::~CListSelector()
{
	
}

void CListSelector::draw(CClientDC &dc, int orgX, int orgY, int width, int height)
{
	
	
	list<CSelectorItem>::iterator iter;
	
	int y0 = orgY;
	int y1 = orgY;
	
	int x0 = orgX;
	int x1 = orgX + width;

	
	//dc.Rectangle(orgX,orgY,orgX + width,orgY + height);
	
	int size=this->itemList.size();

	//dc.LineTo(x1,y1);
	int count=9;
	int start=4;
	int isNeedBreak=FALSE;

	int j=0;

	for(int i= -4 + focusIndex ; 
		i<= 4 + focusIndex;
		i++)
	{

		y0 = orgY + (j)*40;
		y1 = y0 + 40;
		CRect rect2(x0, y0+1, x1, y1);
		dc.Rectangle(&rect2);

		if(i==focusIndex)
		{
			CBrush *p=new CBrush();
			p->CreateSolidBrush(RGB(200,0,000));
			dc.FillRect(&rect2,p);
			dc.SetTextColor(RGB(255,255,255));
			delete p;
		}else{
			dc.SetTextColor(RGB(0,0,0));
		}

		int index = 0;
		if(i<0){
			index = (size*0X100000 + i) % size  ;
		}else{
			index=i % size ;
		}

		CString str(itemList[ index  ].getValue().c_str());		
		dc.DrawText(str,&rect2,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		j++;
	
	}	
	
}


void CListSelector::addItem(CSelectorItem &item)
{
	itemList.push_back(item);
	itemCount=itemList.size();
}

void CListSelector::addItem(string name, string value)
{
	CSelectorItem *pItem=new CSelectorItem(index,name,value);
	itemList.push_back(*pItem);
	itemCount=itemList.size();
	index++;
}


CListSelector* CListSelector::getSampleSelector()
{
	static CListSelector *pSelector=NULL;
	
	if(pSelector==NULL){
		
		pSelector = new CListSelector();
#if 1		
		pSelector->addItem("name","中央电视台-1");
		pSelector->addItem("name","中央电视台-2");
		pSelector->addItem("name","中央电视台-3");
		pSelector->addItem("name","中央电视台-4");
		pSelector->addItem("name","中央电视台-5");
		pSelector->addItem("name","中央电视台-6");
		pSelector->addItem("name","中央电视台-7");
		pSelector->addItem("name","中央电视台-8");
		pSelector->addItem("name","中央电视台-9");
		pSelector->addItem("name","中央电视台10");
		pSelector->addItem("name","中央电视台11");
		pSelector->addItem("name","中央电视台12");
		pSelector->addItem("name","中央电视台13");
		pSelector->addItem("name","中央电视台14");
		pSelector->addItem("name","中央电视台15");
		pSelector->addItem("name","中央电视台16");
		pSelector->addItem("name","中央电视台17");
#else
		pSelector->addItem("name","8元/次");
		pSelector->addItem("name","1元/天");
		pSelector->addItem("name","4元包月");
#endif
	}
	return pSelector;
}

void CListSelector::focusNext()
{
	focusIndex--;
	index = (itemCount*0X100000 + focusIndex) % itemCount  ;
	this->value = itemList[ index  ].getValue();
	
}

void CListSelector::focusPrev()
{
	focusIndex++;
	index = (itemCount*0X100000 + focusIndex) % itemCount  ;
	this->value = itemList[ index  ].getValue();
	
}

int CListSelector::getItemCount()
{
	return this->itemCount;
}
