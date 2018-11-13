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

//int main() {
//	float a[3][3] = {
//		{1,1,1},
//		{2,2,2},
//		{3,3,3}
//	};
//
//	Matrix3X3 m(*a);
//	Matrix3X3 m1(*a);
//
//	Matrix3X3 k = 2*(m*m1);
//	for (int i = 0; i < 3; ++i) {
//		for (int j = 0; j < 3; ++j) {
//			cout << k.m[i][j]<<" ";
//		}
//		cout << endl;
//	}
//
//	system("Pause");
//	return 0;
//}