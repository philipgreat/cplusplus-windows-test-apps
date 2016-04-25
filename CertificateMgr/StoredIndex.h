// StoredIndex.h: interface for the CStoredIndex class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOREDINDEX_H__9A46C5EF_2B02_4821_8CA4_E87F463DFECA__INCLUDED_)
#define AFX_STOREDINDEX_H__9A46C5EF_2B02_4821_8CA4_E87F463DFECA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <windows.h>
struct IndexItem
{
	DWORD fileId;
	char  friendName[16];
	DWORD time;// start from 1970
	DWORD startAddress;//offset 
	DWORD length;//length of the store
	DWORD state;
};

class CStoredIndex  
{

public:
	CStoredIndex();
	virtual ~CStoredIndex();

};

#endif // !defined(AFX_STOREDINDEX_H__9A46C5EF_2B02_4821_8CA4_E87F463DFECA__INCLUDED_)
