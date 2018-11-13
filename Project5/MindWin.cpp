#include "MindWin.h"
#include"MyMath.h"
#include"PolyGon2D.h"
LRESULT CALLBACK MindWin::WindowProc(HWND _hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	float mouse_x, mouse_y;

	switch (msg) {
	case WM_LBUTTONDOWN:
		mouse_x = (float)LOWORD(lparam);
		mouse_y = (float)HIWORD(lparam);
		break;
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		break;
	default:
		return DefWindowProc(_hwnd, msg, wparam, lparam);
	}
	return 0;
}

void MindWin::Init(HINSTANCE _hinstance, HINSTANCE hprev, LPSTR lpcmdline, int ncmdshow) {
	
	if (IsCreateDebug) {
		AllocConsole();   // 建立控制台
		SetConsoleTitle("Debug Output");
	}
	WNDCLASS _WndClass;
	_WndClass.cbClsExtra = NULL;
	_WndClass.cbWndExtra = NULL;
	_WndClass.hbrBackground = HBRUSH(WHITE_BRUSH);
	_WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	_WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	_WndClass.hInstance = _hinstance;
	_WndClass.lpfnWndProc =(WNDPROC)(MindWin::WindowProc);
	_WndClass.lpszClassName = "Mind";
	_WndClass.lpszMenuName = NULL;
	_WndClass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClass(&_WndClass)) {
		return;
	}
	
	//创建Window窗口
	hwnd = CreateWindow("Mind", "Mind", WS_OVERLAPPEDWINDOW | WS_VISIBLE, (GetSystemMetrics(SM_CXSCREEN) - WIDTH) / 2, (GetSystemMetrics(SM_CYSCREEN) - HEIGHT) / 2, WIDTH, HEIGHT, NULL, NULL, _hinstance, NULL);

	if (!hwnd) {
		return;
	}

	
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);
	WinDC = GetDC(hwnd);
	MSG msg;
	Graphics::Init();

	PolyGon2D g(3, "SanJiaoXing",Vector4D(100,0,0));

	int m[3][2] = {
		{50,50},
		{0,100},
		{100,100}
	};

	g.SetPoint(*m, MColor(255, 255, 255));
	g.Draw();

	Graphics::FillBuffer(WinDC);
	
	//srand(time(NULL));
	while (GetMessage(&msg,NULL,0,0)) {
		/*if (PeekMessage(&msg,NULL,0,0,0)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			
		}
		Sleep(5000);*/
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		Graphics::ClearBuffer();
		//g.LocalToWorld();
		g.Draw();
		Sleep(500);
		Graphics::FillBuffer(WinDC);
		
	}
	
	return;
}

MindWin::~MindWin(){
	hinstace = NULL;
	hwnd = NULL;
	WinDC = NULL;
}
