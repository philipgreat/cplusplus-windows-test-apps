// SelectorItem.h: interface for the CSelectorItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SELECTORITEM_H__EF3990EA_8ABB_4A75_B884_23D3BCF395EC__INCLUDED_)
#define AFX_SELECTORITEM_H__EF3990EA_8ABB_4A75_B884_23D3BCF395EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSelectorItem  
{
public:
	int		index;
	string	describe;
	string	value;
public:
	int getIndex() const;
	string& getValue();
	string& getDescribe();
	CSelectorItem(int index, string describe, string value);
	virtual ~CSelectorItem();

};

#endif // !defined(AFX_SELECTORITEM_H__EF3990EA_8ABB_4A75_B884_23D3BCF395EC__INCLUDED_)
