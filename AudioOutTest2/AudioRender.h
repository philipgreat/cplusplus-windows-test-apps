// AudioRender.h: interface for the CAudioRender class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AUDIORENDER_H__F1126EF8_F9B4_47F9_8927_224F7791BC8A__INCLUDED_)
#define AFX_AUDIORENDER_H__F1126EF8_F9B4_47F9_8927_224F7791BC8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <windows.h>
#include <MMSystem.h>
class CAudioRender  
{
private:
	int counter;
	WAVEHDR     *waveHeaders;
	char		*audioBuffer;
	HWAVEOUT	waveDevice;
	WAVEFORMATEX wfx;
	int			bufferedSampleCount;
	HANDLE		semaphoreHandle;
	int			sampleLength;
public:
	int GetSampleLength();
	BOOL Stop();
	void SetBufferedSample(int sampleCount);
	int PushSample(char *buffer,int len);
	CAudioRender(WAVEFORMATEX *pwfx);
	virtual ~CAudioRender();

};

#endif // !defined(AFX_AUDIORENDER_H__F1126EF8_F9B4_47F9_8927_224F7791BC8A__INCLUDED_)
