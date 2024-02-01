#ifndef ENGINE_CORE_MATH_MATRIX3_H_
#define ENGINE_CORE_MATH_MATRIX3_H_

#include <array>

namespace Turbo
{

	class Matrix3
	{
	public:

		// Predefined matrices

		static Matrix3 zero;
		static Matrix3 identity;

		// Fields

		float e11, e12, e13, e21, e22, e23, e31, e32, e33;

		// Constructors

		Matrix3(float ne11, float ne12, float ne13, 
				float ne21, float ne22, float ne23, 
				float ne31, float ne32, float ne33);
		Matrix3(std::array<float, 9> arr);

		// Operators

		Matrix3& operator=(Matrix3 rhs);

		Matrix3& operator+=(const Matrix3& rhs);
		Matrix3& operator-=(const Matrix3& rhs);
		Matrix3& operator*=(const Matrix3& rhs);
		//Matrix3& operator*=
		friend Matrix3 operator+(Matrix3 lhs, const Matrix3& rhs);
		friend Matrix3 operator-(Matrix3 lhs, const Matrix3& rhs);
		friend Matrix3 operator*(Matrix3 lhs, const Matrix3& rhs);

		Matrix3& operator-();

		// Functions

		void scale(float scalar);
		float getDeterminant() const;
		Matrix3 getInverse();
		Matrix3 getTranspose();

		// Utility

		friend void swap(Matrix3& lhs, Matrix3& rhs) noexcept;
	};

}

#endif // ENGINE_CORE_MATH_MATRIX3_H_
