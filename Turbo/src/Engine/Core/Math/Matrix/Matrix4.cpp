#include "Matrix4.h"

#include <iostream>

#include "Engine/Core/Math/Trigonometry.h"
#include "Engine/Core/Math/Vector/Vector3D.h"
#include "Engine/Core/Math/Vector/Vector4D.h"
#include "Matrix3.h"

namespace Turbo
{

	// Predefined Matrices

	const Matrix4 Matrix4::zero = Matrix4({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
	const Matrix4 Matrix4::identity = Matrix4({ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 });


	// Constructors

	Matrix4::Matrix4(float ne11, float ne12, float ne13, float ne14,
		float ne21, float ne22, float ne23, float ne24,
		float ne31, float ne32, float ne33, float ne34,
		float ne41, float ne42, float ne43, float ne44) :
		e11(ne11), e12(ne12), e13(ne13), e14(ne14), e21(ne21), e22(ne22), e23(ne23), e24(ne24), e31(ne31), e32(ne32), e33(ne33), e34(ne34), e41(ne41), e42(ne42), e43(ne43), e44(ne44) {
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

	Matrix4 operator*(Matrix4 lhs, const Matrix4& rhs)
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
			e11 * Matrix3({ e22, e23, e24, e32, e33, e34, e42, e43, e44 }).getDeterminant() -
			e12 * Matrix3({ e21, e23, e24, e31, e33, e34, e41, e43, e44 }).getDeterminant() +
			e13 * Matrix3({ e21, e22, e24, e31, e32, e34, e41, e42, e44 }).getDeterminant() -
			e14 * Matrix3({ e21, e22, e23, e31, e32, e33, e41, e42, e43 }).getDeterminant()
			);
	}

	Matrix4 Matrix4::getInverse()
	{
		Matrix4 newMatrix(*this);

		newMatrix.e11 = Matrix3({ e22, e23, e24, e32, e33, e34, e42, e43, e44 }).getDeterminant();
		newMatrix.e12 = -Matrix3({ e21, e23, e24, e31, e33, e34, e41, e43, e44 }).getDeterminant();
		newMatrix.e13 = Matrix3({ e21, e22, e24, e31, e32, e34, e41, e42, e44 }).getDeterminant();
		newMatrix.e14 = Matrix3({ e21, e22, e23, e31, e32, e33, e41, e42, e43 }).getDeterminant();

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

		newMatrix.scale(1.0f / this->getDeterminant());

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

	Vector4D operator*(Matrix4 lhs, const Vector4D& rhs)
	{
		return Vector4D({
			lhs.e11 * rhs.x + lhs.e12 * rhs.y + lhs.e13 * rhs.z + lhs.e14 * rhs.w,
			lhs.e21 * rhs.x + lhs.e22 * rhs.y + lhs.e23 * rhs.z + lhs.e24 * rhs.w,
			lhs.e31 * rhs.x + lhs.e32 * rhs.y + lhs.e33 * rhs.z + lhs.e34 * rhs.w,
			lhs.e41 * rhs.x + lhs.e42 * rhs.y + lhs.e43 * rhs.z + lhs.e44 * rhs.w
			});
	}

	std::array<std::array<float, 4>, 4> Matrix4::getIterable()
	{
		std::array<std::array<float, 4>, 4> iterable;

		iterable[0][0] = e11;
		iterable[0][1] = e12;
		iterable[0][2] = e13;
		iterable[0][3] = e14;

		iterable[1][0] = e21;
		iterable[1][1] = e22;
		iterable[1][2] = e23;
		iterable[1][3] = e24;

		iterable[2][0] = e31;
		iterable[2][1] = e32;
		iterable[2][2] = e33;
		iterable[2][3] = e34;

		iterable[3][0] = e41;
		iterable[3][1] = e42;
		iterable[3][2] = e43;
		iterable[3][3] = e44;

		return iterable;
	}

	void Matrix4::setColumn1(const Vector3D& col)
	{
		e11 = col.x;
		e21 = col.y;
		e31 = col.z;
	}

	void Matrix4::setColumn2(const Vector3D& col)
	{
		e12 = col.x;
		e22 = col.y;
		e32 = col.z;
	}

	void Matrix4::setColumn3(const Vector3D& col)
	{
		e13 = col.x;
		e23 = col.y;
		e33 = col.z;
	}

	void Matrix4::setColumn4(const Vector3D& col)
	{
		e14 = col.x;
		e24 = col.y;
		e34 = col.z;
	}

	void Matrix4::setRow1(const Vector3D& row)
	{
		e11 = row.x;
		e12 = row.y;
		e13 = row.z;
	}

	void Matrix4::setRow2(const Vector3D& row)
	{
		e21 = row.x;
		e22 = row.y;
		e23 = row.z;
	}

	void Matrix4::setRow3(const Vector3D& row)
	{
		e31 = row.x;
		e32 = row.y;
		e33 = row.z;
	}

	void Matrix4::setRow4(const Vector3D& row)
	{
		e41 = row.x;
		e42 = row.y;
		e43 = row.z;
	}

	// Transforms

	Matrix4 Matrix4::translationMatrix(const Vector3D& translation_vector)
	{
		Matrix4 translation_mat = identity;
		translation_mat.e14 = translation_vector.x;
		translation_mat.e24 = translation_vector.y;
		translation_mat.e34 = translation_vector.z;

		return translation_mat;
	}

	Matrix4 Matrix4::scaleMatrix(const Vector3D& scaling_factors)
	{
		Matrix4 scale_mat = identity;
		scale_mat.e11 = scaling_factors.x;
		scale_mat.e22 = scaling_factors.y;
		scale_mat.e33 = scaling_factors.z;
		scale_mat.e44 = 1;

		return scale_mat;
	}

	Matrix4 Matrix4::rotationMatrix(const Vector3D& angles)
	{
		Matrix4 rotation = identity;
		rotation.rotateAroundXMatrix(Trigonometry::fromDegreesToRadians(angles.x));
		rotation.rotateAroundYMatrix(Trigonometry::fromDegreesToRadians(angles.y));
		rotation.rotateAroundZMatrix(Trigonometry::fromDegreesToRadians(angles.z));

		return rotation;
	}

	Matrix4 Matrix4::rotationAroundZMatrix(const float& angle)
	{
		float cos = Trigonometry::cos(angle);
		float sin = Trigonometry::sin(angle);

		Matrix4 rotation_mat = identity;

		rotation_mat.e11 =  cos;
		rotation_mat.e12 = -sin;
		rotation_mat.e21 =  sin;
		rotation_mat.e22 =  cos;

		return rotation_mat;
	}

	Matrix4 Matrix4::rotationAroundXMatrix(const float& angle)
	{
		float cos = Trigonometry::cos(angle);
		float sin = Trigonometry::sin(angle);

		Matrix4 rotation_mat = identity;

		rotation_mat.e22 =  cos;
		rotation_mat.e23 = -sin;
		rotation_mat.e32 =  sin;
		rotation_mat.e33 =  cos;

		return rotation_mat;
	}

	Matrix4 Matrix4::rotationAroundYMatrix(const float& angle)
	{
		float cos = Trigonometry::cos(angle);
		float sin = Trigonometry::sin(angle);

		Matrix4 rotation_mat = identity;

		rotation_mat.e11 =  cos;
		rotation_mat.e13 =  sin;
		rotation_mat.e31 = -sin;
		rotation_mat.e33 =  cos;

		return rotation_mat;
	}

	Matrix4 Matrix4::rotateAroundZMatrix(const float& angle)
	{
		Matrix4 rotation_mat = rotationAroundZMatrix(angle);

		*this *= rotation_mat;

		return *this;
	}

	Matrix4 Matrix4::rotateAroundXMatrix(const float& angle)
	{
		Matrix4 rotation_mat = rotationAroundXMatrix(angle);

		*this *= rotation_mat;

		return *this;
	}

	Matrix4 Matrix4::rotateAroundYMatrix(const float& angle)
	{
		Matrix4 rotation_mat = rotationAroundYMatrix(angle);

		*this *= rotation_mat;

		return *this;
	}

	Matrix4 Matrix4::translate(const Vector3D& rhs)
	{
		Matrix4 translation_mat = translationMatrix(rhs);

		*this *= translation_mat;

		return *this;
	}

	Matrix4 Matrix4::translate(const Vector4D& rhs)
	{
		Matrix4 vec_mat = identity;
		vec_mat.e14 = rhs.x;
		vec_mat.e24 = rhs.y;
		vec_mat.e34 = rhs.z;
		vec_mat.e44 = rhs.w;

		*this *= vec_mat;

		return *this;
	}

	Matrix4 Matrix4::scale(const Vector3D& scaling_factors)
	{
		Matrix4 vec_mat = identity;
		vec_mat.e11 = scaling_factors.x;
		vec_mat.e22 = scaling_factors.y;
		vec_mat.e33 = scaling_factors.z;
		vec_mat.e44 = 1;

		*this *= vec_mat;

		return *this;
	}

	// Rendering

	Matrix4 Matrix4::orthographicProjectionMatrix(float right, float left, float top, float bottom, float far, float near)
	{
		Matrix4 ortho = identity;

		ortho.e11 = 2.0f / (right - left);
		ortho.e22 = 2.0f / (top - bottom);
		ortho.e33 = -2.0f / (far - near);
		ortho.e14 = -(right + left) / (right - left);
		ortho.e24 = -(top + bottom) / (top - bottom);
		ortho.e34 = -(far + near) / (far - near);

		return ortho;
	}

	Matrix4 Matrix4::perspectiveProjectionMatrix(float right, float left, float top, float bottom, float far, float near)
	{
		Matrix4 perspective = identity;

		perspective.e11 = 2 * near / (right - left);
		perspective.e22 = 2 * near / (top - bottom);
		perspective.e33 = -(far + near) / (far - near);
		perspective.e43 = -1;
		perspective.e13 = (right + left) / (right - left);
		perspective.e23 = (top + bottom) / (top - bottom);
		perspective.e34 = - 2 * far * near / (far - near);

		return perspective;
	}

	Matrix4 Matrix4::perspectiveProjectionMatrix(float fov, float aspect, float far, float near)
	{
		float top = near * std::tan(fov * 0.5f);
		float bottom = -top;
		float left = bottom * aspect;
		float right = top * aspect;

		Matrix4 perspective = identity;

		perspective.e11 = 2 * near / (right - left);
		perspective.e22 = 2 * near / (top - bottom);
		perspective.e33 = -(far + near) / (far - near);
		perspective.e43 = -1;
		perspective.e13 = (right + left) / (right - left);
		perspective.e23 = (top + bottom) / (top - bottom);
		perspective.e34 = -2 * far * near / (far - near);

		return perspective;
	}

	Matrix4 Matrix4::lookAtMatrix(const Vector3D& cameraPosition, const Vector3D& target, const Vector3D& up)
	{
		Vector3D direction = Vector3D::getNormalized(cameraPosition - target);

		Vector3D cameraRight = Vector3D::getNormalized(Vector3D::crossProduct(up, direction));
		Vector3D cameraUp = Vector3D::getNormalized(Vector3D::crossProduct(direction, cameraRight));

		Matrix4 lhs = identity;
		lhs.setRow1(cameraRight);
		lhs.setRow2(cameraUp);
		lhs.setRow3(direction);

		Matrix4 rhs = identity;

		Vector3D negatedCameraPos = cameraPosition;
		negatedCameraPos.scale(-1);

		rhs.setColumn4(negatedCameraPos);

		return lhs * rhs;
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

	void Matrix4::getPointer(float*& data) const
	{
		auto* data2 = new float[16]{
			e11, e12, e13, e14,
			e21, e22, e23, e24,
			e31, e32, e33, e34,
			e41, e42, e43, e44
		};

		data = data2;
	}

}
