#include "MyMath.h"

/*2D向量*/
const float Vector2D::VectorMag() {
	return sqrtf(this->x*this->x + this->y * this->y);
}

const void Vector2D::Norm() {

	if (x == 0 && y == 0)
		return;

	float tmp = sqrtf(x*x + y * y);

	if (tmp!=0)
		x /= tmp; y /=tmp;
}

const float Vector2D::Dot(const Vector2D& vt2D) {
	return this->x*vt2D.x+this->y*vt2D.y;
}


const Vector2D Vector2D::operator -(const Vector2D& vt2D)const {
	return Vector2D(x-vt2D.x,y-vt2D.y);
}

Vector2D Vector2D::operator -=(const Vector2D& vt2D) {
	x -= vt2D.x;
	y -= vt2D.y;
	return *this;
}

const Vector2D Vector2D::operator +(const Vector2D& vt2D)const {
	return Vector2D(x + vt2D.x, y + vt2D.y);
}

Vector2D& Vector2D::operator +=(const Vector2D& vt2D){
	x += vt2D.x;
	y += vt2D.y;
	return *this;
}

Vector2D& Vector2D::operator *=(const float& num) {
	x *= num;
	y *= num;
	return *this;
}

const Vector2D Vector2D::operator *(const float& num)const {
	return Vector2D(x * num, y * num);
}


Vector2D& Vector2D::operator /=(const float& num) {
	x /= num;
	y /= num;
	return *this;
}

const Vector2D Vector2D::operator /(const float& num)const {
	return Vector2D(x / num, y / num);
}

/*3D向量*/
const float Vector3D::VectorMag() {
	return sqrtf(this->x*this->x + this->y * this->y+this->z*this->z);
}

const void Vector3D::Norm() {

	if (x == 0 && y == 0&&z==0)
		return;

	float tmp = sqrtf(x*x + y * y+z*z);

	if (tmp != 0)
		x /= tmp; y /= tmp; z / tmp;
}

const float Vector3D::Dot(const Vector3D& vt3D) {
	return this->x*vt3D.x + this->y*vt3D.y+this->z*vt3D.z;
}

const Vector3D Vector3D::operator -(const Vector3D& vt3D)const {
	return Vector3D(x - vt3D.x, y - vt3D.y,z-vt3D.z);
}

Vector3D Vector3D::operator -=(const Vector3D& vt3D) {
	x -= vt3D.x;
	y -= vt3D.y;
	z -= vt3D.z;
	return *this;
}

const Vector3D Vector3D::operator +(const Vector3D& vt3D)const {
	return Vector3D(x + vt3D.x, y + vt3D.y,z+vt3D.z);
}

Vector3D& Vector3D::operator +=(const Vector3D& vt3D) {
	x += vt3D.x;
	y += vt3D.y;
	z += vt3D.z;
	return *this;
}

Vector3D& Vector3D::operator *=(const float& num) {
	x *= num;
	y *= num;
	z *= num;
	return *this;
}

const Vector3D Vector3D::operator *(const float& num)const {
	return Vector3D(x * num, y * num,z*num);
}


Vector3D& Vector3D::operator /=(const float& num) {
	x /= num;
	y /= num;
	z /= num;
	return *this;
}

const Vector3D Vector3D::operator /(const float& num)const {
	return Vector3D(x / num, y / num,z/num);
}

const Vector3D& Vector3D::operator =(const Vector3D& vt3D) {
	x = vt3D.x; y = vt3D.y; z = vt3D.z;
	return *this;
}

const Vector3D& Vector3D::Cross(const Vector3D& vt3D) {
	return Vector3D(this->y*vt3D.z-this->z*vt3D.y,this->z*vt3D.x-this->x*vt3D.z,this->x*vt3D.y-this->y*vt3D.x);
}

/*4D向量*/
const Vector4D Vector4D::operator -(const Vector4D& vt4D)const {
	return Vector4D(vt3-vt4D.vt3);
}

const Vector4D& Vector4D::operator -=(const Vector4D& vt4D) {
	vt3 -= vt4D.vt3;
	return *this;
}

const Vector4D Vector4D::operator +(const Vector4D& vt4D)const {
	return Vector3D(vt3+vt4D.vt3);
}

Vector4D& Vector4D::operator +=(const Vector4D& vt4D) {
	vt3 += vt4D.vt3;
	return *this;
}

Vector4D& Vector4D::operator *=(const float& num) {
	vt3.x *= num;
	vt3.y *= num;
	vt3.z *= num;
	return *this;
}

const Vector4D Vector4D::operator *(const float& num)const {
	return Vector4D(vt3*num);
}


Vector4D& Vector4D::operator /=(const float& num) {
	vt3.x /= num;
	vt3.y /= num;
	vt3.z /= num;
	return *this;
}

const Vector4D Vector4D::operator /(const float& num)const {
	return Vector3D(vt3/num);
}

const Vector4D& Vector4D::operator =(const Vector4D& vt4D) {
	vt3 = vt4D.vt3;
	return *this;
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

void Matrix4X4::Norm() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m[i][j] = 1;
		}
	}
}

const Matrix4X4& Matrix4X4::operator *=(const float& num) {
	for (int i = 0; i < 4;++i) {
		for (int j = 0; j < 4;++j) {
			m[i][j] *= num;
		}
	}
	return *this;
}


/*3X3矩阵*/
void Matrix3X3::Transpose() {
	//// 先定义一个4X4矩阵存放临时数据
	Matrix3X3 temp(*m);

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			m[i][i] = temp.m[j][i];
		}
	}
}

void Matrix3X3::Norm() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			m[i][j] =1;
		}
	}
}

const Matrix3X3 Matrix3X3::operator +(const Matrix3X3& mt3)const{
	Matrix3X3 temp;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp.m[i][j] = m[i][j]+mt3.m[i][j];
		}
	}
	return temp;
}

const Matrix3X3 Matrix3X3::operator -(const Matrix3X3& mt3)const {
	Matrix3X3 temp;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			temp.m[i][j] = m[i][j] - mt3.m[i][j];
		}
	}
	return temp;
}

const Matrix3X3& Matrix3X3::operator =(const Matrix3X3& mt3){
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			m[i][j] = mt3.m[i][j];
		}
	}
	return *this;
}

const Matrix3X3 Matrix3X3::operator *(const Matrix3X3& mt3)const {
	Matrix3X3 temp;
	for (int i = 0; i < 3;++i) {
		for (int k = 0; k < 3;++k) {
			for (int j = 0; j < 3; ++j) {
				float a= (m[i][j] * mt3.m[j][i]);
				temp.m[i][k] += a;
			}
		}
		
	}

	return temp;
}
const Matrix3X3& Matrix3X3::operator +=(const Matrix3X3& mt3) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			 m[i][j] + mt3.m[i][j];
		}
	}
	return *this;
}
const Matrix3X3& Matrix3X3::operator -=(const Matrix3X3& mt3) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			m[i][j] - mt3.m[i][j];
		}
	}
	return *this;
}
const Matrix3X3& Matrix3X3::operator *=(const Matrix3X3& mt3) {
	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k < 3; ++k) {
			for (int j = 0; j < 3; ++j) {
				float a = (m[i][j] * mt3.m[j][i]);
				m[i][k] += a;
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