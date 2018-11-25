#include "MyMath.h"

/*2D向量*/
const float Vector2D::VectorMag() {
	return sqrtf(this->x*this->x + this->y * this->y);
}

const void Vector2D::Norm() {

	if (this->x == 0 && this->y == 0)
		return;

	float tmp = sqrtf(this->x*this->x + this->y * this->y);

	if (tmp!=0)
		this->x /= tmp; this->y /=tmp;
}

const float Vector2D::Dot(const Vector2D& vt2D) {
	return this->x*vt2D.x+this->y*vt2D.y;
}


const Vector2D Vector2D::operator -(const Vector2D& vt2D)const {
	return Vector2D(this->x-vt2D.x, this->y-vt2D.y);
}

Vector2D Vector2D::operator -=(const Vector2D& vt2D) {
	this->x -= vt2D.x;
	this->y -= vt2D.y;
	return *this;
}

const Vector2D Vector2D::operator +(const Vector2D& vt2D)const {
	return Vector2D(this->x + vt2D.x, this->y + vt2D.y);
}

Vector2D& Vector2D::operator +=(const Vector2D& vt2D){
	this->x += vt2D.x;
	this->y += vt2D.y;
	return *this;
}

Vector2D& Vector2D::operator *=(const float& num) {
	this->x *= num;
	this->y *= num;
	return *this;
}

const Vector2D Vector2D::operator *(const float& num)const {
	return Vector2D(this->x * num, this->y * num);
}


Vector2D& Vector2D::operator /=(const float& num) {
	this->x /= num;
	this->y /= num;
	return *this;
}

const Vector2D Vector2D::operator /(const float& num)const {
	return Vector2D(this->x / num, this->y / num);
}

/*3D向量*/
const float Vector3D::VectorMag() {
	return sqrtf(this->x*this->x + this->y * this->y+this->z*this->z);
}

const void Vector3D::Norm() {

	if (this->x == 0 && this->y == 0&& this->z==0)
		return;

	float tmp = sqrtf(this->x*this->x + this->y * this->y+ this->z*this->z);

	if (tmp != 0)
		this->x /= tmp; this->y /= tmp; this->z /=tmp;
}

const float Vector3D::Dot(const Vector3D& vt3D) {
	return this->x*vt3D.x + this->y*vt3D.y+this->z*vt3D.z;
}

const Vector3D Vector3D::operator -(const Vector3D& vt3D)const {
	return Vector3D(this->x - vt3D.x, this->y - vt3D.y, this->z-vt3D.z);
}

Vector3D Vector3D::operator -=(const Vector3D& vt3D) {
	this->x -= vt3D.x;
	this->y -= vt3D.y;
	this->z -= vt3D.z;
	return *this;
}

const Vector3D Vector3D::operator +(const Vector3D& vt3D)const {
	return Vector3D(x + vt3D.x, y + vt3D.y,z+vt3D.z);
}

Vector3D& Vector3D::operator +=(const Vector3D& vt3D) {
	this->x += vt3D.x;
	this->y += vt3D.y;
	this->z += vt3D.z;
	return *this;
}

Vector3D& Vector3D::operator *=(const float& num) {
	this->x *= num;
	this->y *= num;
	this->z *= num;
	return *this;
}

const Vector3D Vector3D::operator *(const float& num)const {
	return Vector3D(this->x * num, this->y * num, this->z*num);
}


Vector3D& Vector3D::operator /=(const float& num) {
	this->x /= num;
	this->y /= num;
	this->z /= num;
	return *this;
}

const Vector3D Vector3D::operator /(const float& num)const {
	return Vector3D(this->x / num, this->y / num, this->z/num);
}

const Vector3D& Vector3D::operator =(const Vector3D& vt3D) {
	this->x = vt3D.x; this->y = vt3D.y; this->z = vt3D.z;
	return *this;
}

const Vector3D Vector3D::Cross(const Vector3D& vt3D) {
	int _x = this->y*vt3D.z - this->z*vt3D.y;
	int _y = this->z*vt3D.x - this->x*vt3D.z;
	int _z = this->x*vt3D.y - this->y*vt3D.x;
	return Vector3D(_x,_y,_z);
}

/*4D向量*/
const Vector4D Vector4D::operator -(const Vector4D& vt4D)const {
	return Vector4D(this->x-vt4D.x, this->y-vt4D.y, this->z-vt4D.z);
}

const Vector4D& Vector4D::operator -=(const Vector4D& vt4D) {
	this->x -=vt4D.x;
	this->y -= vt4D.y;
	this->z -= vt4D.z;
	return *this;
}

const Vector4D Vector4D::operator +(const Vector4D& vt4D)const {
	return Vector3D(this->x+vt4D.x, this->y+vt4D.y, this->z+vt4D.z);
}

Vector4D& Vector4D::operator +=(const Vector4D& vt4D) {
	this->x += vt4D.x;
	this->y += vt4D.y;
	this->z += vt4D.z;
	return *this;
}

Vector4D& Vector4D::operator *=(const float& num) {
	this->x *= num;
	this->y *= num;
	this->z *= num;
	return *this;
}

const Vector4D Vector4D::operator *(const float& num)const {
	return Vector4D(x*num,y*num,z*num);
}


Vector4D& Vector4D::operator /=(const float& num) {
	this->x /= num;
	this->y /= num;
	this->z /= num;
	return *this;
}

const Vector4D Vector4D::operator /(const float& num)const {
	return Vector3D(x/num,y/num,z/num);
}

