#pragma once
#include"Common.h"
#include "Graphics.h"
class MindWin{
public:
	MindWin() :IsCreateDebug(false) {}
	MindWin(bool _isCreateDebug) :IsCreateDebug(_isCreateDebug) {}
	void Init(HINSTANCE _hinstance, HINSTANCE hprev, LPSTR lpcmdline, int ncmdshow);

	~MindWin();
private:
	static LRESULT CALLBACK WindowProc(HWND _hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
private:
	HINSTANCE hinstace;
	HWND hwnd;
	HDC WinDC;
	bool IsCreateDebug;//是否建立控制台
};

