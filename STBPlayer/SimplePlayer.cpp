// SimplePlayer.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#include <streams.h>
#pragma comment(lib,"STRMBASE.lib")
#include <initguid.h>




#define JIF(x) if (FAILED(hr=(x))) \
    {\
	TCHAR msg[1024]={0}; HRESULT result=AMGetErrorText(hr,msg,1024); printf(TEXT("\n0X%08X: %s In: "),hr,msg);\
	printf(#x); printf("\n"); return hr;}

#define SAFE_RELEASE_COM(x)	if((x)!=NULL) {(x)->Release(); delete (x); (x)=NULL;}

DEFINE_GUID(CLSID_BouncingBall,
	0xfd501041, 0x8ebe, 0x11ce, 0x81, 0x83, 0x00, 0xaa, 0x00, 0x57, 0x7d, 0xa1);
DEFINE_GUID(CLSID_VIDEORENDER,   
	0x6BC1CFFA,0x8FC1,0x4261,0xAC,0x22,0xCF,0xB4,0xCC,0x38,0xDB,0x50);

DEFINE_GUID(CLSID_NullInPlace,
	0x52b63860, 0xdc93, 0x11ce, 0xa0, 0x99, 0x00, 0xaa, 0x00, 0x47, 0x9a, 0x58);

DEFINE_GUID(CLSID_NullNull,
0x08af6540, 0x4f21, 0x11cf, 0xaa, 0xcb, 0x00, 0x20, 0xaf, 0x0b, 0x99, 0xa3);

HRESULT FindFilterByClassId (IFilterGraph *pGraph,unsigned long data1,IBaseFilter **filter);


HRESULT RenderOutputPins(IGraphBuilder *pGB, IBaseFilter *pFilter);
int PlayMovie(WCHAR* lpszMovie);
HRESULT PlaySnow(LPTSTR lpszMovie);
void EnumPins (IBaseFilter *inFilter);
IPin* GetFirstPin (IBaseFilter *inFilter);
void EnumFilters (IFilterGraph *pGraph);
void EnumMediaType (IPin *inPin);
HRESULT TestNullFilter(LPTSTR lpszMovie);
HRESULT PrintClsId(IBaseFilter *pFilter);
HRESULT TestNullFilter3(LPTSTR lpszMovie);


void EnumFilters (IFilterGraph *pGraph)
{
	IEnumFilters *pEnum = NULL;
	IBaseFilter *pFilter;
	ULONG cFetched;
	pGraph->EnumFilters(&pEnum);
	while(pEnum->Next(1, &pFilter, &cFetched) == S_OK)
	{
		FILTER_INFO FilterInfo;
		char szName[256];
		pFilter->QueryFilterInfo(&FilterInfo);
		WideCharToMultiByte(CP_ACP, 0, FilterInfo.achName, -1, szName, 256, 0, 0);
		printf("\n");
		wprintf(FilterInfo.achName);
		PrintClsId(pFilter);


//		_LOG_VAL(FilterInfo.achName);
		EnumPins(pFilter);
		FilterInfo.pGraph->Release();
		pFilter->Release();
	}
	pEnum->Release();
}

void EnumPins (IBaseFilter *inFilter)
{
	
	
	IEnumPins * pEnum = NULL;
	IPin * pPin = NULL;
	if (SUCCEEDED(inFilter->EnumPins(&pEnum)))
	{
		//ASSERT(pEnum);
		while (pEnum->Next(1, &pPin, 0) == S_OK)
		{
			PIN_INFO pinInfo;
			char szName[256];
			pPin->QueryPinInfo(&pinInfo);
			WideCharToMultiByte(CP_ACP, 0, pinInfo.achName, -1, szName, 256, 0, 0);
			printf(",");
			wprintf(pinInfo.achName);
//			_LOG_VAL(pinInfo.achName);
			pinInfo.pFilter->Release();
			pPin->Release();
		}
		pEnum->Release();
	}
	
	
}
void RenderPins (IBaseFilter *inFilter,IGraphBuilder **ppGB)
{
	
	
	IEnumPins * pEnum = NULL;
	IPin * pPin = NULL;
	if (SUCCEEDED(inFilter->EnumPins(&pEnum)))
	{
		//ASSERT(pEnum);
		while (pEnum->Next(1, &pPin, 0) == S_OK)
		{
			PIN_INFO pinInfo;
			char szName[256];
			pPin->QueryPinInfo(&pinInfo);
			WideCharToMultiByte(CP_ACP, 0, pinInfo.achName, -1, szName, 256, 0, 0);
			wprintf(pinInfo.achName);
			(*ppGB)->Render(pPin);
//			_LOG_VAL(pinInfo.achName);
			pinInfo.pFilter->Release();
			pPin->Release();
		}
		pEnum->Release();
	}
	
	
}
void EnumMediaType (IPin *inPin)
{
	//IEnumMediaTypes * pEnumCandidates;
	
	IEnumMediaTypes * pMTEnum;
	AM_MEDIA_TYPE *pAMType;  
	if (SUCCEEDED(inPin->EnumMediaTypes(&pMTEnum)))
	{
		//ASSERT(pMTEnum);
		while (pMTEnum->Next(1, &pAMType, 0) == S_OK)
		{

			printf("\n\tfind type: ");
			if(MEDIATYPE_Video==pAMType->majortype){
				printf("MEDIATYPE_Video");
			}else if(MEDIATYPE_Audio==pAMType->majortype){
				printf("MEDIATYPE_Audio");
			
			}else if(MEDIATYPE_Text==pAMType->majortype){
				printf("MEDIATYPE_Text");
			}else if(MEDIATYPE_Midi==pAMType->majortype){
				printf("MEDIATYPE_Midi");
			
			}else if(MEDIATYPE_Stream==pAMType->majortype){
				printf("MEDIATYPE_Stream");			
			}else if(MEDIATYPE_Interleaved==pAMType->majortype){
				printf("MEDIATYPE_Interleaved");				
			}else if(MEDIATYPE_File==pAMType->majortype){
				printf("MEDIATYPE_File");			
			}else if(MEDIATYPE_ScriptCommand==pAMType->majortype){
				printf("MEDIATYPE_ScriptCommand");			
			}else if(MEDIATYPE_AUXLine21Data==pAMType->majortype){
				printf("MEDIATYPE_AUXLine21Data");
#ifdef _WIN32_WCE			
			}else if(MEDIATYPE_LMRT==pAMType->majortype){
				printf("MEDIATYPE_LMRT");
			
			}else if(MEDIATYPE_URL_STREAM==pAMType->majortype){
				printf("MEDIATYPE_URL_STREAM");
#endif			
			}else if(MEDIASUBTYPE_YVU9==pAMType->majortype){
				printf("MEDIASUBTYPE_YVU9");
			
			}else{
				printf("MEDIA: %08X-%04X-%04X-%08X\n",
					pAMType->majortype.Data1,
					pAMType->majortype.Data2,
					pAMType->majortype.Data3,
					pAMType->majortype.Data4
					
					);
				printf("MEDIA: %08X-%04X-%04X-%08X\n",
					pAMType->subtype.Data1,
					pAMType->subtype.Data2,
					pAMType->subtype.Data3,
					pAMType->subtype.Data4
					
					);
			}
		}
		pMTEnum->Release();
	}
}
#include  "ChannelMediaPlayer.h"
static CChannelMediaPlayer player;
int testMediaPlayer(WCHAR *fileName)
{
	HRESULT         hr = S_OK;

	player.Init();
	player.RenderFile(fileName,NULL);
	//printf("%d",player.GetTotalTime());
	//JIF(player.Seek(3000));
	//getchar();
	player.WaitForCompletion();
	player.Release();
	return 0;
}
LONG __stdcall FirstFilter( EXCEPTION_POINTERS* pep ) 
{
	printf( "æ”»ª±¿¿£¡À!\n" );
	return EXCEPTION_EXECUTE_HANDLER; 
}

int main(int argc, char* argv[])
{
	
	if(argc<2){
		printf("use like this: player <url>\n");
		return -1;	
	}
	::SetUnhandledExceptionFilter(FirstFilter);

	int len=strlen(argv[1]);
	WCHAR *fileName=new WCHAR[len+1];
	CoInitialize(NULL);
	::MultiByteToWideChar(936,0,argv[1],len+1,fileName,len+1);
	//PlaySnow("");
	//PlayMovie(L"F:\\videosample\\4.asf");
	//fileName
	testMediaPlayer(fileName);

	//PlayMovie(fileName);
	
	//::GetCurrentProcessId();
	//TestNullFilter3("");
	CoUninitialize();

	return 0;
}
HRESULT RenderOutputPins(IGraphBuilder *pGB, IBaseFilter *pFilter)
{
    HRESULT         hr = S_OK;
    IEnumPins *     pEnumPin = NULL;
    IPin *          pConnectedPin = NULL, * pPin;
    PIN_DIRECTION   PinDirection;
    ULONG           ulFetched;

    // Enumerate all the pins on the filter.
    hr = pFilter->EnumPins( &pEnumPin );

    if(SUCCEEDED(hr))
    {
        // Step through every pin, looking for the output pins.
        while (S_OK == (hr = pEnumPin->Next( 1L, &pPin, &ulFetched)))
        {
            // Check whether this pin is already connected. If so, ignore it.
            hr = pPin->ConnectedTo(&pConnectedPin);
            if (pConnectedPin)
            {
                // Release the IPin interface on the connected pin.
                pConnectedPin->Release();
                pConnectedPin = NULL;
            }

            if (VFW_E_NOT_CONNECTED == hr)
            {
                // This pin is not connected to another filter yet. Check 
                // whether it is an output pin. If so, use the Filter Graph
                // Manager's Render() method to render the pin.

                hr = pPin->QueryDirection( &PinDirection );
                if ( ( S_OK == hr ) && ( PinDirection == PINDIR_OUTPUT ) )
                {
                    hr = pGB->Render(pPin);
                }
            }
            pPin->Release();

            // If there was an error, stop enumerating.
            if (FAILED(hr))                      
                break;
        }
    }

    // Release the pin enumerator object.
    pEnumPin->Release();
    return hr;
}


int PlayMovie(WCHAR* lpszMovie)
{
	HRESULT hr;
	IGraphBuilder *pGB = NULL;

	IMediaControl *pMC = NULL;
	IMediaEventEx *pME = NULL;
	IVideoWindow  *pVW = NULL;
	IBaseFilter *pReader = NULL;
	IFileSourceFilter *pFS = NULL;
	//CLSID_WMAsfReader

	long evCode; // something to hold a returned event code
	JIF(CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC,
		IID_IGraphBuilder, (void **)&pGB));
	JIF(CoCreateInstance(CLSID_WMAsfReader, NULL, CLSCTX_INPROC,
		IID_IBaseFilter, (void **)&pReader));

	JIF(pGB->AddFilter(pReader, L"ASF Reader"));
	JIF(pReader->QueryInterface(IID_IFileSourceFilter, (void **) &pFS));
	//hr = pGB->RenderFile(L"file:///C:/Downloads/cluster1.wmv", NULL);
	//hr = pGB->RenderFile(L"http://10.130.200.135:80/cluster1.wmv", NULL);
	printf("before render file!\n");
	JIF(pFS->Load( lpszMovie, NULL));

	//JIF(pGB->AddSourceFilter(lpszMovie, L"WMAsfReader",&pReader));
	
	JIF(RenderOutputPins(pGB,pReader));
	//while(hr=pSnowFilter->EnumPins(
	//JIF(pGB->RenderFile(lpszMovie, NULL));
	//pGB->AddSourceFilter(
	//EnumFilters(pGB);
	//http://127.0.0.1:1965/live
	//pGB->Reconnect(
	//hr = pGB->RenderFile(
	int a=VFW_S_DUPLICATE_NAME;
	//hr = pGB->QueryInterface(
	JIF(pGB->QueryInterface(IID_IMediaControl, (void **)&pMC));
	JIF(pGB->QueryInterface(IID_IMediaEventEx, (void **)&pME));
	JIF(pMC->Run());
	JIF(pME->WaitForCompletion(INFINITE, &evCode));
	if(pMC)pMC->Release();
	if(pGB)pGB->Release();
	if(pME)pME->Release();
	return 0;
}


HRESULT PlaySnow(LPTSTR lpszMovie)
{
	HRESULT hr;
	IGraphBuilder *pGB = NULL;

	IMediaControl *pMC = NULL;
	IMediaEventEx *pME = NULL;
	IVideoWindow  *pVW = NULL;
	IBaseFilter *pSnowFilter = NULL;
	IBaseFilter *pVMRFilter = NULL;
	IPin *pPinOut = NULL;
	IPin *pPinIn = NULL;
	
	long evCode=0; 
	// something to hold a returned event code
	JIF(CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC,
		IID_IGraphBuilder, (void **)&pGB));
	//add filter and connect them



	//hr=CoCreateInstance(INFINITEPINTEEFILTER, NULL, CLSCTX_INPROC_SERVER, IID_IBaseFilter, (void**)&pVideorenderFilter);
	JIF(CoCreateInstance(
		CLSID_VIDEORENDER, 
		NULL, 
		CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, 
		(void**)&pVMRFilter));
	JIF(CoCreateInstance(
		CLSID_BouncingBall, 
		NULL, 
		CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, 
		(void**)&pSnowFilter));
	//GET PINS
	JIF(pGB->AddFilter(pVMRFilter,L"RENDER"));
	JIF(pGB->AddFilter(pSnowFilter,L"SOURCE"));

//	EnumPins(pSnowFilter);
//	EnumPins(pVMRFilter);

	//hr = pSnowFilter->FindPin(L"Output" , &pPinOut);
	pPinOut=GetFirstPin(pSnowFilter);
	
	JIF(pVMRFilter->FindPin(L"VMR Input0" , &pPinIn));
	
	//pGB->AddSourceFilter(

	JIF(pGB->Connect (pPinOut,pPinIn));

	JIF( pGB->QueryInterface(IID_IMediaControl, (void **)&pMC));
	JIF( pGB->QueryInterface(IID_IMediaEventEx, (void **)&pME));

	//	hr = pVW->put_Owner((OAHWND)this->m_hWnd);
	JIF( pMC->Run());
	JIF( pME->WaitForCompletion(INFINITE, &evCode));
	//Sleep(100000000);
	JIF(pGB->Disconnect(pPinOut));
	SAFE_RELEASE_COM(pMC);
	SAFE_RELEASE_COM(pSnowFilter);
	SAFE_RELEASE_COM(pVMRFilter);
	SAFE_RELEASE_COM(pPinOut);
	SAFE_RELEASE_COM(pPinIn);
	SAFE_RELEASE_COM(pPinIn);
	SAFE_RELEASE_COM(pGB);
	return hr;

}