const Vector4D& Vector4D::operator =(const Vector4D& vt4D) {
	this->x = vt4D.x;
	this->y = vt4D.y;
	this->z = vt4D.z;
	this->w = vt4D.w;
	return *this;
}

Vector4D Vector4D::operator *(const Matrix4X4& vt4D) {
	Vector4D temp;
	temp.x = (this->x * vt4D.m[0][0] + this->y * vt4D.m[1][0] + this->z * vt4D.m[2][0] + this->w * vt4D.m[3][0]);
	temp.y = (this->x * vt4D.m[0][1] + this->y * vt4D.m[1][1] + this->z * vt4D.m[2][1] + this->w * vt4D.m[3][1]);
	temp.z = (this->x * vt4D.m[0][2] + this->y * vt4D.m[1][2] + this->z * vt4D.m[2][2] + this->w * vt4D.m[3][2]);
	temp.w=	 (this->x * vt4D.m[0][3] + this->y * vt4D.m[1][3] + this->z * vt4D.m[2][3] + this->w * vt4D.m[3][3]);
	
	temp.x /= temp.w;
	temp.y /= temp.w;
	temp.z /= temp.w;
	temp.w = 1;
	
	return temp;
}

/*4X4矩阵*/
void Matrix4X4::Transpose() {
	// 先定义一个4X4矩阵存放临时数据
	Matrix4X4 temp(*m);

	for (int i = 0; i < 4;++i) {
		for (int j = 0; j < 4;++j) {
			m[i][i] = temp.m[j][i];
		}
	}
}

void Matrix4X4::Identity() {
	m[0][0] =m[1][1]=m[2][2]=m[3][3]= 1;
}

const Matrix4X4& Matrix4X4::operator *=(const float& num) {
	for (int i = 0; i < 4;++i) {
		for (int j = 0; j < 4;++j) {
			m[i][j] *= num;
		}
	}
	return *this;
}

//4*4矩阵相乘
const Matrix4X4 Matrix4X4::operator *(const Matrix4X4& mt4) {
	Matrix4X4 temp;
	for (int i = 0; i < 4; ++i) {
		for (int k = 0; k < 4; ++k) {
			for (int j = 0; j < 4; ++j) {
				float a = (m[i][j] * mt4.m[j][k]);
				temp.m[i][k] += a;
			}
		}
	}

	return temp;
}

const Vector4D Matrix4X4::operator *(const Vector4D& mt4) {
	Vector4D temp;
	temp.x = (this->m[0][0]*mt4.x+ this->m[0][1]*mt4.y+ this->m[0][2]*mt4.z+ this->m[0][3]*mt4.w);
	temp.y = (this->m[1][0] * mt4.x + this->m[1][1] * mt4.y + this->m[1][2] * mt4.z + this->m[1][3] * mt4.w) ;
	temp.z = (this->m[2][0] * mt4.x + this->m[2][1] * mt4.y + this->m[2][2] * mt4.z + this->m[2][3] * mt4.w);
	temp.w = (this->m[3][0] * mt4.x + this->m[3][1] * mt4.y + this->m[3][2] * mt4.z + this->m[3][3] * mt4.w);
	return temp;
}

/*3X3矩阵*/
void Matrix3X3::Transpose() {
	//// 先定义一个4X4矩阵存放临时数据
	Matrix3X3 temp(*m);

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			this->m[i][i] = temp.m[j][i];
		}
	}
}

void Matrix3X3::Norm() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			this->m[i][j] =1;
		}
	}
}

const Matrix3X3 Matrix3X3::operator +(const Matrix3X3& mt3)const{
	Matrix3X3 temp;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp.m[i][j] = this->m[i][j]+mt3.m[i][j];
		}
	}
	return temp;
}

const Matrix3X3 Matrix3X3::operator -(const Matrix3X3& mt3)const {
	Matrix3X3 temp;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp.m[i][j] = this->m[i][j] - mt3.m[i][j];
		}
	}
	return temp;
}

const Matrix3X3& Matrix3X3::operator =(const Matrix3X3& mt3){
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			this->m[i][j] = mt3.m[i][j];
		}
	}
	return *this;
}

const Matrix3X3 Matrix3X3::operator *(const Matrix3X3& mt3)const {
	Matrix3X3 temp;
	for (int i = 0; i < 3;++i) {
		for (int k = 0; k < 3;++k) {
			for (int j = 0; j < 3; ++j) {
				float a= (this->m[i][j] * mt3.m[j][i]);
				temp.m[i][k] += a;
			}
		}
		
	}

	return temp;
}
const Matrix3X3& Matrix3X3::operator +=(const Matrix3X3& mt3) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			this->m[i][j] + mt3.m[i][j];
		}
	}
	return *this;
}
const Matrix3X3& Matrix3X3::operator -=(const Matrix3X3& mt3) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			this->m[i][j] - mt3.m[i][j];
		}
	}
	return *this;
}
const Matrix3X3& Matrix3X3::operator *=(const Matrix3X3& mt3) {
	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k < 3; ++k) {
			for (int j = 0; j < 3; ++j) {
				float a = (this->m[i][j] * mt3.m[j][i]);
				this->m[i][k] += a;
			}
		}
	}
	return *this;
}

const Matrix3X3 operator*(const float& num, const Matrix3X3& mt3) {
	Matrix3X3 temp;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp.m[i][j] = mt3.m[i][j] * num;
		}
	}
	return temp;
}