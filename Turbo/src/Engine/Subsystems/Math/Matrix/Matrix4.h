#pragma once
#include <array>

namespace Turbo
{

	class Matrix4
	{
	private:
		
		float e11, e12, e13, e14, e21, e22, e23, e24, e31, e32, e33, e34, e41, e42, e43, e44;

	public:

		// Predefined matrices

		static Matrix4 zero;
		static Matrix4 identity;

		// Constructors

		Matrix4(float ne11, float ne12, float ne13, float ne14, 
				float ne21, float ne22, float ne23, float ne24, 
				float ne31, float ne32, float ne33, float ne34, 
				float ne41, float ne42, float ne43, float ne44);
		Matrix4(const std::array<float, 16>& arr);

		// Operators

		Matrix4& operator=(Matrix4 rhs);

		Matrix4& operator+=(const Matrix4& rhs);
		Matrix4& operator-=(const Matrix4& rhs);
		Matrix4& operator*=(const Matrix4& rhs);
		friend Matrix4 operator+(Matrix4 lhs, const Matrix4& rhs);
		friend Matrix4 operator-(Matrix4 lhs, const Matrix4& rhs);
		friend Matrix4 operator*(Matrix4 lhs, const Matrix4& rhs);

		Matrix4& operator-();

		// Functions

		void scale(float scalar);
		float getDeterminant() const;
		Matrix4 getInverse();
		Matrix4 getTranspose();

		// Utility

		friend void swap(Matrix4& lhs, Matrix4& rhs) noexcept;
	};

}
