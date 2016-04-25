// BufferWriter.h: interface for the CBufferWriter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BUFFERWRITER_H__6BB6F3CB_F169_4D60_9A74_964FDD7E04A4__INCLUDED_)
#define AFX_BUFFERWRITER_H__6BB6F3CB_F169_4D60_9A74_964FDD7E04A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBufferWriter  
{
private:
	int currentPosition;
	unsigned int length;
	char *buffer;
public:
	unsigned int GetCurrentPostion();
	bool WriteDouble(double val);
	bool WriteString(char *str);
	bool WriteInt(int val);
	CBufferWriter(char *buffer,unsigned int len);
	virtual ~CBufferWriter();

};

#endif // !defined(AFX_BUFFERWRITER_H__6BB6F3CB_F169_4D60_9A74_964FDD7E04A4__INCLUDED_)
