// AudioOutTest2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <MMSystem.h>
#include "FileReader.h"
#define SIZE_MEGA  1024*32*2
#define SIZE_MEGA2  1024*32*2
void CALLBACK WaveCallback(HWAVEOUT hWave, UINT uMsg, DWORD dwUser, 
                           DWORD dw1, DWORD dw2);
#include "AudioRender.h"

int main(int argc, char* argv[]){
	
	WAVEFORMATEX wfx;
	CFileReader reader("D:\\Downloads\\01.01º®É½É®×Ù.wav");
	reader.Seek(20);
	reader.ReadFile((char*)&wfx,sizeof(WAVEFORMATEX));
	reader.Seek(8);
	CAudioRender audiorender(&wfx);
	//int sizepersample = audiorender;
	int sizepersample = audiorender.GetSampleLength();
	char *p=new char[sizepersample];
	while(1)
	{	int ret = 0;
		ret = reader.ReadFile(p,sizepersample);
		//IF WANT TO DECODE HERE 
		//DECODE IT
		if(ret > 0 ){	
			audiorender.PushSample(p,ret);
		}else{
			break;
		}
	}

	return 0;
}


int kmain(int argc, char* argv[])
{
	HWAVEOUT	waveDevice;
	WAVEFORMATEX wfx;
    HANDLE   semaphoreHandle;
	char *p=new char[SIZE_MEGA];
	char *p2=new char[SIZE_MEGA];



	CFileReader reader("D:\\Downloads\\01.01º®É½É®×Ù.wav");
	reader.Seek(20);
	reader.ReadFile((char*)&wfx,sizeof(WAVEFORMATEX));
	reader.Seek(8);
	

	semaphoreHandle=CreateSemaphore(NULL, 2, 2, NULL);
	waveOutOpen(&waveDevice,
                WAVE_MAPPER,
                &wfx,
                (DWORD)WaveCallback,
                (DWORD)semaphoreHandle,
                CALLBACK_FUNCTION);

	WAVEHDR      waveHeader;
	WAVEHDR      waveHeader2;
	


	int counter= 0;
	
	memset(&waveHeader,0,sizeof(WAVEHDR));
	waveHeader.lpData = p;
	waveHeader.dwBufferLength  = SIZE_MEGA2;
	waveHeader.lpNext = &waveHeader2;
	
	waveHeader2 = waveHeader;
	waveHeader2.lpData = p2;
	waveHeader2.dwBufferLength  = SIZE_MEGA2;
	waveHeader2.lpNext = &waveHeader;


	waveOutPrepareHeader(waveDevice, &waveHeader, sizeof(WAVEHDR));
	waveOutPrepareHeader(waveDevice, &waveHeader2, sizeof(WAVEHDR));	

	

	while(1){
		::WaitForSingleObject(semaphoreHandle,INFINITE);
		
		printf("WaitForSingleObject %08u\n",counter);
		if(counter%2==0){
			if(reader.ReadFile(p,SIZE_MEGA2)){		
				waveOutWrite ( waveDevice, &waveHeader, sizeof(WAVEHDR) );
			}else{
				break;
			}
		}else{
			if(reader.ReadFile(p2,SIZE_MEGA2)>0){
				waveOutWrite ( waveDevice, &waveHeader2, sizeof(WAVEHDR) );
			}else{
				break;
			}
		}
		
		counter++;
		
	
	
	}


	waveOutClose(waveDevice);
	CloseHandle(semaphoreHandle);

	printf("Hello World!\n");
	return 0;
}


void CALLBACK WaveCallback(HWAVEOUT hWave, UINT uMsg, DWORD dwUser, 
                           DWORD dw1, DWORD dw2)
{
    if (uMsg == WOM_DONE) {
        ReleaseSemaphore((HANDLE)dwUser, 1, NULL);
		//printf("release semaphore called\n");
		printf("release semaphore called\n");
    }
	
}
