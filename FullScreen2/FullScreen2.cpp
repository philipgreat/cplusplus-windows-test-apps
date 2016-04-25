
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"d3d9.lib")

#include <windows.h>// Header File For Windows
#include <d3dx9.h>// Header File For DirectX 3D
#include <d3d9.h>// Header File For DirectX 3D
#include <d3dx9core.h>

HDC hDC= NULL;// Private GDI Device Context
HWND hWnd= NULL;// Holds Our Window Handle
HINSTANCE hInstance;// Holds The Instance Of The Application
LPDIRECT3D9 pD3D= NULL;// DirectX 3D Version 9
LPDIRECT3DDEVICE9 pD3DDevice= NULL;// DirectX 3D Rendering Device

//LPDIRECT3DVERTEXBUFFER9 g_pVB= NULL; // Buffer to hold vertices
LPDIRECT3DTEXTURE9 g_pTexture = NULL; // Our texture
LPD3DXSPRITE		sprite=NULL;
LPDIRECT3DTEXTURE9 g_pTexture2 = NULL; // Our texture

static int globalCounter= 0;

static bool keys[256];// Array Used For The Keyboard Routine
static bool active=TRUE;// Window Active Flag Set To TRUE By Default
static bool fullscreen=TRUE;// Fullscreen Flag Set To Fullscreen Mode By Default

char *fileList[]={"denis keller.jpg","image2.jpg"};

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);// Declaration For WndProc

void ResizeD3DScene(int width, int height)// Resize And Initialize The D3D Window
{
	if (height==0)// Prevent A Divide By Zero By
	{
		height=1;// Making Height Equal One
	}
	
	D3DXMATRIXA16 matProjection;// Create A Projection Matrix
	// Calculate The Aspect Ratio Of The Window
	D3DXMatrixPerspectiveFovLH(&matProjection, 45.0f, (float)width/(float)height, 0.1f, 100.0f );
	pD3DDevice->SetTransform( D3DTS_PROJECTION, &matProjection );
	D3DXMatrixIdentity(&matProjection);// Reset The Projection Matrix
}

int ChangeBackground(char *fileName)
{
	if( FAILED( D3DXCreateTextureFromFile( pD3DDevice, fileName, &g_pTexture ) ) )
	{
		return E_FAIL;
	}
	return S_OK;
	
}

int SwitchBackground()
{
	int size = sizeof(fileList)/sizeof(char*);
	
	ChangeBackground(*(fileList+globalCounter%size));
	globalCounter++;
	return 0;
	
}

int InitD3D() // All Setup For D3D Goes Here
{
	
	pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE ); // Enable Z-Buffer (Depth Buffer)
	pD3DDevice->SetRenderState(D3DRS_CULLMODE, FALSE); // Disable Backface Culling
	pD3DDevice->SetRenderState(D3DRS_LIGHTING, FALSE); // Disable Light
	pD3DDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE);
	//SwitchBackground();
	
	if( FAILED( D3DXCreateTextureFromFile( pD3DDevice, "image2.jpg", &g_pTexture2 ) ) )
	{
		return E_FAIL;
	}
	
	ChangeBackground("denis keller.jpg");
	
	if (FAILED(D3DXCreateSprite(pD3DDevice,&sprite)))
	{
		// created OK]
		return E_FAIL;
	}
	
	return TRUE; // Initialization Went OK
}

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE) 
struct CUSTOMVERTEX 
{ 
	
	FLOAT x, y, z, rhw; // The transformed position for the vertex. 
	
	DWORD color; // The vertex color. 
	
}; 






//注意顶点格式申明
struct VertexType
{
	D3DVECTOR	pos;		//位置
	FLOAT		rhw;		//在屏幕上绘制必须的
	DWORD		clr;		//颜色
};
#define MYFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

//绘制两条不连续的线
VertexType	line_list[4] = 
{
	{0,0,0,1.0f,0xFFFF00FF},
	{400,0,0,1.0f,0xFFFF00FF},
	{0,400,0,1.0f,0xFFFF0000},
	{400,400,0,1.0f,0xFFFFFFFF},
};

