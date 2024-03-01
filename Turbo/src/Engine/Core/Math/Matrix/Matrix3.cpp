#include "Matrix3.h"

#include <iostream>

namespace Turbo
{

	// Predefined Matrices

	Matrix3 Matrix3::zero = Matrix3({ 0, 0, 0, 0, 0, 0, 0, 0, 0 });
	Matrix3 Matrix3::identity = Matrix3({ 1, 0, 0, 0, 1, 0, 0, 0, 1 });


	// Constructors

	Matrix3::Matrix3(float ne11, float ne12, float ne13, float ne21, float ne22, float ne23, float ne31, float ne32, float ne33) :
							e11(ne11), e12(ne12), e13(ne13), e21(ne21), e22(ne22), e23(ne23), e31(ne31), e32(ne32), e33(ne33) {
	}

	Matrix3::Matrix3(std::array<float, 9> arr)
	{
		e11 = arr[0];
		e12 = arr[1];
		e13 = arr[2];
		e21 = arr[3];
		e22 = arr[4];
		e23 = arr[5];
		e31 = arr[6];
		e32 = arr[7];
		e33 = arr[8];
	}

	// Operators

	Matrix3& Matrix3::operator=(Matrix3 rhs)
	{
		swap(*this, rhs);
		return *this;
	}

	Matrix3& Matrix3::operator+=(const Matrix3& rhs)
	{
		e11 += rhs.e11;
		e12 += rhs.e12;
		e13 += rhs.e13;
		e21 += rhs.e21;
		e22 += rhs.e22;
		e23 += rhs.e23;
		e31 += rhs.e31;
		e32 += rhs.e32;
		e33 += rhs.e33;

		return *this;
	}

	Matrix3 operator+(Matrix3 lhs, const Matrix3& rhs)
	{
		lhs += rhs;

		return lhs;
	}


	Matrix3& Matrix3::operator-=(const Matrix3& rhs)
	{
		e11 -= rhs.e11;
		e12 -= rhs.e12;
		e13 -= rhs.e13;
		e21 -= rhs.e21;
		e22 -= rhs.e22;
		e23 -= rhs.e23;
		e31 -= rhs.e31;
		e32 -= rhs.e32;
		e33 -= rhs.e33;

		return *this;
	}

	Matrix3 operator-(Matrix3 lhs, const Matrix3& rhs)
	{
		lhs -= rhs;

		return lhs;
	}


	Matrix3& Matrix3::operator*=(const Matrix3& rhs)
	{
		float ne11 = e11 * rhs.e11 + e12 * rhs.e21 + e13 * rhs.e31;
		float ne12 = e11 * rhs.e12 + e12 * rhs.e22 + e13 * rhs.e32;
		float ne13 = e11 * rhs.e13 + e12 * rhs.e23 + e13 * rhs.e33;

		float ne21 = e21 * rhs.e11 + e22 * rhs.e21 + e23 * rhs.e31;
		float ne22 = e21 * rhs.e12 + e22 * rhs.e22 + e23 * rhs.e32;
		float ne23 = e21 * rhs.e13 + e22 * rhs.e23 + e23 * rhs.e33;

		float ne31 = e31 * rhs.e11 + e32 * rhs.e21 + e33 * rhs.e31;
		float ne32 = e31 * rhs.e12 + e32 * rhs.e22 + e33 * rhs.e32;
		float ne33 = e31 * rhs.e13 + e32 * rhs.e23 + e33 * rhs.e33;

		e11 = ne11;
		e12 = ne12;
		e13 = ne13;
		e21 = ne21;
		e22 = ne22;
		e23 = ne23;
		e31 = ne31;
		e32 = ne32;
		e33 = ne33;
		
		return *this;
	}

	Matrix3 operator*(Matrix3 lhs, const Matrix3 rhs)
	{
		lhs *= rhs;

		return lhs;
	}

	Matrix3& Matrix3::operator-()
	{
		e11 = -e11;
		e12 = -e12;
		e13 = -e13;
		e21 = -e21;
		e22 = -e22;
		e23 = -e23;
		e31 = -e31;
		e32 = -e32;
		e33 = -e33;

		return *this;
	}


	// Functions

	std::array<std::array<float, 3>, 3> Matrix3::getIterable()
	{
		std::array<std::array<float, 3>, 3> iterable;

		iterable[0][0] = e11;
		iterable[0][1] = e12;
		iterable[0][2] = e13;

		iterable[1][0] = e21;
		iterable[1][1] = e22;
		iterable[1][2] = e23;

		iterable[2][0] = e31;
		iterable[2][1] = e32;
		iterable[2][2] = e33;

		return iterable;
	}

	void Matrix3::scale(float scalar)
	{
		e11 *= scalar;
		e12 *= scalar;
		e13 *= scalar;
		e21 *= scalar;
		e22 *= scalar;
		e23 *= scalar;
		e31 *= scalar;
		e32 *= scalar;
		e33 *= scalar;
	}


	float Matrix3::getDeterminant() const
	{
		return (e11 * e22 * e33 + 
				e12 * e23 * e31 + 
				e21 * e32 * e13) - 
			   (e13 * e22 * e31 + 
				e32 * e23 * e11 +
				e33 * e21 * e12);
	}

	Matrix3 Matrix3::getInverse()
	{
		Matrix3 newMatrix(*this);

		float det = getDeterminant();

		newMatrix.e11 = (e22 * e33 - e23 * e32) * (1 / det);
		newMatrix.e12 = -(e12 * e33 - e13 * e32) * (1 / det);
		newMatrix.e13 = (e12 * e23 - e13 * e22) * (1 / det);

		newMatrix.e21 = -(e21 * e33 - e23 * e31) * (1 / det);
		newMatrix.e22 = (e11 * e33 - e13 * e31) * (1 / det);
		newMatrix.e23 = -(e11 * e23 - e13 * e21) * (1 / det);

		newMatrix.e31 = (e21 * e32 - e22 * e31) * (1 / det);
		newMatrix.e32 = -(e11 * e32 - e12 * e31) * (1 / det);
		newMatrix.e33 = (e11 * e22 - e12 * e21) * (1 / det);

		return newMatrix;
	}

	Matrix3 Matrix3::getTranspose()
	{
		Matrix3 newMatrix(*this);

		newMatrix.e21 = e12;
		newMatrix.e31 = e13;

		newMatrix.e12 = e21;
		newMatrix.e32 = e23;

		newMatrix.e13 = e31;
		newMatrix.e23 = e32;

		return newMatrix;
	}

	// Utility

	void swap(Matrix3& lhs, Matrix3& rhs) noexcept
	{
		std::swap(lhs.e11, rhs.e11);
		std::swap(lhs.e12, rhs.e12);
		std::swap(lhs.e13, rhs.e13);
		std::swap(lhs.e21, rhs.e21);
		std::swap(lhs.e22, rhs.e22);
		std::swap(lhs.e23, rhs.e23);
		std::swap(lhs.e31, rhs.e31);
		std::swap(lhs.e32, rhs.e32);
		std::swap(lhs.e33, rhs.e33);
	}

}