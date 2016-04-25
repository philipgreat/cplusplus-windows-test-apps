// LayoutManager.h: interface for the CLayoutManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAYOUTMANAGER_H__A4C0A1EF_E80A_43E2_95A1_08F9F77D36BC__INCLUDED_)
#define AFX_LAYOUTMANAGER_H__A4C0A1EF_E80A_43E2_95A1_08F9F77D36BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLayoutManager  
{
private:
	int orgX;
	int orgY;
	int width;
	int height;
public:
	CLayoutManager();
	CLayoutManager(int orgX,int orgY,int width,int height);
	virtual ~CLayoutManager();

};

#endif // !defined(AFX_LAYOUTMANAGER_H__A4C0A1EF_E80A_43E2_95A1_08F9F77D36BC__INCLUDED_)
