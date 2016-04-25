// BufferReader.h: interface for the CBufferReader class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BUFFERREADER_H__D3B3BFFD_FFE0_4EE9_9834_E80835BA35F3__INCLUDED_)
#define AFX_BUFFERREADER_H__D3B3BFFD_FFE0_4EE9_9834_E80835BA35F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBufferReader  
{
private:
	unsigned int currentPosition;
	unsigned int length;
	char *buffer;

public:
	unsigned int GetCurrentPostion();
	char* ReadString();
	double ReadDouble();
	int ReadInt();
	CBufferReader(const char *buffer,unsigned int len);
	virtual ~CBufferReader();

};

#endif // !defined(AFX_BUFFERREADER_H__D3B3BFFD_FFE0_4EE9_9834_E80835BA35F3__INCLUDED_)
