#include "Transform.h"

Transform::Transform(){
	
}

void Transform::Rotate2D(const Vector2D& vct) {
	
}

void Transform::LocalToWorld() {
	//加入第一个变换后的位置，局部转换世界坐标
	ChangePositionArray.push_back((Position+localPosition));
	vector<Point>::iterator temp = PointArray.begin();//获取第一个点
	for (; temp != PointArray.end();++temp) {
		temp->vt3D +=ChangePositionArray[0].vt3;
	}
}

void Transform::WorldToCamera() {
	//加入第二个变换后的位置，世界坐标转换到相机空间
	Vector4D t = CameraMatrix * ChangePositionArray[0];
	ChangePositionArray.push_back(t);
	vector<Point>::iterator temp = PointArray.begin();//获取第一个点
	for (; temp != PointArray.end(); ++temp) {
		temp->vt3D += ChangePositionArray[1].vt3;
	}
}

void Transform::CameraToPerspective() {
	//加入第三个变换后的位置，相机空间转换到透视空间
	Vector4D t = PerspectiveMatrix * ChangePositionArray[1];
	t.vt3.Norm();
	ChangePositionArray.push_back(t);
	vector<Point>::iterator temp = PointArray.begin();//获取第一个点
	for (; temp != PointArray.end(); ++temp) {
		temp->vt3D += ChangePositionArray[2].vt3;
	}
}

//透视投影转换到屏幕坐标
void Transform::PerspectiveToView() {
	//加入第三个变换后的位置，相机空间转换到透视空间
	Vector4D t = ViewMatrix * ChangePositionArray[2];
	ChangePositionArray.push_back(t);
	vector<Point>::iterator temp = PointArray.begin();//获取第一个点
	for (; temp != PointArray.end(); ++temp) {
		temp->vt3D += ChangePositionArray[3].vt3;
	}
}

void  Transform::Move(const Vector3D& vt3d) {
	vector<Point>::iterator t = PointArray.begin();
	for (; t != PointArray.end(); ++t) {
		t->vt3D += vt3d;
	}
}

Transform::~Transform()
{

}
