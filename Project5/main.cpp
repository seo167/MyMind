#include<Windows.h>
#include<iostream>
#include"MyMath.h"
#include"GameObjectFactory.h"
#include"PolyGon2D.h"
#include "resource.h"
using namespace std;

const int WIDTH = 1440;
const int HEIGHT = 900;
HWND hwnd;
bool canDraw = true;

LRESULT CALLBACK WindowProc(HWND _hwnd,UINT msg,WPARAM wparam,LPARAM lparam) {
	HDC hdc = GetDC(hwnd);
	COLORREF color;
	float mouse_x,mouse_y;
	PolyGon2D SanJiaoXing(_hwnd, 4, "SanJiaoXing");
	int Vertex[4][2]{
				{500,500},
				{500,800},
				{800,800},
				{800,500}
	};
	switch (msg){
		case WM_LBUTTONDOWN:
			mouse_x = (float)LOWORD(lparam);
			mouse_y = (float)HIWORD(lparam);

			color = RGB(rand() % 255, rand() % 255, rand() % 255);
			SanJiaoXing.SetPoint(*Vertex,color);
			SanJiaoXing.Draw();
			break;
		case WM_DESTROY:
			PostQuitMessage(WM_QUIT);
			break;
		default:
			return DefWindowProc(_hwnd, msg, wparam, lparam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hinstance,HINSTANCE hprev,LPSTR lpcmdline,int ncmdshow) {
	
	AllocConsole();   // 建立控制台
	SetConsoleTitle("Debug Output");
	
	WNDCLASS _WndClass;
	_WndClass.cbClsExtra = NULL;
	_WndClass.cbWndExtra = NULL;
	_WndClass.hbrBackground = HBRUSH(WHITE_BRUSH);
	_WndClass.hCursor = LoadCursor(NULL,IDC_ARROW);
	_WndClass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	_WndClass.hInstance = hinstance;
	_WndClass.lpfnWndProc = WindowProc;
	_WndClass.lpszClassName = "Demo";
	_WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	_WndClass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClass(&_WndClass)) {
		return 0;
	}
	
	//创建Window窗口
	hwnd=CreateWindow("Demo","Demo",WS_OVERLAPPEDWINDOW|WS_VISIBLE, (GetSystemMetrics(SM_CXSCREEN) -WIDTH)/2,(GetSystemMetrics(SM_CYSCREEN)-HEIGHT)/2,WIDTH,HEIGHT,NULL,NULL,hinstance,NULL);

	if(!hwnd){
		return 0;
	}

	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	MSG msg;
	while (GetMessage(&msg,NULL,0,0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		
	}

	return 0;

}