VertexType tri_list1[6] = 
{
	{0,0,0,1.0f,0xFFFF00FF},
	{400,0,0,1.0f,0xFFFF00FF},
	{0,400,0,1.0f,0xFFFF0000},
	{0,400,0,1.0f,0xFFFF0000},
	{400,0,0,1.0f,0xFFFF00FF},
	{400,400,0,1.0f,0xFFFFFFFF},
};

VertexType tri_list[6] = 
{
	{400,0,0,1.0f,0xFFFF00FF},
	{0,0,0,1.0f,0xFFFF00FF},
	{0,400,0,1.0f,0xFFFF0000},
	{400,0,0,1.0f,0xFFFF00FF},
	{0,400,0,1.0f,0xFFFF0000},
	{400,400,0,1.0f,0xFFFFFFFF},
};


int DrawD3DScene()// Here's Where We Do All The Drawing
{
	
	
	VertexType points[] = {
		{{1,2,0},1.0f,0XFFFFFFFF},
		{{1,1,1},1.0f,0XFFFFFFFF},
	};
	//IDirect3DDevice9::DrawPrimitiveUP(D3DPT_POINTLIST,2,points,sizeof(VertexType));
	
	pD3DDevice->Clear( 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, // Clear Screen And Depth Buffer
		D3DCOLOR_COLORVALUE(1.0f,1.0f,1.0f,1.0f), 1.0f, 0 );
	
	pD3DDevice->BeginScene();
	/*here will be the code for 3d*/



	D3DXVECTOR2 center(0.5f,0.5f);
	D3DXVECTOR2 center2(0.5f,0.5f);
	D3DXVECTOR2 scaling(1.33f,1.0);
	D3DXVECTOR2 scaling2(1.0f,1.0);
	D3DXVECTOR2 trans(100.0f,100.0f);
	
	RECT rect;
	rect.left = 0;
	rect.right =640;
	rect.top = 0;
	rect.bottom =480;
	
	RECT rect2;
	rect2.left = 0;
	rect2.right =200;
	rect2.top = 0;
	rect2.bottom =200;

	sprite->Begin();
	sprite->Draw(g_pTexture2,&rect2,&scaling2,&center2,0.0f,&trans,0xf0FFFFFF);
	sprite->Draw(g_pTexture,&rect,&scaling,&center,0.0f,NULL,0x44ffffff);	
	sprite->End();
	
	pD3DDevice->EndScene();
	
	pD3DDevice->Present( NULL, NULL, NULL, NULL );// Display Result
	
	return TRUE;// Keep Going
}


/*

  
	
	  HRESULT DrawPrimitiveUP(
	  D3DPRIMITIVETYPE PrimitiveType,
	  UINT PrimitiveCount,
	  CONST void* pVertexStreamZeroData,
	  UINT VertexStreamZeroStride
	  );
	  
		
		  
*/







