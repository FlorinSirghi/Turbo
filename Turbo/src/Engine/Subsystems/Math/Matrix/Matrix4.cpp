#include "Matrix4.h"
#include "Matrix3.h"
#include <iostream>

namespace Turbo
{

	// Predefined Matrices

	Matrix4 Matrix4::zero = Matrix4({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
	Matrix4 Matrix4::identity = Matrix4({ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 });


	// Constructors

	Matrix4::Matrix4(float ne11, float ne12, float ne13, float ne14,
					 float ne21, float ne22, float ne23, float ne24,
					 float ne31, float ne32, float ne33, float ne34,
					 float ne41, float ne42, float ne43, float ne44) :
		e11(ne11), e12(ne12), e13(ne13), e21(ne21), e22(ne22), e23(ne32), e31(ne31), e32(ne32), e33(ne33) {
	}

	Matrix4::Matrix4(const std::array<float, 16>& arr)
	{
		e11 = arr[0];
		e12 = arr[1];
		e13 = arr[2];
		e14 = arr[3];
		e21 = arr[4];
		e22 = arr[5];
		e23 = arr[6];
		e24 = arr[7];
		e31 = arr[8];
		e32 = arr[9];
		e33 = arr[10];
		e34 = arr[11];
		e41 = arr[12];
		e42 = arr[13];
		e43 = arr[14];
		e44 = arr[15];
	}

	// Operators

	Matrix4& Matrix4::operator=(Matrix4 rhs)
	{
		swap(*this, rhs);
		return *this;
	}

	Matrix4& Matrix4::operator+=(const Matrix4& rhs)
	{
		e11 += rhs.e11;
		e12 += rhs.e12;
		e13 += rhs.e13;
		e14 += rhs.e14;
		e21 += rhs.e21;
		e22 += rhs.e22;
		e23 += rhs.e23;
		e24 += rhs.e24;
		e31 += rhs.e31;
		e32 += rhs.e32;
		e33 += rhs.e33;
		e34 += rhs.e34;
		e41 += rhs.e41;
		e42 += rhs.e42;
		e43 += rhs.e43;
		e44 += rhs.e44;

		return *this;
	}

	Matrix4 operator+(Matrix4 lhs, const Matrix4& rhs)
	{
		lhs += rhs;

		return lhs;
	}


	Matrix4& Matrix4::operator-=(const Matrix4& rhs)
	{
		e11 -= rhs.e11;
		e12 -= rhs.e12;
		e13 -= rhs.e13;
		e14 -= rhs.e14;
		e21 -= rhs.e21;
		e22 -= rhs.e22;
		e23 -= rhs.e23;
		e24 -= rhs.e24;
		e31 -= rhs.e31;
		e32 -= rhs.e32;
		e33 -= rhs.e33;
		e34 -= rhs.e34;
		e41 -= rhs.e41;
		e42 -= rhs.e42;
		e43 -= rhs.e43;
		e44 -= rhs.e44;

		return *this;
	}

	Matrix4 operator-(Matrix4 lhs, const Matrix4& rhs)
	{
		lhs -= rhs;

		return lhs;
	}


	Matrix4& Matrix4::operator*=(const Matrix4& rhs)
	{
		float ne11 = e11 * rhs.e11 + e12 * rhs.e21 + e13 * rhs.e31 + e14 * rhs.e41;
		float ne12 = e11 * rhs.e12 + e12 * rhs.e22 + e13 * rhs.e32 + e14 * rhs.e42;
		float ne13 = e11 * rhs.e13 + e12 * rhs.e23 + e13 * rhs.e33 + e14 * rhs.e43;
		float ne14 = e11 * rhs.e14 + e12 * rhs.e24 + e13 * rhs.e34 + e14 * rhs.e44;

		float ne21 = e21 * rhs.e11 + e22 * rhs.e21 + e23 * rhs.e31 + e24 * rhs.e41;
		float ne22 = e21 * rhs.e12 + e22 * rhs.e22 + e23 * rhs.e32 + e24 * rhs.e42;
		float ne23 = e21 * rhs.e13 + e22 * rhs.e23 + e23 * rhs.e33 + e24 * rhs.e43;
		float ne24 = e21 * rhs.e14 + e22 * rhs.e24 + e23 * rhs.e34 + e24 * rhs.e44;

		float ne31 = e31 * rhs.e11 + e32 * rhs.e21 + e33 * rhs.e31 + e34 * rhs.e41;
		float ne32 = e31 * rhs.e12 + e32 * rhs.e22 + e33 * rhs.e32 + e34 * rhs.e42;
		float ne33 = e31 * rhs.e13 + e32 * rhs.e23 + e33 * rhs.e33 + e34 * rhs.e43;
		float ne34 = e31 * rhs.e14 + e32 * rhs.e24 + e33 * rhs.e34 + e34 * rhs.e44;

		float ne41 = e41 * rhs.e11 + e42 * rhs.e21 + e43 * rhs.e31 + e44 * rhs.e41;
		float ne42 = e41 * rhs.e12 + e42 * rhs.e22 + e43 * rhs.e32 + e44 * rhs.e42;
		float ne43 = e41 * rhs.e13 + e42 * rhs.e23 + e43 * rhs.e33 + e44 * rhs.e43;
		float ne44 = e41 * rhs.e14 + e42 * rhs.e24 + e43 * rhs.e34 + e44 * rhs.e44;

		e11 = ne11;
		e12 = ne12;
		e13 = ne13;
		e14 = ne14;
		e21 = ne21;
		e22 = ne22;
		e23 = ne23;
		e24 = ne24;
		e31 = ne31;
		e32 = ne32;
		e33 = ne33;
		e34 = ne34;
		e41 = ne41;
		e42 = ne42;
		e43 = ne43;
		e44 = ne44;

		return *this;
	}

	Matrix4 operator*(Matrix4 lhs, const Matrix4 rhs)
	{
		lhs *= rhs;

		return lhs;
	}

	Matrix4& Matrix4::operator-()
	{
		e11 = -e11;
		e12 = -e12;
		e13 = -e13;
		e14 = -e14;
		e21 = -e21;
		e22 = -e22;
		e23 = -e23;
		e24 = -e24;
		e31 = -e31;
		e32 = -e32;
		e33 = -e33;
		e34 = -e34;
		e41 = -e41;
		e42 = -e42;
		e43 = -e43;
		e44 = -e44;

		return *this;
	}


	// Functions

	void Matrix4::scale(float scalar)
	{
		e11 *= scalar;
		e12 *= scalar;
		e13 *= scalar;
		e14 *= scalar;
		e21 *= scalar;
		e22 *= scalar;
		e23 *= scalar;
		e24 *= scalar;
		e31 *= scalar;
		e32 *= scalar;
		e33 *= scalar;
		e34 *= scalar;
		e41 *= scalar;
		e42 *= scalar;
		e43 *= scalar;
		e44 *= scalar;
	}


	float Matrix4::getDeterminant() const
	{
		return (
			e11 * Matrix3({e22, e23, e24, e32, e33, e34, e42, e43, e44}).getDeterminant() - 
			e12 * Matrix3({e21, e23, e24, e31, e33, e34, e41, e43, e44}).getDeterminant() +
			e13 * Matrix3({e21, e22, e24, e31, e32, e34, e41, e42, e44}).getDeterminant() -
			e14 * Matrix3({e21, e22, e23, e31, e32, e33, e41, e42, e43}).getDeterminant()
			);
	}

	Matrix4 Matrix4::getInverse()
	{
		Matrix4 newMatrix(*this);

		float det = getDeterminant();

		newMatrix.e11 = Matrix3({ e22, e23, e24, e32, e33, e34, e42, e43, e44 }).getDeterminant();
		newMatrix.e12 =	-Matrix3({ e21, e23, e24, e31, e33, e34, e41, e43, e44 }).getDeterminant();
		newMatrix.e13 =	Matrix3({ e21, e22, e24, e31, e32, e34, e41, e42, e44 }).getDeterminant();
		newMatrix.e14 =	Matrix3({ e21, e22, e23, e31, e32, e33, e41, e42, e43 }).getDeterminant();

		newMatrix.e21 = -Matrix3({ e12, e13, e14, e32, e33, e34, e42, e43, e44 }).getDeterminant();
		newMatrix.e22 = Matrix3({ e11, e13, e14, e31, e33, e34, e41, e43, e44 }).getDeterminant();
		newMatrix.e23 = -Matrix3({ e11, e12, e14, e31, e32, e34, e41, e42, e44 }).getDeterminant();
		newMatrix.e24 = Matrix3({ e11, e12, e13, e31, e32, e33, e41, e42, e43 }).getDeterminant();

		newMatrix.e31 = Matrix3({ e12, e13, e14, e22, e23, e24, e42, e43, e44 }).getDeterminant();
		newMatrix.e32 = -Matrix3({ e11, e13, e14, e21, e23, e24, e41, e43, e44 }).getDeterminant();
		newMatrix.e33 = Matrix3({ e11, e12, e14, e21, e22, e24, e41, e42, e44 }).getDeterminant();
		newMatrix.e34 = -Matrix3({ e11, e12, e13, e21, e22, e23, e41, e42, e43 }).getDeterminant();

		newMatrix.e41 = -Matrix3({ e12, e13, e14, e22, e23, e24, e32, e33, e34 }).getDeterminant();
		newMatrix.e42 = Matrix3({ e11, e13, e14, e21, e23, e24, e31, e33, e34 }).getDeterminant();
		newMatrix.e43 = -Matrix3({ e11, e12, e14, e21, e22, e24, e31, e32, e34 }).getDeterminant();
		newMatrix.e44 = Matrix3({ e11, e12, e13, e21, e22, e23, e31, e32, e33 }).getDeterminant();

		return newMatrix;
	}

	Matrix4 Matrix4::getTranspose()
	{
		Matrix4 newMatrix(*this);

		newMatrix.e21 = e12;
		newMatrix.e31 = e13;
		newMatrix.e41 = e14;

		newMatrix.e12 = e21;
		newMatrix.e32 = e23;
		newMatrix.e42 = e24;

		newMatrix.e13 = e31;
		newMatrix.e23 = e32;
		newMatrix.e43 = e34;

		newMatrix.e14 = e41;
		newMatrix.e24 = e42;
		newMatrix.e34 = e43;

		return newMatrix;
	}

	// Transforms

	Matrix4 Matrix4::translate(const Vector3D& rhs)
	{
		Matrix4 vec_mat = Matrix4::zero;
		vec_mat.e14 = rhs.x;
		vec_mat.e24 = rhs.y;
		vec_mat.e34 = rhs.z;

		*this *= vec_mat;

		return *this;
	}

	Matrix4 Matrix4::translate(const Vector4D& rhs)
	{
		Matrix4 vec_mat = Matrix4::zero;
		vec_mat.e14 = rhs.x;
		vec_mat.e24 = rhs.y;
		vec_mat.e34 = rhs.z;
		vec_mat.e44 = rhs.w;

		*this *= vec_mat;

		return *this;
	}

	// Utility

	void swap(Matrix4& lhs, Matrix4& rhs) noexcept
	{
		std::swap(lhs.e11, rhs.e11);
		std::swap(lhs.e12, rhs.e12);
		std::swap(lhs.e13, rhs.e13);
		std::swap(lhs.e14, rhs.e14);
		std::swap(lhs.e21, rhs.e21);
		std::swap(lhs.e22, rhs.e22);
		std::swap(lhs.e23, rhs.e23);
		std::swap(lhs.e24, rhs.e24);
		std::swap(lhs.e31, rhs.e31);
		std::swap(lhs.e32, rhs.e32);
		std::swap(lhs.e33, rhs.e33);
		std::swap(lhs.e34, rhs.e34);
		std::swap(lhs.e41, rhs.e41);
		std::swap(lhs.e42, rhs.e42);
		std::swap(lhs.e43, rhs.e43);
		std::swap(lhs.e44, rhs.e44);
	}

}