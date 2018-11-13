#pragma once
#include"Common.h"

//颜色
struct MColor {
	unsigned char r, g, b, alpha;
	MColor(int _r, int _g, int _b, int _alpha = 255) {
		r = (unsigned char)((_r & 0xff0000 >> 16));
		g = (unsigned char)((_g & 0x00ff00 >> 8));
		b = (unsigned char)(_b & 0x0000ff);
		alpha = (unsigned char)alpha;
	}
};

//图形设备
class  Graphics{
public:
	static void Init();
	//清除深度缓冲区
	static void ClearZBuffer();

	//清除后备缓冲区
	static void ClearBuffer();

	//绘制缓冲区
	static void FillBuffer(HDC hdc);

	static void DrawDDLine(int x0, int y0, int x1, int y1, const MColor* _color);
	//采用Bresenham画线
	static void DrawBresenhamLine(int x0, int y0, int x1, int y1, const MColor* _color);

	static void DrawPoint(int x,int y,const MColor* color);

	~Graphics() {
		DeleteObject(MindHdc);
		DeleteObject(hCompatibleBitmap);
		DeleteObject(pen);
		DeleteObject(brush);
	}
private:
	static HDC MindHdc;//Mind设备
	static HBITMAP hCompatibleBitmap;//兼容Bitmap
	static DIBSECTION MindDIBSection;
	static void* Data;//存储的数据
	static int Pitch;//屏幕一行的总字节
	static RECT rect;//规划一个矩形，充当屏幕坐标
	static HPEN pen;
	static HBRUSH brush;
	static float* zBuffer;//深度缓存区
};
