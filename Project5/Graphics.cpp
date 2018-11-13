#include "Graphics.h"
#include<cmath>

using namespace std;
HDC Graphics::MindHdc;//Mind设备
HBITMAP Graphics::hCompatibleBitmap;//Mind的帧缓存
DIBSECTION Graphics::MindDIBSection;
void* Graphics::Data;//存储的数据
int Graphics::Pitch;//屏幕一行的总字节
RECT Graphics::rect;//规划一个矩形，充当屏幕坐标
HPEN Graphics::pen;
HBRUSH Graphics::brush;
float* Graphics::zBuffer;//深度缓存区

void Graphics::Init() {
	//获取一个屏幕设备表,传NULL会获得和屏幕一样大的DC
	MindHdc = CreateCompatibleDC(NULL);
	
	BITMAPINFO bitInfo = {0};
	bitInfo.bmiHeader.biSize = sizeof(bitInfo.bmiHeader);
	bitInfo.bmiHeader.biBitCount = 32;
	bitInfo.bmiHeader.biCompression = BI_RGB;
	bitInfo.bmiHeader.biPlanes = 1;
	bitInfo.bmiHeader.biWidth=WIDTH;
	bitInfo.bmiHeader.biHeight=HEIGHT;
	bitInfo.bmiHeader.biSizeImage=WIDTH*HEIGHT*4;

	//该指针主要用于接收位图位数
	void* pBit = NULL;
	//获取兼容HDC和兼容Bitmap,兼容Bitmap选入兼容HDC
	hCompatibleBitmap =CreateDIBSection(MindHdc,&bitInfo,DIB_RGB_COLORS, &pBit,NULL,0);
	//选择MaindBuffer来使用
	SelectObject(MindHdc, hCompatibleBitmap);
	
	//将MindHdc写入到MindDIBSection
	GetObject(MindHdc,sizeof(DIBSECTION),&MindDIBSection);

	
	Data = MindDIBSection.dsBm.bmBits;
	Pitch = MindDIBSection.dsBm.bmWidthBytes;

	//设置一个矩阵范围
	SetRect(&rect,0,0,WIDTH,HEIGHT);

	//创建笔和笔刷
	pen = CreatePen(PS_SOLID,1,RGB(0,0,0));
	//选择该画笔来使用
	SelectObject(MindHdc, pen);

	brush = CreateSolidBrush(RGB(0,0,0));
	//选择该笔刷来使用
	SelectObject(MindHdc, brush);
	
	//将深度缓存设置成0
	zBuffer = new float[WIDTH*HEIGHT];
	memset(zBuffer,0,(WIDTH*HEIGHT*sizeof(float)));
}

void Graphics::ClearZBuffer() {
	ClearBuffer();
	memset(zBuffer, 0, (WIDTH*HEIGHT * sizeof(float)));
}

void Graphics::FillBuffer(HDC hdc) {
	//将MindHdc所绘制的传入hdc入面
	BitBlt(hdc, 0, 0, WIDTH, HEIGHT, MindHdc, 0, 0, SRCCOPY);
}

void Graphics::DrawDDLine(int x0, int y0, int x1, int y1, const MColor* _color) {
	float dx, dy, xInc, yInc, Step;

	dx = x1 - x0;
	dy = y1 - y0;

	float fbsDx = fabs(dx), fbsDy = fabs(dy);

	if (fbsDx > fbsDy)
		Step = fbsDx;
	else
		Step = fbsDy;

	xInc = dx / Step;//如果dx>dy,xInc=1,否则等于0
	yInc = dy / Step;//如果dx>dy,yInc=m,否则等于1

	float x = x0;
	float y = y0;

	SetPixel(MindHdc, x, y, RGB(_color->r,_color->g,_color->b));

	for (int i = 0; i < Step; ++i) {
		x += xInc;
		y += yInc;
		SetPixel(MindHdc, x, y, RGB(_color->r, _color->g, _color->b));

	}
}
//采用Bresenham画线
void Graphics::DrawBresenhamLine(int x0, int y0, int x1, int y1, const MColor* _color) {
	int dx, dy, Inc, p0, x, y;
	dx = x1 - x0;
	dy = y1 - y0;

	//主要用来判断象限
	if (dx*dy > 0) {
		Inc = 1;
	}
	else {
		Inc = -1;
	}

	if (fabs(dx) > fabs(dy)) {
		int twoDy = 2 * fabs(dy);
		int twoDyMinDx = 2 * (fabs(dy) - fabs(dx));
		p0 = twoDy - fabs(dx);

		if (x0 > x1) {
			x = x1;
			y = y1;
			x1 = x0;
		}
		else {
			x = x0;
			y = y0;
		}
		SetPixel(MindHdc, x, y, RGB(_color->r,_color->g,_color->b));
		while (x < x1) {
			++x;
			if (p0 < 0) {
				p0 += twoDy;
			}
			else {
				y += Inc;
				p0 += twoDyMinDx;
			}
			SetPixel(MindHdc, x, y, RGB(_color->r, _color->g, _color->b));
		}

	}
	else {
		int twoDx = 2 * fabs(dx);
		int twoDxMinDy = 2 * (fabs(dx) - fabs(dy));
		p0 = twoDx - fabs(dy);

		if (y0 > y1) {
			x = x1;
			y = y1;
			y1 = y0;
		}
		else {
			x = x0;
			y = y0;
		}
		SetPixel(MindHdc, x, y, RGB(_color->r, _color->g, _color->b));
		while (y < y1) {
			++y;
			if (p0 < 0) {
				p0 += twoDx;
			}
			else {
				x += Inc;
				p0 += twoDxMinDy;
			}
			SetPixel(MindHdc, x, y, RGB(_color->r, _color->g, _color->b));
		}

	}
}

void Graphics::DrawPoint(int x, int y, const MColor* color) {
	SetPixel(MindHdc,x,y,RGB(color->r,color->g,color->b));
}

void Graphics::ClearBuffer() {
	FillRect(MindHdc, &rect, brush);
}
