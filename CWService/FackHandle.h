// FackHandle.h: interface for the CFackHandle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACKHANDLE_H__DCB7013D_9B37_4499_B230_B9642514E16A__INCLUDED_)
#define AFX_FACKHANDLE_H__DCB7013D_9B37_4499_B230_B9642514E16A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FileListHandle.h"

class CFackHandle : public CFileListHandle  
{
public:
	BOOL OnFileName(const WCHAR *fileName);
	BOOL OnFileName(const char* filename);
	void OnEnd();
	void OnStart();
	CFackHandle();
	virtual ~CFackHandle();

};

#endif // !defined(AFX_FACKHANDLE_H__DCB7013D_9B37_4499_B230_B9642514E16A__INCLUDED_)
