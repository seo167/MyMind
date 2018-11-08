#include "GameObject.h"

GameObject::GameObject(HWND _hwnd, string _name){
	mHdc = GetDC(_hwnd);
	name = _name;
}

void GameObject::SetObjectPixel2D(int x, int y, COLORREF color) {
	Point p(color,x,y,0.0);
	PixList.push_back(p);
}

//使用DD算法实现直线
void GameObject::DrawDDLine(int x0, int y0, int x1, int y1, COLORREF color) {

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

	SetPixel(mHdc, x, y, color);

	for (int i = 0; i < Step; ++i) {
		x += xInc;
		y += yInc;
		SetPixel(mHdc, x, y, color);

	}
}

//使用Bresemham算法实现直线
void GameObject::DrawBresenhamLine(int x0, int y0, int x1, int y1, COLORREF color) {
	int dx, dy, Inc, p0, x, y;
	dx = x1 - x0;
	dy = y1 - y0;

	//主要用来判断象限
	if (dx*dy > 0) {
		Inc = 1;
	}else {
		Inc = -1;
	}

	if (fabs(dx) > fabs(dy)) {
		int twoDy = 2 * fabs(dy);
		int twoDyMinDx = 2 * (fabs(dy) - fabs(dx));
		p0 = twoDy -fabs(dx);

		if (x0 > x1) {
			x = x1;
			y = y1;
			x1 = x0;
		}
		else {
			x = x0;
			y = y0;
		}
		SetPixel(mHdc, x, y, color);
		while (x < x1) {
			++x;
			if (p0 < 0) {
				p0 += twoDy;
			}
			else {
				y += Inc;
				p0 += twoDyMinDx;
			}
			SetPixel(mHdc, x, y, color);
		}

	}
	else {
		int twoDx = 2 * fabs(dx);
		int twoDxMinDy = 2 * (fabs(dx) - fabs(dy));
		p0 = twoDx -fabs(dy);

		if (y0 > y1) {
			x = x1;
			y = y1;
			y1 = y0;
		}
		else {
			x = x0;
			y = y0;
		}
		SetPixel(mHdc, x, y, color);
		while (y < y1) {
			++y;
			if (p0 < 0) {
				p0 += twoDx;
			}
			else {
				x += Inc;
				p0 += twoDxMinDy;
			}
			SetPixel(mHdc, x, y, color);
		}

	}

}

GameObject::~GameObject()
{
	name.empty();
	mHdc = NULL;
}
