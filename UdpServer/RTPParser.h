// RTPParser.h: interface for the CRTPParser class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RTPPARSER_H__3496F959_5481_45F5_B612_6616112BE20B__INCLUDED_)
#define AFX_RTPPARSER_H__3496F959_5481_45F5_B612_6616112BE20B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <windows.h>

class CRTPParser  
{
private:
	unsigned char *header;
	unsigned int bufferlength;
	unsigned char *currentPosition;
public:
	unsigned int readLEDword();
	unsigned int readLEWord();
	unsigned int readLEByte();
	CRTPParser(unsigned char *start, unsigned int length);
	virtual ~CRTPParser();

};

#endif // !defined(AFX_RTPPARSER_H__3496F959_5481_45F5_B612_6616112BE20B__INCLUDED_)
