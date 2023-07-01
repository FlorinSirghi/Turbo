#pragma once
#include <array>

namespace Turbo
{

	class Matrix2
	{

	public:

		// Predefined matrices

		static Matrix2 zero;
		static Matrix2 identity;

		// Fields

		float e11, e12, e21, e22;

		// Constructors

		Matrix2(float ne11, float ne12, float ne21, float ne22);
		Matrix2(std::array<float, 4> arr);

		// Operators

		Matrix2& operator=(Matrix2 rhs);

		Matrix2& operator+=(const Matrix2& rhs);
		Matrix2& operator-=(const Matrix2& rhs);
		Matrix2& operator*=(const Matrix2& rhs);
		friend Matrix2 operator+(Matrix2 lhs, const Matrix2& rhs);
		friend Matrix2 operator-(Matrix2 lhs, const Matrix2& rhs);
		friend Matrix2 operator*(Matrix2 lhs, const Matrix2& rhs);

		Matrix2& operator-();

		// Functions

		void scale(float scalar);
		float getDeterminant() const;
		Matrix2 getInverse();
		Matrix2 getTranspose();

		// Utility

		friend void swap(Matrix2& lhs, Matrix2& rhs);
	};

}
