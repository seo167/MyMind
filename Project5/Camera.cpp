#include "Camera.h"

void Camera::SetLookAt(Vector3D eye, Vector3D _target) {
	target = _target;;
	n = _target - eye;
	v = Vector3D(0, 1, 0);
	u = v.Cross(n);
	v = n.Cross(u);

	n.Norm();
	u.Norm();
	v.Norm();
	pos = eye;

	InitTMat();
	InitRMat();
	
}

void Camera::SetPerspective(Matrix4X4 *PerspectiveMat) {
	//PerspectiveMat->Norm();
	PerspectiveMat->m[0][0] = distance;
	PerspectiveMat->m[1][1] = distance * ar;
	PerspectiveMat->m[2][3] = 1;
	PerspectiveMat->m[3][3] = 0;
}

void Camera::SetView(Matrix4X4 *ViewMat) {
	float alpha = (WIDTH-1) / 2;
	float beta = (HEIGHT-1)/ 2;
	ViewMat->Identity();
	ViewMat->m[0][0] = alpha;
	ViewMat->m[1][1] =beta;
	ViewMat->m[3][0] = alpha;
	ViewMat->m[3][1] = beta;
}


void Camera::InitTMat() {

	tMat.m[0][0] = tMat.m[1][1]
		= tMat.m[2][2] = tMat.m[3][3]
		= 1;
	tMat.m[3][0] = (-pos.x);
	tMat.m[3][1] = (-pos.y);
	tMat.m[3][2] = (-pos.z);

}

void Camera::InitRMat() {
	rMat.m[0][0] = u.x; rMat.m[1][0] = u.y; rMat.m[2][0] = u.z;
	rMat.m[0][1] = v.x; rMat.m[1][1] = v.y; rMat.m[2][1] = v.z;
	rMat.m[0][2] = n.x; rMat.m[2][1] = n.y; rMat.m[2][2] = n.z;
	rMat.m[3][3] = 1;
}


Camera::~Camera() {

}
