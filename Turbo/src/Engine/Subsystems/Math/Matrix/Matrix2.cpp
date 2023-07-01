#include "Matrix2.h"
#include <iostream>

namespace Turbo
{

	// Predefined Matrices

	Matrix2 Matrix2::zero = Matrix2(0, 0, 0, 0);
	Matrix2 Matrix2::identity = Matrix2(1, 0, 0, 1 );


	// Constructors

	Matrix2::Matrix2(float ne11, float ne12, float ne21, float ne22) : e11(ne11), e12(ne12), e21(ne21), e22(ne22){
	}

	Matrix2::Matrix2(std::array<float, 4> arr)
	{
		e11 = arr[0];
		e12 = arr[1];
		e21 = arr[2];
		e22 = arr[3];
	}

	// Operators

	Matrix2& Matrix2::operator=(Matrix2 rhs)
	{
		swap(*this, rhs);
		return *this;
	}

	Matrix2& Matrix2::operator+=(const Matrix2& rhs)
	{
		e11 += rhs.e11;
		e12 += rhs.e12;
		e21 += rhs.e21;
		e22 += rhs.e22;

		return *this;
	}

	Matrix2 operator+(Matrix2 lhs, const Matrix2& rhs)
	{
		lhs += rhs;

		return lhs;
	}


	Matrix2& Matrix2::operator-=(const Matrix2& rhs)
	{
		e11 -= rhs.e11;
		e12 -= rhs.e12;
		e21 -= rhs.e21;
		e22 -= rhs.e22;

		return *this;
	}

	Matrix2 operator-(Matrix2 lhs, const Matrix2& rhs)
	{
		lhs -= rhs;

		return lhs;
	}


	Matrix2& Matrix2::operator*=(const Matrix2& rhs)
	{
		float ne11 = e11 * rhs.e11 + e12 * rhs.e21;
		float ne12 = e11 * rhs.e12 + e12 * rhs.e22;
		float ne21 = e21 * rhs.e11 + e22 * rhs.e21;
		float ne22 = e21 * rhs.e12 + e22 * rhs.e22;

		e11 = ne11;
		e22 = ne22;
		e21 = ne21;
		e12 = ne12;

		return *this;
	}

	Matrix2 operator*(Matrix2 lhs, const Matrix2& rhs)
	{
		lhs *= rhs;

		return lhs;
	}

	Matrix2& Matrix2::operator-()
	{
		e11 = -e11;
		e12 = -e12;
		e21 = -e21;
		e22 = -e22;

		return *this;
	}

	// Functions

	void Matrix2::scale(float scalar)
	{
		e11 *= scalar;
		e12 *= scalar;
		e21 *= scalar;
		e22 *= scalar;
	}


	float Matrix2::getDeterminant() const
	{
		return e11 * e22 - e12 * e21;
	}

	Matrix2 Matrix2::getInverse()
	{
		Matrix2 newMatrix(*this);

		float det = getDeterminant();

		newMatrix.e11 = e22 * (1 / det);
		newMatrix.e12 = -e12 * (1 / det);
		newMatrix.e21 = -e21 * (1 / det);
		newMatrix.e22 = e11 * (1 / det);

		return newMatrix;
	}

	Matrix2 Matrix2::getTranspose()
	{
		Matrix2 newMatrix(*this);

		std::swap(newMatrix.e12, newMatrix.e21);

		return newMatrix;
	}

	// Utility

	void swap(Matrix2& lhs, Matrix2& rhs)
	{
		std::swap(lhs.e11, rhs.e11);
		std::swap(lhs.e12, rhs.e12);
		std::swap(lhs.e21, rhs.e21);
		std::swap(lhs.e22, rhs.e22);
	}

}