void KillD3DWindow()// Properly Kill The Window
{
	
	if( sprite != NULL )
		sprite->Release();
	
	
	if( g_pTexture != NULL )
		g_pTexture->Release();
	
	if (pD3DDevice != NULL)pD3DDevice->Release();// Release D3D Device
	
	if (pD3D != NULL) pD3D->Release();// Release D3D Interface
	
	if (fullscreen)// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL,0);// If So Switch Back To The Desktop
		ShowCursor(TRUE);// Show Mouse Pointer
	}
	
	if (hDC && !ReleaseDC(hWnd,hDC))// Are We Able To Release The DC
	{
		MessageBox(NULL,"Release Device Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hDC=NULL;// Set DC To NULL
	}
	
	if (hWnd && !DestroyWindow(hWnd))// Are We Able To Destroy The Window?
	{
		MessageBox(NULL,"Could Not Release hWnd.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hWnd=NULL;// Set hWnd To NULL
	}
	
	if (!UnregisterClass("Direct3D",hInstance))// Are We Able To Unregister Class
	{
		MessageBox(NULL,"Could Not Unregister Class.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hInstance=NULL;// Set hInstance To NULL
	}
}

/*This Code Creates Our DirectX 3D Window. Parameters Are:*
*title- Title To Appear At The Top Of The Window*
*width- Width Of The D3D Window Or Fullscreen Mode*
*height- Height Of The D3D Window Or Fullscreen Mode*
*fullscreenflag- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)*/

BOOL CreateD3DWindow(char* title, int width, int height, bool fullscreenflag)
{
	WNDCLASS wc;
	DWORD dwExStyle;// Window Extended Style
	DWORD dwStyle;// Window Style
	RECT WindowRect;// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left=(long)0;// Set Left Value To 0
	WindowRect.right=(long)width;// Set Right Value To Requested Width
	WindowRect.top=(long)0;// Set Top Value To 0
	WindowRect.bottom=(long)height;// Set Bottom Value To Requested Height
	
	fullscreen=fullscreenflag;// Set The Global Fullscreen Flag
	
	hInstance= GetModuleHandle(NULL);// Grab An Instance For Our Window
	wc.style= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc= (WNDPROC) WndProc;// WndProc Handles Messages
	wc.cbClsExtra= 0;// No Extra Window Data
	wc.cbWndExtra= 0;// No Extra Window Data
	wc.hInstance= hInstance;// Set The Instance
	wc.hIcon= LoadIcon(NULL, IDI_WINLOGO);// Load The Default Icon
	wc.hCursor= LoadCursor(NULL, IDC_ARROW);// Load The Arrow Pointer
	wc.hbrBackground= NULL;// No Background Required For D3D
	wc.lpszMenuName= NULL;// We Don't Want A Menu
	wc.lpszClassName= "Direct3D";// Set The Class Name
	
	if (!RegisterClass(&wc))// Attempt To Register The Window Class
	{
		MessageBox(NULL,"Failed To Register The Window Class.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;// Return FALSE
	}
	
	if (fullscreen)// Fullscreen Mode?
	{
		dwExStyle=WS_EX_APPWINDOW;// Window Extended Style
		dwStyle=WS_POPUP;// Windows Style
		ShowCursor(FALSE);// Hide Mouse Pointer
	}
	else
	{
		dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;// Window Extended Style
		dwStyle=WS_OVERLAPPEDWINDOW;// Windows Style
	}
	
	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);// Adjust Window To True Requested Size
	
	// Create The Window
	if (!(hWnd=CreateWindowEx(dwExStyle,// Extended Style For The Window
		"Direct3D",// Class Name
		title,// Window Title
		dwStyle |// Defined Window Style
		WS_CLIPSIBLINGS |// Required Window Style
		WS_CLIPCHILDREN,// Required Window Style
		0, 0,// Window Position
		WindowRect.right-WindowRect.left,// Calculate Window Width
		WindowRect.bottom-WindowRect.top,// Calculate Window Height
		NULL,// No Parent Window
		NULL,// No Menu
		hInstance,// Instance
		NULL)))// Dont Pass Anything To WM_CREATE
	{
		KillD3DWindow();// Reset The Display
		MessageBox(NULL,"Window Creation Error.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;// Return FALSE
	}
	
	if (!(hDC=GetDC(hWnd)))// Did We Get A Device Context?
	{
		KillD3DWindow();// Reset The Display
		MessageBox(NULL,"Can't Create A Device Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;// Return FALSE
	}
	
	pD3D = Direct3DCreate9( D3D_SDK_VERSION );// Check For The Correct DirectX 3D version
	if ( pD3D == NULL )
	{
		KillD3DWindow();// Reset The Display
		MessageBox(NULL,"Can't find D3D SDK Version 9.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;// Return FALSE
	}
	
	D3DPRESENT_PARAMETERS d3dpp=// d3dpp Tells Windows How We Want Things To Be
	{
		width,// Back Buffer Width
			height,// Back Buffer Height
			D3DFMT_R5G6B5,// Back Buffer Format (Color Depth)
			1,// Back Buffer Count (Double Buffer)
			D3DMULTISAMPLE_NONE,// No Multi Sample Type
			0,// No Multi Sample Quality
			D3DSWAPEFFECT_DISCARD,// Swap Effect (Fast)
			hWnd,// The Window Handle
			!fullscreen,// Windowed or Fullscreen
			TRUE,// Enable Auto Depth Stencil
			D3DFMT_D16,// 16Bit Z-Buffer (Depth Buffer)
			0,// No Flags
			D3DPRESENT_RATE_DEFAULT,// Default Refresh Rate
			D3DPRESENT_INTERVAL_DEFAULT// Default Presentation Interval (vertical sync)
	};
	
	// Check The Wanted Surface Format.
	if ( FAILED( pD3D->CheckDeviceFormat( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,
		d3dpp.BackBufferFormat, D3DUSAGE_DEPTHSTENCIL,
		D3DRTYPE_SURFACE, d3dpp.AutoDepthStencilFormat ) ) )
	{
		KillD3DWindow();// Reset The Display
		MessageBox(NULL,"Can't Find Surface Format.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;// Return FALSE
	}
	
	// Create The DirectX 3D Device
	if(FAILED( pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &pD3DDevice ) ) )
	{
		KillD3DWindow();// Reset The Display
		MessageBox(NULL,"Can't Create DirectX 3D Device.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;// Return FALSE
	}
	
	ShowWindow(hWnd,SW_SHOW);// Show The Window
	SetForegroundWindow(hWnd);// Slightly Higher Priority
	SetFocus(hWnd);// Sets Keyboard Focus To The Window
	ResizeD3DScene(width, height);// Set Up Our Perspective D3D Screen
	
	if (!InitD3D())// Initialize Our Newly Created D3D Window
	{
		KillD3DWindow();// Reset The Display
		MessageBox(NULL,"Initialization Failed.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;// Return FALSE
	}
	/*
	InitVB();
	*/
	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd,
						 UINT uMsg,
						 WPARAM wParam,
						 LPARAM lParam )
{
	switch( uMsg )
	{
	case WM_ACTIVATE:// Watch For Window Activate Message
		{
			if (!HIWORD(wParam))// Check Minimization State
			{
				active=TRUE;// Program Is Active
			}
			else
			{
				active=FALSE;// Program Is No Longer Active
			}
			
			return 0;// Return To The Message Loop
		}
		
	case WM_SYSCOMMAND:// Intercept System Commands
		{
			switch (wParam)// Check System Calls
			{
			case SC_SCREENSAVE:// Screensaver Trying To Start?
			case SC_MONITORPOWER:// Monitor Trying To Enter Powersave?
				return 0;// Prevent From Happening
			}
			break;// Exit
		}
		
	case WM_CLOSE:// Did We Receive A Close Message?
		{
			PostQuitMessage(0);// Send A Quit Message
			return 0;// Jump Back
		}
		
	case WM_KEYDOWN:// Is A Key Being Held Down?
		{
			keys[wParam] = TRUE;// If So, Mark It As TRUE
			return 0;// Jump Back
		}
		
	case WM_KEYUP:// Has A Key Been Released?
		{
			keys[wParam] = FALSE;// If So, Mark It As FALSE
			return 0;// Jump Back
		}
		
	case WM_SIZE:// Resize The Direct3D Window
		{
			if(!fullscreen)
				ResizeD3DScene(LOWORD(lParam), HIWORD(lParam)); // LoWord=Width, HiWord=Height
			return 0;// Jump Back
		}
	}
	
	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

int WINAPI WinMain( HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine,
				   int nCmdShow )
{
	
	MSG msg;
	BOOL done=FALSE;// Bool Variable To Exit Loop
	
	// Ask The User Which Screen Mode They Prefer
	/*
	if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
	fullscreen=FALSE;// Windowed Mode
	}
	*/
	fullscreen=FALSE;
	// Create Our DirectX 3D Window
	if (!CreateD3DWindow("Apron Tutorials Direct3D Framework",640,480,fullscreen))
	{
		return 0;// Quit If Window Was Not Created
	}
	
	while(!done)// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))// Is There A Message Waiting?
		{
			if (msg.message==WM_QUIT)// Have We Received A Quit Message?
			{
				done=TRUE;// If So done=TRUE
			}
			else// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);// Translate The Message
				DispatchMessage(&msg);// Dispatch The Message
			}
		}
		else// If There Are No Messages
		{
			// Draw The Scene. Watch For ESC Key And Quit Messages From DrawD3DScene()
			if ((active && !DrawD3DScene()) || keys[VK_ESCAPE])// Active? Was There A Quit Received?
			{
				done=TRUE;// ESC or DrawD3DScene Signalled A Quit
			}
			
			if (keys['F'])// Is F1 Being Pressed?
			{
				keys['F']=FALSE;// If So Make Key FALSE
				KillD3DWindow();// Kill Our Current Window
				fullscreen=!fullscreen;// Toggle Fullscreen / Windowed Mode
				// Recreate Our DirectX 3D Window
				if (!CreateD3DWindow("Apron Tutorials Direct3D Framework",640,480,fullscreen))
				{
					return 0;// Quit If Window Was Not Created
				}
			}
			if (keys['H'])// Is F1 Being Pressed?
			{
				keys['H']=FALSE;// If So Make Key FALSE
				//::ChangeBackground("image2.jpg");
				SwitchBackground();
			}
			
		}
	}
	
	// Shutdown
	KillD3DWindow();
	return (msg.wParam);// Exit The Program
}

#if 0	
	if(0){
		
		pD3DDevice->SetTextureStageState(0,D3DTSS_COLOROP,D3DTOP_SELECTARG2);	//选择参数二作为颜色结果
		pD3DDevice->SetTextureStageState(0,D3DTSS_COLORARG1,D3DTA_TEXTURE);	//参数一设置成纹理
		pD3DDevice->SetTextureStageState(0,D3DTSS_COLORARG2,D3DTA_DIFFUSE);	//参数二设置成color
		
		//设置Alpha如何操作
		//pD3DDevice->SetTextureStageState(0,D3DTSS_ALPHAOP,D3DTOP_MODULATE);	//参数一 * 参数二 作为Alpha结果
		pD3DDevice->SetTextureStageState(0,D3DTSS_ALPHAOP,D3DTOP_SELECTARG2);	//选择参数二作为Alpha结果
		pD3DDevice->SetTextureStageState(0,D3DTSS_ALPHAARG1,D3DTA_TEXTURE);	//参数一设置成纹理
		pD3DDevice->SetTextureStageState(0,D3DTSS_ALPHAARG2,D3DTA_DIFFUSE);	//参数二设置成color
		
		//禁止更高层的颜色和Alpha操作
		pD3DDevice->SetTextureStageState(1,D3DTSS_COLOROP,D3DTOP_DISABLE);
		pD3DDevice->SetTextureStageState(1,D3DTSS_ALPHAOP,D3DTOP_DISABLE);
		pD3DDevice->SetTextureStageState(0,D3DTSS_ALPHAOP,D3DTOP_MODULATE);
	}
	
	

	pD3DDevice->SetFVF(MYFVF);
	pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST,2,line_list,sizeof(VertexType));
	pD3DDevice->DrawPrimitiveUP(D3DPT_LINESTRIP,3,line_list,sizeof(VertexType));
	pD3DDevice->DrawPrimitiveUP(D3DPT_POINTLIST,4,line_list,sizeof(VertexType));
	pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,1,line_list,sizeof(VertexType));
	pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,2,line_list,sizeof(VertexType));
	
	pD3DDevice->SetTextureStageState(0,D3DTSS_COLOROP,D3DTOP_MODULATE);	//参数一 * 参数二 作为颜色结果
	pD3DDevice->SetTextureStageState(0,D3DTSS_ALPHAOP,D3DTOP_MODULATE);	//参数一 * 参数二 作为Alpha结果
	
	//设置纹理
	pD3DDevice->SetTexture(0,g_pTexture);
	//绘制两个三角形.一个三角形占三个顶点
	//关闭背面剪裁
	pD3DDevice->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE);
	
	pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,2,tri_list,sizeof(VertexType));
	
#endif



