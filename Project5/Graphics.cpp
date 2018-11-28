#include "Graphics.h"
#include<cmath>

using namespace std;
HDC Graphics::MindHdc;//Mind设备
HBITMAP Graphics::hCompatibleBitmap;//Mind的帧缓存
DIBSECTION Graphics::MindDIBSection;
float* Graphics::zBuffer;//深度缓存区
MColor* Graphics::FrameBuffer;//视频缓存

int Graphics::RectMaxX;
int Graphics::RectMinX;//矩形X轴最小
int Graphics::RectMaxY;//矩形Y轴最大
int Graphics::RectMinY;//矩形Y轴最小

int Graphics::ClipLeftTop = 0x1001;//左上角边界编码
int Graphics::ClipRightTop = 0x1010;//右上角边界编码
int Graphics::ClipTop = 0x1000;//上方边界编码
int Graphics::ClipLeft = 0x0001;//左方边界编码
int Graphics::ClipRight = 0x0010;//右方边界编码
int Graphics::ClipLeftBottom = 0x0101;//左下角边界编码
int Graphics::ClipBottom = 0x0100;//下方边界编码
int Graphics::ClipRightBottom = 0x0110;//右下角边界编码

void Graphics::Init() {
	//获取一个屏幕设备表,传NULL会获得和屏幕一样大的DC
	MindHdc = CreateCompatibleDC(NULL);
	FrameBuffer = new MColor[WIDTH*HEIGHT * sizeof(MColor)];
	BITMAPINFO bitInfo = {0};
	bitInfo.bmiHeader.biSize = sizeof(bitInfo.bmiHeader);
	bitInfo.bmiHeader.biBitCount = 32;
	bitInfo.bmiHeader.biCompression = BI_RGB;
	bitInfo.bmiHeader.biPlanes = 1;
	bitInfo.bmiHeader.biWidth=WIDTH;
	bitInfo.bmiHeader.biHeight=HEIGHT;
	bitInfo.bmiHeader.biSizeImage=WIDTH*HEIGHT*4;

	//获取兼容HDC和兼容Bitmap,兼容Bitmap选入兼容HDC
	hCompatibleBitmap =CreateDIBSection(MindHdc,&bitInfo,DIB_RGB_COLORS,(void**)&FrameBuffer,0,0);
	//选择MaindBuffer来使用
	SelectObject(MindHdc, hCompatibleBitmap);
	//将深度缓存设置成0
	zBuffer = new float[WIDTH*HEIGHT];
	memset(zBuffer,0,(WIDTH*HEIGHT*sizeof(float)));

	RectMaxX = WIDTH - 100;
	RectMinX = 100;
	RectMaxY = HEIGHT - 100;
	RectMinY = 50;
}

void Graphics::ClearZBuffer() {
	ClearBuffer();
	memset(zBuffer, 0, (WIDTH*HEIGHT * sizeof(float)));
}

void Graphics::FillBuffer(HDC hdc) {
	//将MindHdc所绘制的传入hdc入面
	BitBlt(hdc, 0, 0, WIDTH, HEIGHT, MindHdc, 0, 0, SRCCOPY);
}

