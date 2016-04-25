// CPIOTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define xmalloc(s) HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,(s))
#define xfree(p)   HeapFree(GetProcessHeap(),0,(p))

//��Ŀ������ʹ�� Visual C++ �����ֻ�� 1536 �ֽڵĴ��ڳ���
//��Щ���ɶ���dREAMtHEATER�ϴ����ҵġ���
//����������ļ���СΪ: 1536 �ֽ�


////////////////////////////////////////////////////////////////////////////////////////////////////
//Ԥ����
#include <Windows.h>

//ʹ���������Ԥ������������ʱ������ Release ��ʽ��������ͨ��


//�Զ��������ڣ����Ҫ�Ż����Ƽ�ʹ�����
//���ʹ�� VS.NET��Ҳ�����������ã��ڡ������������������ѡ����Ŀ���һ���ѡ�����ԡ�->����������->���߼���->����ڵ㡱
//VC 6����Ҳ�����Ƶ����ã������岻�ǵ���
//��Ŀ���Ե��������ÿ�����ϸ�����������Ż�Ҳ���������������
#pragma comment(linker, "/ENTRY:EntryPoint")


//�����ǵ����ζ��룬Ĭ���� 4K���� Win98 ���ܸ����װ�� PE �ļ����������� PE �ļ��Ĵ�С
//������һ������������˵�ǡ���Ч��ָ�ʲô�ģ���������Ҳע�͵��ˣ�Ҳ���Ƕ�̫С��ԭ��ɡ�
//ֱ���ڹ���ѡ���������ã���Ŀ�����ԡ�->����������->���Ż���->��Windows98 �Ż���->���� (/OPT:NOWIN98)��
//#pragma comment(linker, "/OPT:NOWIN98")


//������Ż��Ƕκϲ������Ƽ�ʹ�ã��ںܶ������Ҳ��Ҳ����ʹ��
#pragma comment(linker, "/SECTION:MiniPE,")             //�����Զ���� MiniPE Section
#pragma comment(linker, "/MERGE:.data=MiniPE")  //�ϲ�.data Section �� MiniPE Section
#pragma comment(linker, "/MERGE:.text=MiniPE")  //�ϲ�.text Section �� MiniPE Section
#pragma comment(linker, "/MERGE:.rdata=MiniPE") //�ϲ�.rdata Section �� MiniPE Section
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////
//ȫ�ֱ���
HWND                                    g_hWnd;         //�����ھ����һ������о����õ��˱�������ʹ��ȫ�ֱ���
HINSTANCE                               g_hInst;        //Ӧ�ó�����̾����һ������о����õ��˱�������ʹ��ȫ�ֱ���

const char                              c_szAppName[] = "MiniPE";
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////
//��������
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow);
////////////////////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////////////////////////
//��ں���
//ʹ�������Լ�����ں�����������������Ĭ���ṩ��һ��ѳ����ʼ�������Ĵ���
//Ϊ����һ����ͨ�� Win32SDK ��������ʹ�����ַ���������ĺ��������� WinMain() ��������������Ӧ�Ĳ���
void EntryPoint()
{
       ExitProcess(WinMain(GetModuleHandle(NULL), NULL, GetCommandLine(), SW_SHOWNORMAL));
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////
//������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow)
{
       MSG                                             sMsg;
       WNDCLASSEX                              sWndClassEx;


       g_hInst = hInstance;

       sWndClassEx.cbSize = sizeof(WNDCLASSEX);
       sWndClassEx.style = CS_VREDRAW | CS_HREDRAW;
       sWndClassEx.lpfnWndProc = (WNDPROC) WindowProc;
       sWndClassEx.cbClsExtra = 0;
       sWndClassEx.cbWndExtra = 0;
       sWndClassEx.hInstance = g_hInst;
       sWndClassEx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
       sWndClassEx.hCursor = LoadCursor(NULL, IDC_ARROW);
       sWndClassEx.hbrBackground = (HBRUSH) (COLOR_WINDOW);
       sWndClassEx.lpszMenuName = NULL;
       sWndClassEx.lpszClassName = c_szAppName;
       sWndClassEx.hIconSm = NULL;
       RegisterClassEx(&sWndClassEx);

       g_hWnd = CreateWindowEx(0, c_szAppName, c_szAppName, WS_OVERLAPPEDWINDOW,
               CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
               NULL, NULL, g_hInst, NULL);
       ShowWindow(g_hWnd, iCmdShow);
       UpdateWindow(g_hWnd);
	   //printf("hello");

       while (GetMessage(&sMsg, NULL, 0, 0))
       {
               TranslateMessage(&sMsg);
               DispatchMessage(&sMsg);
       }
       return((int) sMsg.wParam);
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////
//�����ڻص�����
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
       switch (uMsg)
       {
       case WM_DESTROY:
               PostQuitMessage(0);
               break;

       default:
               return(DefWindowProc(hWnd, uMsg, wParam, lParam));
       }
       return(0);
}
///