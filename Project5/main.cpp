#include "MindWin.h"
#include"MyMath.h"
#include "resource.h"
#include"Graphics.h"
using namespace std;


int WINAPI WinMain(HINSTANCE hinstance,HINSTANCE hprev,LPSTR lpcmdline,int ncmdshow) {
	MindWin* WIN = new MindWin(true);

	WIN->Init(hinstance,hprev,lpcmdline,ncmdshow);

	return 0;
}