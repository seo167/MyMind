#include "Transform.h"

Transform::Transform(){
	WorldMatrix.Identity();
}

void Transform::Rotate2D(const Vector2D& vct) {
	
}

void Transform::LocalToWorld() {
	//加入第一个变换后的位置，局部转换世界坐标
	//ChangePositionArray.push_back((Position+localPosition));
	vector<Point>::iterator temp = PointArray.begin();//获取第一个点
	for (; temp != PointArray.end();++temp) {
		Vector4D t(temp->vt3D);
		t = t * WorldMatrix;
		temp->vt3D.x = t.x;
		temp->vt3D.y = t.y;
		temp->vt3D.z = t.z;
	}
}

void Transform::WorldToCamera() {
	//加入第二个变换后的位置，世界坐标转换到相机空间
	//ChangePositionArray.push_back(t);
	vector<Point>::iterator temp = PointArray.begin();//获取第一个点
	for (; temp != PointArray.end(); ++temp) {
		Vector4D t(temp->vt3D);
		t = t * CameraMatrix;
		temp->vt3D.x = t.x;
		temp->vt3D.y = t.y;
		temp->vt3D.z = t.z;
	}
}

void Transform::CameraToPerspective() {
	//加入第三个变换后的位置，相机空间转换到透视空间
	//Vector4D t = ChangePositionArray[1]*PerspectiveMatrix ;
	//ChangePositionArray.push_back(t);
	vector<Point>::iterator temp = PointArray.begin();//获取第一个点
	for (; temp != PointArray.end(); ++temp) {
		Vector4D t(temp->vt3D);
		t = t * PerspectiveMatrix;
		temp->vt3D.x = t.x;
		temp->vt3D.y = t.y;
		temp->vt3D.z = t.z;
		//temp->vt3D.Norm();
	}
}

//透视投影转换到屏幕坐标
void Transform::PerspectiveToView() {
	//加入第三个变换后的位置，相机空间转换到透视空间
	//Vector4D t = ViewMatrix * ChangePositionArray[2];
	//ChangePositionArray.push_back(t);
	vector<Point>::iterator temp = PointArray.begin();//获取第一个点
	for (; temp != PointArray.end(); ++temp) {
		Vector4D t(temp->vt3D);
		t = t * ViewMatrix;
		temp->vt3D.x = t.x;
		temp->vt3D.y = t.y;
		temp->vt3D.z = t.z;
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
