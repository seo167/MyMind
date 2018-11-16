#include "GameObject.h"

GameObject::GameObject(string _name, const Vector4D& _worldPosition){
	name = _name;
	transform.Position = _worldPosition;
}

void GameObject::LocalToWorld() {
	transform.LocalToWorld();
	vector<Point>::iterator t= PixVector.begin();
	for (; t != PixVector.end();++t) {
		t->vt3D += transform.changePosition.vt3;
	}
}

void  GameObject::Move(const Vector3D& vt3d) {
	vector<Point>::iterator t = PixVector.begin();
	for (; t != PixVector.end(); ++t) {
		t->vt3D += vt3d;
	}
}

void GameObject::SetObjectPixel2D(int x, int y, MColor color) {
	int worldCenterX = WIDTH / 2;//世界坐标轴中心X轴
	int worldCenterY = HEIGHT / 2;//世界坐标轴中心Y轴

	Point p(color, x, y,0);
	PixVector.push_back(p);
}

void GameObject::FillTopTriangle(Point p1, Point p2, Point p3, MColor color) {
	Point Left(MColor(255,255,255));
	Point Right(MColor(255, 255, 255));
	Point Top(MColor(255, 255, 255));

	if (p1.vt3D.y==p2.vt3D.y) {
		Left = p1;
		Right = p2;
		Top = p3;
	}else if (p2.vt3D.y==p3.vt3D.y) {
		Left = p2;
		Right = p3;
		Top = p1;
	}else{
		Left = p1;
		Right = p3;
		Top = p2;
	}
	if (Left.vt3D.x>Right.vt3D.x) {
		swap(Left,Right);
	}

	float dxLeft=(Top.vt3D.x-Left.vt3D.x)/(Top.vt3D.y-Left.vt3D.y);
	float dxRight= (Right.vt3D.x - Top.vt3D.x)/( Right.vt3D.y - Top.vt3D.y);
	float xLeft = Left.vt3D.x;
	float xRight = Right.vt3D.x;
	int y = Left.vt3D.y;

	for (; y <=Top.vt3D.y;++y) {
		Graphics::DrawBresenhamLine((int)(xLeft+0.5),y,(int)(xRight+0.5),y,&(Left.color));
		xLeft += dxLeft;
		xRight += dxRight;
	}
}

void GameObject::FillBottomTriangle(Point p1, Point p2, Point p3, MColor color) {
	Point Left(MColor(255, 255, 255));
	Point Right(MColor(255, 255, 255));
	Point Top(MColor(255, 255, 255));

	if (p2.vt3D.y == p3.vt3D.y) {
		Left = p2;
		Right = p3;
		Top = p1;
	}else if (p1.vt3D.y==p2.vt3D.y) {
		Left = p1;
		Right = p2;
		Top = p3;
	}else {
		Left = p1;
		Right = p3;
		Top = p2;
	}

	if (Left.vt3D.x>Right.vt3D.x) {
		swap(Left,Right);
	}


	float dxLeft = (Left.vt3D.x - Top.vt3D.x) / (Left.vt3D.y - Top.vt3D.y);
	float dxRight = (Top.vt3D.x - Right.vt3D.x) / (Top.vt3D.y - Right.vt3D.y);
	float xLeft = Top.vt3D.x;
	float xRight = Top.vt3D.x;
	int y = Top.vt3D.y;

	for (; y <=Left.vt3D.y;++y) {
		Graphics::DrawBresenhamLine((int)(xLeft+0.5),y,(int)(xRight+0.5),y,&p1.color);
		xLeft += dxLeft;
		xRight += dxRight;
	}
}

//画三角形
void GameObject::DrawTriangle() {
	vector<Point>::iterator temp1 = PixVector.begin();//x0，y0点
	vector<Point>::iterator temp2 = PixVector.begin();//x1，y1点
	int x1, x2, y1, y2;
	while (true) {
		++temp2;
		if (temp2 == PixVector.end()) {
			break;
		}
		x1 = temp1->vt3D.x;
		y1 = temp1->vt3D.y;
		x2 = temp2->vt3D.x; 
		y2 = temp2->vt3D.y;
		if (Graphics::ClipLine(x1, y1, x2, y2)) {
			Graphics::DrawBresenhamLine(x1, y1, x2, y2, &(temp1->color));
		}
		
		++temp1;
	}
	temp2 = PixVector.begin();
	x1 = temp1->vt3D.x;
	y1 = temp1->vt3D.y;
	x2 = temp2->vt3D.x; 
	y2 = temp2->vt3D.y;
	if (Graphics::ClipLine(x1, y1, x2, y2)) {
		Graphics::DrawBresenhamLine(x1, y1, x2, y2, &(temp1->color));
	}
	

	
	TriangleCount += 1;
}

GameObject::~GameObject(){
	name.empty();
}
