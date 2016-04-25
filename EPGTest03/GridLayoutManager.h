// GridLayoutManager.h: interface for the CGridLayoutManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRIDLAYOUTMANAGER_H__DA5AB5E2_E910_46BD_8C1F_D6333E3DBD2A__INCLUDED_)
#define AFX_GRIDLAYOUTMANAGER_H__DA5AB5E2_E910_46BD_8C1F_D6333E3DBD2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LayoutManager.h"

class CGridLayoutManager : public CLayoutManager  
{
public:
	CGridLayoutManager(int orgX,int orgY,int width,int height);
	CGridLayoutManager();
	virtual ~CGridLayoutManager();

};

#endif // !defined(AFX_GRIDLAYOUTMANAGER_H__DA5AB5E2_E910_46BD_8C1F_D6333E3DBD2A__INCLUDED_)
