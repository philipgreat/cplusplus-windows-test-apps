// ElementNotFoundException.h: interface for the CElementNotFoundException class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELEMENTNOTFOUNDEXCEPTION_H__2038CAE4_5BC6_4BF4_B2B2_9A0CE3BA6CC9__INCLUDED_)
#define AFX_ELEMENTNOTFOUNDEXCEPTION_H__2038CAE4_5BC6_4BF4_B2B2_9A0CE3BA6CC9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CElementNotFoundException  
{
private:
	char message[1024];
public:
	char * getMessage();
	CElementNotFoundException();
	CElementNotFoundException(char *msg);
	virtual ~CElementNotFoundException();

};

#endif // !defined(AFX_ELEMENTNOTFOUNDEXCEPTION_H__2038CAE4_5BC6_4BF4_B2B2_9A0CE3BA6CC9__INCLUDED_)
