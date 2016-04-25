// CPIOTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define xmalloc(s) HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,(s))
#define xfree(p)   HeapFree(GetProcessHeap(),0,(p))

//题目：怎样使用 Visual C++ 编译出只有 1536 字节的窗口程序
//这些技巧都是dREAMtHEATER老大哥告我的……
//编译出来后，文件大小为: 1536 字节


////////////////////////////////////////////////////////////////////////////////////////////////////
//预处理
#include <Windows.h>

//使用了下面的预处理，编译连接时必须是 Release 方式，否则不能通过


//自定义程序入口，如果要优化，推荐使用这个
//如果使用 VS.NET，也可以这样设置：在“解决方案管理器”里选定项目，右击，选择“属性”->“链接器”->“高级”->“入口点”
//VC 6里面也有类似的设置，但具体不记得了
//项目属性的其它设置可以仔细看看，其它优化也都在这里可以设置
#pragma comment(linker, "/ENTRY:EntryPoint")


//下面是调整段对齐，默认是 4K，在 Win98 下能更快地装入 PE 文件，但会增加 PE 文件的大小
//下面这一行在这里好像会说是“无效的指令”什么的，故在这里也注释掉了，也许是段太小的原因吧。
//直接在工程选项里面设置：项目“属性”->“链接器”->“优化”->“Windows98 优化”->“否 (/OPT:NOWIN98)”
//#pragma comment(linker, "/OPT:NOWIN98")


//下面的优化是段合并，不推荐使用，在很多程序里也许也许不能使用
#pragma comment(linker, "/SECTION:MiniPE,")             //创建自定义的 MiniPE Section
#pragma comment(linker, "/MERGE:.data=MiniPE")  //合并.data Section 到 MiniPE Section
#pragma comment(linker, "/MERGE:.text=MiniPE")  //合并.text Section 到 MiniPE Section
#pragma comment(linker, "/MERGE:.rdata=MiniPE") //合并.rdata Section 到 MiniPE Section
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////
//全局变量
HWND                                    g_hWnd;         //主窗口句柄，一般程序中经常用到此变量，故使用全局变量
HINSTANCE                               g_hInst;        //应用程序进程句柄，一般程序中经常用到此变量，故使用全局变量

const char                              c_szAppName[] = "MiniPE";
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////
//函数声明
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow);
////////////////////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////////////////////////
//入口函数
//使用我们自己的入口函数，而不用连接器默认提供的一大堆程序初始化操作的代码
//为了在一个普通的 Win32SDK 程序里能使用这种方法，下面的函数将调用 WinMain() 函数，并给出相应的参数
void EntryPoint()
{
       ExitProcess(WinMain(GetModuleHandle(NULL), NULL, GetCommandLine(), SW_SHOWNORMAL));
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////
//主函数
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
//主窗口回调函数
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