#include "Plane.h"

void Plane::SetMatrix() {
	for (int i = 0; i < 2;++i) {
		camera->SetCameraMatrix(&(TriangleArray[i].transform.CameraMatrix));
		camera->SetPerspective(&(TriangleArray[i].transform.PerspectiveMatrix));
		camera->SetView(&(TriangleArray[i].transform.ViewMatrix));
	}
}

void Plane::Conversion() {
	for (int i = 0; i < 2; ++i) {
		TriangleArray[i].transform.LocalToWorld();
		TriangleArray[i].transform.WorldToCamera();
		//CullBack(TriangleArray[i]);//½øÐÐ±³ÃæÌÞ³ý
		TriangleArray[i].transform.CameraToPerspective();
		TriangleArray[i].transform.PerspectiveToView();
	}
}

void Plane::CullBack(PolyGon3D& Tringle) {
	Vector4D p1 = Tringle.transform.GetPointArray()[0].vt3D;
	Vector4D p2 = Tringle.transform.GetPointArray()[1].vt3D;
	Vector4D p3 = Tringle.transform.GetPointArray()[2].vt3D;

	Vector4D v1, v2, normal,view;

	v1 = p2 - p1;
	v2 = p3 - p2;
	normal = v2.Cross(v1);

	view = p1 - camera->pos;

	float pd = view.dot(normal);
	if (pd<=0) {
		Tringle.CullState = CULLSTATE::CULLBACK;
	}

}

Plane::~Plane()
{
}