void Graphics::DrawPoint(int x, int y, MColor _color) {
	if ((x<WIDTH)&&(y<HEIGHT)) {
		if (x < 0)
			x=abs(x);
		if (y < 0)
			y = abs(y);
		FrameBuffer[x +y * WIDTH]=_color;
	}
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

	xInc = dx / Step;//如果dx>dy,xInc=1,否则等于1/m
	yInc = dy / Step;//如果dx>dy,yInc=m,否则等于1

	float x = x0;
	float y = y0;

	DrawPoint(x, y, MColor(_color->r,_color->g,_color->b));

	for (int i = 0; i < Step; ++i) {
		x += xInc;
		y += yInc;
		DrawPoint(x, y, MColor(_color->r, _color->g, _color->b));

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

		DrawPoint(x, y, MColor(_color->r, _color->g, _color->b));
		while (x < x1) {
			++x;
			if (p0 < 0) {
				p0 += twoDy;
			}
			else {
				y += Inc;
				p0 += twoDyMinDx;
			}
			DrawPoint(x, y, MColor(_color->r, _color->g, _color->b));
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
		DrawPoint(x, y, MColor(_color->r, _color->g, _color->b));
		while (y < y1) {
			++y;
			if (p0 < 0) {
				p0 += twoDx;
			}
			else {
				x += Inc;
				p0 += twoDxMinDy;
			}
			DrawPoint(x, y, MColor(_color->r, _color->g, _color->b));
		}

	}
}

void Graphics::DrawPoint(int x, int y, const MColor* color) {
	SetPixel(MindHdc,x,y,RGB(color->r,color->g,color->b));
}

void Graphics::ClearBuffer() {
	memset(FrameBuffer, 0, sizeof(MColor)*WIDTH*HEIGHT);
}

void Graphics::DrawClipRect() {
	//绘画TopX
	DrawBresenhamLine(RectMinX, RectMinY, RectMaxX, RectMinY,new MColor(255,0,0));
	//绘画LeftY
	DrawBresenhamLine(RectMinX, RectMinY, RectMinX, RectMaxY,new MColor(255,0,0));
	//绘画BottomX
	DrawBresenhamLine(RectMinX, RectMaxY, RectMaxX, RectMaxY,new MColor(255,0,0));
	//绘画RightY
	DrawBresenhamLine(RectMaxX, RectMinY, RectMaxX, RectMaxY,new MColor(255,0,0));
}

bool Graphics::ClipLine(int &x0, int &y0, int &x1, int &y1) {
	int code1=0x0000, code2 = 0x0000;//获取边界编码

	int IntersectX, IntersectY = 0;//X,Y相交点

	//判断第一个点和第二个点在哪一个边界
	if (x0 < RectMinX)
		code1 |= ClipLeft;
	if (x0 > RectMaxX)
		code1 |= ClipRight;
	if (y0 > RectMaxY)
		code1 |= ClipBottom;
	if (y0 < RectMinY)
		code1 |= ClipTop ;
	if (x1 < RectMinX)
		code2 |= ClipLeft;
	if (x1 > RectMaxX)
		code2 |= ClipRight;
	if (y1 > RectMaxY)
		code2 |= ClipBottom ;
	if (y1 < RectMinY)
		code2 |= ClipTop;

	//if (code1==0&&code2==0)
	//	return true;

	int IntersectX1=x0, IntersectY1=y0, IntersectX2=x1, IntersectY2=y1;
	Clip(IntersectX1,IntersectY1,x0,x1,y0,y1,code1);
	Clip(IntersectX2, IntersectY2, x0, x1, y0, y1, code2);
	
	if ((IntersectX1<RectMinX)||(IntersectX1>RectMaxX)
		||(IntersectX2<RectMinX)||(IntersectX2>RectMaxX)
		||(IntersectY1<RectMinY)||(IntersectY2>RectMaxY)
		||(IntersectY2<RectMinY)||(IntersectY1>RectMaxY)) {
		return false;
	}
	x0 = IntersectX1;
	x1 = IntersectX2;
	y0 = IntersectY1;
	y1 = IntersectY2;
	return true;
}

void Graphics::Clip(int &IntersectX, int&IntersectY,const int& x0,const int& x1,const int& y0,const int& y1,const int &code) {
	//计算交点

	if (code == ClipLeftTop) {
		IntersectY = RectMinY;
		if ((y1 - y0 != 0)) {
			IntersectX = (int)((IntersectY - y0)*(x1 - x0) / (y1 - y0) + x0);
		}
		
		if (IntersectX<RectMinX || IntersectX>RectMaxX) {
			IntersectX = RectMinX;
			if ((x1 - x0 != 0)) {
				IntersectY = (int)((IntersectX - x0)*(y1 - y0) / (x1 - x0) + y0);
			}
		}
	}
	else if (code == ClipRightTop) {
		IntersectY = RectMinY;
		if ((y1 - y0 != 0)) {
			IntersectX = (int)((IntersectY - y0)*(x1 - x0) / (y1 - y0) + x0);
		}
		
		if (IntersectX<RectMinX || IntersectX>RectMaxX) {
			IntersectX = RectMaxX;
			if ((x1 - x0 != 0)) {
				IntersectY = (int)((IntersectX - x0)*(y1 - y0) / (x1 - x0) + y0);
			}
			
		}
	}
	else if (code == ClipTop) {
		IntersectY = RectMinY;
		if ((y1 - y0 != 0)) {
			IntersectX = (int)((IntersectY - y0)*(x1 - x0) / (y1 - y0) + x0);
		}
		
	}
	else if (code == ClipLeft) {
		IntersectX = RectMinX;
		if ((x1 - x0 != 0)) {
			IntersectY = (int)((IntersectX - x0)*(y1 - y0) / (x1 - x0) + y0);
		}
		
	}
	else if (code == ClipRight) {
		IntersectX = RectMaxX;
		if ((x1 - x0 != 0)) {
			IntersectY = (int)((IntersectX - x0)*(y1 - y0) / (x1 - x0) + y0);
		}
		
	}
	else if (code == ClipLeftBottom) {
		IntersectY = RectMaxY;
		if ((y1 - y0 != 0)) {
			IntersectX = (int)((IntersectY - y0)*(x1 - x0) / (y1 - y0) + x0);
		}
		
		if (IntersectX<RectMinX || IntersectX>RectMaxX) {
			IntersectX = RectMinX;
			if ((x1 - x0 != 0)) {
				IntersectY = (int)((IntersectX - x0)*(y1 - y0) / (x1 - x0) + y0);
			}
			
		}
	}
	else if (code == ClipBottom) {
		IntersectY = RectMaxY;
		if ((y1 - y0 != 0)) {
			IntersectX = (int)((IntersectY - y0)*(x1 - x0) / (y1 - y0) + x0);
		}
		
	}
	else if (code == ClipRightBottom) {
		IntersectY = RectMaxY;
		
		
		if (IntersectX<RectMinX || IntersectX>RectMaxX) {
			IntersectX = RectMaxX;
			if ((x1 - x0 != 0)) {
				IntersectY = (int)((IntersectX - x0)*(y1 - y0) / (x1 - x0) + y0);
			}
			
		}
	}
}