IPin* GetFirstPin (IBaseFilter *inFilter)
{
	
	BOOL found=FALSE;
	IEnumPins * pEnum = NULL;
	IPin * pPin = NULL;
	if (SUCCEEDED(inFilter->EnumPins(&pEnum)))
	{
		//ASSERT(pEnum);
		while (pEnum->Next(1, &pPin, 0) == S_OK)
		{
			//_LOG_VAL(pinInfo.achName);
			found=TRUE;
			pPin->Release();
		}
		pEnum->Release();
	}
	if(found){
		return pPin;
	}else{
		return NULL;
	}
	
}
#define _DEBUG_DESC 1
HRESULT TestNullFilter(LPTSTR lpszMovie)
{
	HRESULT hr;
	IGraphBuilder *pGB = NULL;

	IMediaControl *pMC = NULL;
	IMediaEventEx *pME = NULL;
	IVideoWindow  *pVW = NULL;
	IBaseFilter   *pFilterSrc = NULL;
	IBaseFilter   *pFilterDec = NULL;

	IPin		  *pPin1 = NULL;	
	IPin		  *pPin2 = NULL;

	IPin		  *pPinDescOut = NULL;	
	IPin		  *pPinDescIn = NULL;

	IBaseFilter   *pDescFilter = NULL;

	//INullIPP      *pDesc = NULL;

	long evCode = 0; // something to hold a returned event code
	JIF( CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC,
		IID_IGraphBuilder, (void **)&pGB));
	JIF(CoCreateInstance(
		CLSID_NullInPlace, 
		NULL, 
		CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, 
		(void**)&pDescFilter));

	JIF(pGB->AddFilter((IBaseFilter*)pDescFilter,L"DESCRAMBLE"));

	JIF(pDescFilter->FindPin(L"In",&pPinDescIn));
	JIF(pDescFilter->FindPin(L"Out",&pPinDescOut));

	//hr = pGB->RenderFile(L"file:///C:/Downloads/cluster1.wmv", NULL);
	//hr = pGB->RenderFile(L"http://10.130.200.135:80/cluster1.wmv", NULL);
	//hr = pGB->RenderFile(L"http://10.130.200.199:80/stream.jsp", NULL);
	JIF( pGB->RenderFile(L"f:\\girls.wmv", NULL));
	//JIF( pGB->RenderFile(L"http://127.0.0.1/1.wmv", NULL));

	JIF(pGB->QueryInterface(IID_IVideoWindow,(void **)&pVW));
	::EnumFilters(pGB);

	//JIF(pVW->SetWindowPosition(0, 0, 700, 400));
	//JIF(pGB->QueryInterface(CLSID_VideoRenderer,(void**)&pFilter));
	//JIF( pGB->FindFilterByName(TEXT("\0"),&pFilter));
	//JIF( pGB->AddSourceFilter(
	JIF( pGB->FindFilterByName(L"f:\\girls.wmv",&pFilterSrc));
	JIF( pFilterSrc->FindPin(L"Raw Video 1",&pPin1));
	
	JIF( pGB->FindFilterByName(L"WMVideo Decoder DMO",&pFilterDec));
	JIF( pFilterDec->FindPin(L"in0",&pPin2));

	//WMVideo Decoder DMO

	//JIF(FindFilterByClassId(pGB,0X187463A008,&pFilter));
	PrintClsId(pFilterSrc);
	//pGB->FindFilterByName(

	JIF( pFilterSrc->FindPin(L"Raw Video 1",&pPin1));
	//JIF( pFilter->FindPin(L"Stream 2",&pPin1));
	
	//JIF( FindFilterByClassId(pGB,0XB9D1F322,&pFilter));
	//JIF( FindFilterByClassId(pGB,0XB9D1F322,&pFilter));

	PrintClsId(pFilterSrc);
	JIF( pDescFilter ->FindPin(L"In",&pPinDescIn));
	JIF( pDescFilter ->FindPin(L"Out",&pPinDescOut));


	EnumMediaType(pPin1);
	EnumMediaType(pPin2);

	//EnumMediaType(pPinDescOut);
	
	
	JIF( pPin1->Disconnect());
	JIF( pPin2->Disconnect());
	

	
	//JIF(pGB->Connect(pPin1,pPin2));
