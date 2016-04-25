// AudioRender.cpp: implementation of the CAudioRender class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AudioRender.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
static void CALLBACK WaveCallback(HWAVEOUT hWave, UINT uMsg, DWORD dwUser, 
                           DWORD dw1, DWORD dw2)
{
    if (uMsg == WOM_DONE) {
        ReleaseSemaphore((HANDLE)dwUser, 1, NULL);
		//printf("release semaphore called\n");
    }	
}


CAudioRender::CAudioRender(WAVEFORMATEX *pwfx)
{
	this->counter = 0;
	this->wfx=*pwfx;
	this->bufferedSampleCount = 8;
	this->waveHeaders=new WAVEHDR[bufferedSampleCount];
	this->sampleLength = 32*1024;

	semaphoreHandle=CreateSemaphore(NULL, bufferedSampleCount, bufferedSampleCount, NULL);

	waveOutOpen(&waveDevice,
                WAVE_MAPPER,
                &wfx,
                (DWORD)WaveCallback,
                (DWORD)semaphoreHandle,
                CALLBACK_FUNCTION);

	//初始化若干个header并且首尾相连,取不同段作为不同的缓冲开始 
	//initiates some headers and conntect them like a rope;
	audioBuffer=new char[bufferedSampleCount*sampleLength];
	for(int i=0;i<bufferedSampleCount;i++){
		/*
		0----1----0	
		*/	
		int index = i;
		memset(&waveHeaders[i],0,sizeof(WAVEHDR));
		waveHeaders[i].dwBufferLength = sampleLength;
		waveHeaders[i].lpData = audioBuffer + (i*waveHeaders[i].dwBufferLength);
		waveHeaders[i].lpNext = &(waveHeaders[(i+1)%bufferedSampleCount]);
		waveOutPrepareHeader(waveDevice, &waveHeaders[i], sizeof(WAVEHDR));
	}

	

}

CAudioRender::~CAudioRender()
{

	waveOutClose(waveDevice);
	CloseHandle(semaphoreHandle);
	delete[] waveHeaders;
	delete[] audioBuffer;

}
int CAudioRender::PushSample(char *buffer, int len)
{
	
	if(len > this->sampleLength)
	{
		return 0;
	}
	//if there isn't idle buffer, reture!
	WaitForSingleObject(this->semaphoreHandle,INFINITE);
	//printf("%d\n",counter);	
	int index = counter % this->bufferedSampleCount;

	char *p=waveHeaders[index].lpData;
	memcpy(p,buffer,len);
	waveHeaders[index].dwBufferLength=len;


	waveOutWrite ( waveDevice, &waveHeaders[index], sizeof(WAVEHDR) );
	counter++;
	return len;
}

void CAudioRender::SetBufferedSample(int sampleCount)
{
	bufferedSampleCount = sampleCount;	
}

BOOL CAudioRender::Stop()
{
	counter = 0;
	waveOutReset(waveDevice);
	return TRUE;
}

int CAudioRender::GetSampleLength()
{
	return this->sampleLength;
}
