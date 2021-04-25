
/*
	BasicWindowsApp.cpp by Vincent Roy, Given Under MIT, taken from Frank Luna anexe.

	Shows the minimal ammount of Win32 code needed for Direct3D programming. 
	
	I made this just so i can experience how to start a win32 project for DirectX from scratch
*/


// This has all the win32 API, framework.h can be used instead.
#include "windows.h"

// The main window handle; this is used to idebtify a created window.
HWND ghMainWnd = 0;

// Wraps the code required to initialize a Windows application.
// Function returns if initialization succeeded, otherwise it returns false.
bool InitWindowsApp(HINSTANCE instanceHandle, int show);

// Wraps the message loop code.
int Run();

// The window procedure handles events our app window receives.
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// The Windows equivalent to main()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nShowCmd)
{
	// Initilize the the main window
	if (!InitWindowsApp(hInstance, nShowCmd))
		return 0;

	//Enter the message loop until WM_QUIT is received
	return Run();
}

bool InitWindowsApp(HINSTANCE instanceHandle, int show)
{
	// We describe the window through WNDCLASS
	WNDCLASS wc;

	wc.style			= CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc		= WndProc;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 0;
	wc.hInstance		= instanceHandle;
	wc.hIcon			= LoadIcon(0, IDI_APPLICATION);
	wc.hCursor			= LoadCursor(0, IDC_ARROW);
	wc.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName		= 0;
	wc.lpszClassName	= L"BasicWndClass";

	// Then, we register this WNDCLASS instance with Windows
	if (!RegisterClass(&wc))
	{
		MessageBox(0, L"RegisterClass FAILED", 0, 0);
		return false;
	}

	// Create the window and return its handle
	ghMainWnd = CreateWindow(
		L"BasicWndClass",	//Registered WNDCLASS instance to use
		L"BaseWin32App",	// window title
		WS_OVERLAPPEDWINDOW,// style flags
		CW_USEDEFAULT,		// x-coordinate
		CW_USEDEFAULT,		// y-coordinate
		CW_USEDEFAULT,		// width
		CW_USEDEFAULT,		// height
		0,					// Parent window, 0 is none
		0,					// menu handle, 0 is none
		instanceHandle,		// app instance
		0					// some extra creatiion parameters
	);

	if (ghMainWnd == 0)
	{
		MessageBox(0, L"CreateWindow FAILED", 0, 0);
		return false;
	}

	// The window that was created is not shown by default. We need to tell window show it AND update it.
	ShowWindow(ghMainWnd, show);
	UpdateWindow(ghMainWnd);

	return true;
}

int Run()
{
	MSG msg = { 0 };

	//Loop until we get a WM_QUIT message, it will return -1 if there is an error
	BOOL bRet = 1;
	while ((bRet = GetMessage(&msg, 0, 0, 0)) != 0)
	{
		if (bRet == -1)
		{
			MessageBox(0, L"GetMessage FAILED", L"Error", MB_OK);

			break;
		}
		else
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// Handle some specific message, we should return 0 for those

	switch (msg)
	{
		// When the left mouse button is pressed we then display a message.
	case WM_LBUTTONDOWN:
		MessageBox(0, L"Hello, World!", L"Hello", MB_OK);
		return 0;
		// In the case escape is pressed we destroy the main win
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			DestroyWindow(ghMainWnd);
		}
		return 0;
		// When receive destroy message, we send a quit message that will terminate the loop.
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	
	return DefWindowProc(hWnd, msg, wParam, lParam);
}