#if _DEBUG_DESC

	JIF(pGB->Connect(pPin1,pPinDescIn));
	JIF(pGB->Connect(pPinDescOut,pPin2));
#else
	JIF(pGB->Connect(pPin1,pPin2));

#endif

	//JIF(pPin1->ConnectedTo(&pPin2));
	int c=VFW_E_CANNOT_CONNECT;

	//EnumFilters(pGB);
	int a=VFW_S_DUPLICATE_NAME;

	JIF(  pGB->QueryInterface(IID_IMediaControl, (void **)&pMC));
	JIF(  pGB->QueryInterface(IID_IMediaEventEx, (void **)&pME));

	hr = pMC->Run();
	hr = pME->WaitForCompletion(INFINITE, &evCode);
	if(pMC)pMC->Release();
	if(pGB)pGB->Release();
	if(pME)pME->Release();
	return hr;
}

HRESULT TestNullFilter3(LPTSTR lpszMovie)
{
	HRESULT hr;
	IGraphBuilder *pGB = NULL;

	IMediaControl *pMC = NULL;
	IMediaEventEx *pME = NULL;
	IVideoWindow  *pVW = NULL;
	IBaseFilter   *pFilterSrc = NULL;
	IBaseFilter   *pFilterDec = NULL;

	IPin		  *pPin1 = NULL;	
	IPin		  *pPin2 = NULL;

	IPin		  *pPinDescOut = NULL;	
	IPin		  *pPinDescIn = NULL;

	IBaseFilter   *pDescFilter = NULL;

	//INullIPP      *pDesc = NULL;

	long evCode = 0; // something to hold a returned event code
	JIF( CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC,
		IID_IGraphBuilder, (void **)&pGB));
	JIF(CoCreateInstance(
		CLSID_NullNull, 
		NULL, 
		CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, 
		(void**)&pDescFilter));

	//F:\videosample

	//JIF( pGB->RenderFile(L"f:\\girls.wmv", NULL));
	JIF( pGB->RenderFile(L"F:\\videosample\\4.asf", NULL));
	JIF(pGB->AddFilter((IBaseFilter*)pDescFilter,L"DESCRAMBLE"));
	//JIF( pGB->RenderFile(L"http://127.0.0.1/1.wmv", NULL));
	JIF(pDescFilter->FindPin(L"In",&pPinDescIn));
	JIF(pDescFilter->FindPin(L"Out",&pPinDescOut));

	JIF(pGB->QueryInterface(IID_IVideoWindow,(void **)&pVW));
	::EnumFilters(pGB);

	//JIF(pVW->SetWindowPosition(0, 0, 700, 400));
	//JIF(pGB->QueryInterface(CLSID_VideoRenderer,(void**)&pFilter));
	//JIF( pGB->FindFilterByName(TEXT("\0"),&pFilter));
	//JIF( pGB->AddSourceFilter(
	JIF( pGB->FindFilterByName(L"AVI Decompressor",&pFilterSrc));
	//JIF( pFilterSrc->FindPin(L"Raw Video 1",&pPin1));
	JIF( pFilterSrc->FindPin(L"Out",&pPin1));

	//Moonlight Odio Dekoda
	JIF( pGB->FindFilterByName(L"Video Renderer",&pFilterDec));
	//JIF( pFilterDec->FindPin(L"in0",&pPin2));
	JIF( pFilterDec->FindPin(L"VMR Input0",&pPin2));
	//XForm In

	//WMVideo Decoder DMO

	//JIF(FindFilterByClassId(pGB,0X187463A008,&pFilter));
	PrintClsId(pFilterSrc);
	//pGB->FindFilterByName(

	JIF( pFilterSrc->FindPin(L"Out",&pPin1));
	//JIF( pFilter->FindPin(L"Stream 2",&pPin1));
	
	//JIF( FindFilterByClassId(pGB,0XB9D1F322,&pFilter));
	//JIF( FindFilterByClassId(pGB,0XB9D1F322,&pFilter));

	PrintClsId(pFilterSrc);
	JIF( pDescFilter ->FindPin(L"In",&pPinDescIn));
	JIF( pDescFilter ->FindPin(L"Out",&pPinDescOut));

	printf("media type");
	EnumMediaType(pPinDescIn);
	//EnumMediaType(pPinDescOut);

	
	
	JIF( pPin1->Disconnect());
	JIF( pPin2->Disconnect());
	

	
	//JIF(pGB->Connect(pPin1,pPin2));

	JIF(pGB->Connect(pPin1,pPinDescIn));
	JIF(pGB->Connect(pPinDescOut,pPin2));



	//JIF(pPin1->ConnectedTo(&pPin2));
	int c=VFW_E_CANNOT_CONNECT;

	//EnumFilters(pGB);
	int a=VFW_S_DUPLICATE_NAME;

	JIF(  pGB->QueryInterface(IID_IMediaControl, (void **)&pMC));
	JIF(  pGB->QueryInterface(IID_IMediaEventEx, (void **)&pME));

	hr = pMC->Run();
	hr = pME->WaitForCompletion(INFINITE, &evCode);

	if(pMC)pMC->Release();
	if(pGB)pGB->Release();
	if(pME)pME->Release();
	return hr;
}
HRESULT TestNullFilter4(LPTSTR lpszMovie)
{
	HRESULT hr;
	IGraphBuilder *pGB = NULL;

	IMediaControl *pMC = NULL;
	IMediaEventEx *pME = NULL;
	IVideoWindow  *pVW = NULL;
	IBaseFilter   *pFilterSrc = NULL;
	IBaseFilter   *pFilterDec = NULL;

	IPin		  *pPin1 = NULL;	
	IPin		  *pPin2 = NULL;

	IPin		  *pPinDescOut = NULL;	
	IPin		  *pPinDescIn = NULL;

	IBaseFilter   *pDescFilter = NULL;

	//INullIPP      *pDesc = NULL;

	long evCode = 0; // something to hold a returned event code
	JIF( CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC,
		IID_IGraphBuilder, (void **)&pGB));
	JIF(CoCreateInstance(
		CLSID_NullNull, 
		NULL, 
		CLSCTX_INPROC_SERVER, 
		IID_IBaseFilter, 
		(void**)&pDescFilter));

	//F:\videosample

	//JIF( pGB->RenderFile(L"f:\\girls.wmv", NULL));
	JIF( pGB->RenderFile(L"F:\\videosample\\4.asf", NULL));
	JIF(pGB->AddFilter((IBaseFilter*)pDescFilter,L"DESCRAMBLE"));
	//JIF( pGB->RenderFile(L"http://127.0.0.1/1.wmv", NULL));
	JIF(pDescFilter->FindPin(L"In",&pPinDescIn));
	JIF(pDescFilter->FindPin(L"Out",&pPinDescOut));

	JIF(pGB->QueryInterface(IID_IVideoWindow,(void **)&pVW));
	::EnumFilters(pGB);

	//JIF(pVW->SetWindowPosition(0, 0, 700, 400));
	//JIF(pGB->QueryInterface(CLSID_VideoRenderer,(void**)&pFilter));
	//JIF( pGB->FindFilterByName(TEXT("\0"),&pFilter));
	//JIF( pGB->AddSourceFilter(
	JIF( pGB->FindFilterByName(L"F:\\videosample\\4.asf",&pFilterSrc));
	//JIF( pFilterSrc->FindPin(L"Raw Video 1",&pPin1));
	JIF( pFilterSrc->FindPin(L"Raw Video 0",&pPin1));
	//Moonlight Odio Dekoda
	JIF( pGB->FindFilterByName(L"AVI Decompressor",&pFilterDec));
	//JIF( pFilterDec->FindPin(L"in0",&pPin2));
	JIF( pFilterDec->FindPin(L"In",&pPin2));
	//XForm In

	//WMVideo Decoder DMO

	//JIF(FindFilterByClassId(pGB,0X187463A008,&pFilter));
	PrintClsId(pFilterSrc);
	//pGB->FindFilterByName(

	JIF( pFilterSrc->FindPin(L"Raw Video 0",&pPin1));
	//JIF( pFilter->FindPin(L"Stream 2",&pPin1));
	
	//JIF( FindFilterByClassId(pGB,0XB9D1F322,&pFilter));
	//JIF( FindFilterByClassId(pGB,0XB9D1F322,&pFilter));

	PrintClsId(pFilterSrc);
	JIF( pDescFilter ->FindPin(L"In",&pPinDescIn));
	JIF( pDescFilter ->FindPin(L"Out",&pPinDescOut));

	printf("media type");
	EnumMediaType(pPinDescIn);
	//EnumMediaType(pPinDescOut);

	
	
	JIF( pPin1->Disconnect());
	JIF( pPin2->Disconnect());
	

	
	//JIF(pGB->Connect(pPin1,pPin2));

	JIF(pGB->Connect(pPin1,pPinDescIn));
	JIF(pGB->Connect(pPinDescOut,pPin2));



	//JIF(pPin1->ConnectedTo(&pPin2));
	int c=VFW_E_CANNOT_CONNECT;

	//EnumFilters(pGB);
	int a=VFW_S_DUPLICATE_NAME;

	JIF(  pGB->QueryInterface(IID_IMediaControl, (void **)&pMC));
	JIF(  pGB->QueryInterface(IID_IMediaEventEx, (void **)&pME));

	hr = pMC->Run();
	hr = pME->WaitForCompletion(INFINITE, &evCode);

	if(pMC)pMC->Release();
	if(pGB)pGB->Release();
	if(pME)pME->Release();
	return hr;
}

HRESULT FindFilterByClassId (IFilterGraph *pGraph,unsigned long data1,IBaseFilter **filter)
{
	HRESULT hr=1;
	IEnumFilters *pEnum = NULL;
	IBaseFilter *pFilter = NULL ;
	ULONG cFetched;
	JIF(pGraph->EnumFilters(&pEnum));
	
	while(pEnum->Next(1, &pFilter, &cFetched) == S_OK)
	{	
		CLSID clsId;
		JIF(pFilter->GetClassID(&clsId));
		if(data1==clsId.Data1){
			*filter=pFilter;
			hr=0;
			break;			
		}
		//IBaseFilter **filte;
		pFilter->Release();
	}
	pEnum->Release();
	return hr;
}



HRESULT PrintClsId(IBaseFilter *pFilter)
{

		CLSID id;
		HRESULT hr=0;
		
		if(NULL==pFilter){
			printf("\n%08X-%04X-%04X-%08X",
				0,
				0,
				0,
				0);	
			return 1;
		
		}
		pFilter->GetClassID(&id);
		if(!FAILED(hr)){
			printf("\n%08X-%04X-%04X-%08X",
				id.Data1,
				id.Data2,
				id.Data3,
				id.Data4);

		}
		return hr;
}




