#ifndef ENGINE_CORE_MATH_MATRIX4_H_
#define ENGINE_CORE_MATH_MATRIX4_H_

#include <array>

#include "Engine/Core/Math/Vector/Vector3D.h"
#include "Engine/Core/Math/Vector/Vector4D.h"

namespace Turbo
{

	class Matrix4
	{
	public:

		float e11, e12, e13, e14, e21, e22, e23, e24, e31, e32, e33, e34, e41, e42, e43, e44;

		// Predefined matrices

		static const Matrix4 zero;
		static const Matrix4 identity;

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
		friend Vector4D operator*(Matrix4 lhs, const Vector4D& rhs);


		Matrix4& operator-();

		// Functions

		void scale(float scalar);
		float getDeterminant() const;
		Matrix4 getInverse();
		Matrix4 getTranspose();

		std::array<std::array<float, 4>, 4> getIterable();

		void setColumn1(const Vector3D&);
		void setColumn2(const Vector3D&);
		void setColumn3(const Vector3D&);
		void setColumn4(const Vector3D&);

		void setRow1(const Vector3D&);
		void setRow2(const Vector3D&);
		void setRow3(const Vector3D&);
		void setRow4(const Vector3D&);

		// Transforms

		static Matrix4 translationMatrix(const Vector3D&);
		static Matrix4 scaleMatrix(const Vector3D&);

		static Matrix4 rotationMatrix(const Vector3D&);

		static Matrix4 rotationAroundZMatrix(const float&);
		static Matrix4 rotationAroundYMatrix(const float&);
		static Matrix4 rotationAroundXMatrix(const float&);

		Matrix4 translate(const Vector3D&);
		Matrix4 translate(const Vector4D&);

		Matrix4 scale(const Vector3D& scaling_factors);
		Matrix4 scale(const Vector4D& scaling_factors);

		Matrix4 rotateAroundZMatrix(const float& angle);
		Matrix4 rotateAroundYMatrix(const float& angle);
		Matrix4 rotateAroundXMatrix(const float& angle);

		// Rendering

		static Matrix4 orthographicProjectionMatrix(float right, float left, float top, float bottom, float far, float near);
		static Matrix4 perspectiveProjectionMatrix(float right, float left, float top, float bottom, float far, float near);
		static Matrix4 perspectiveProjectionMatrix(float fov, float aspect, float far, float near);
		static Matrix4 lookAtMatrix(const Vector3D& cameraPosition, const Vector3D& target, const Vector3D& up);

		// Utility

		friend void swap(Matrix4& lhs, Matrix4& rhs) noexcept;
		void getPointer(float*& data) const;
	};

}

#endif // ENGINE_CORE_MATH_MATRIX4_H_
