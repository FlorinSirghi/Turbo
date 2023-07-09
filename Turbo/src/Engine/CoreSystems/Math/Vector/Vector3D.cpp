#include "Vector3D.h"
#include <iostream>
#include <cmath>

namespace Turbo
{

	// Predefined vectors

	const Vector3D Vector3D::zero = Vector3D(0, 0, 0);
	const Vector3D Vector3D::up = Vector3D(0, 1, 0);
	const Vector3D Vector3D::down = Vector3D(0, -1, 0);
	const Vector3D Vector3D::left = Vector3D(-1, 0, 0);
	const Vector3D Vector3D::right = Vector3D(1, 0, 0);

	// Constructors

	Vector3D::Vector3D(const float& X, const float& Y, const float& Z) : x(X), y(Y), z(Z) {
	}

	Vector3D::Vector3D() : x(0), y(0), z(0){
	}


	// Operators

	Vector3D& Vector3D::operator=(Vector3D rhs)
	{
		swap(*this, rhs);
		return *this;
	}

	Vector3D& Vector3D::operator+=(const Vector3D& rhs)
	{
		this->x += rhs.x;
		this->y += rhs.y;
		this->z += rhs.z;

		return *this;
	}

	Vector3D operator+(Vector3D lhs, const Vector3D& rhs)
	{
		lhs += rhs;

		return lhs;
	}

	Vector3D& Vector3D::operator-=(const Vector3D& rhs)
	{
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;

		return *this;
	}

	Vector3D operator-(Vector3D lhs, const Vector3D& rhs)
	{
		lhs -= rhs;

		return lhs;
	}

	Vector3D& Vector3D::operator-()
	{
		this->x = -this->x;
		this->y = -this->y;
		this->z = -this->z;

		return *this;
	}

	// Functions

	void Vector3D::scale(const float& scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
	}

	float Vector3D::getMagnitude() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	void Vector3D::normalize()
	{
		float magnitude = getMagnitude();

		this->x = this->x / magnitude;
		this->y = this->y / magnitude;
		this->z = this->z / magnitude;
	}

	float Vector3D::dotProduct(const Vector3D& lhs, const Vector3D& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	Vector3D& Vector3D::crossProduct(const Vector3D& lhs, const Vector3D& rhs)
	{
		Vector3D thirdVector = Vector3D(lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.z * rhs.x - lhs.x * rhs.z,
			lhs.x * rhs.y - lhs.y * rhs.x);

		return thirdVector;
	}

	Vector3D& Vector3D::getNormalized(const Vector3D& v)
	{
		Vector3D normalized = v;
		normalized.normalize();

		return normalized;
	}

	float Vector3D::angleBetweenVectors(const Vector3D& lhs, const Vector3D& rhs)
	{
		return acos(dotProduct(lhs, rhs) / (lhs.getMagnitude() * rhs.getMagnitude()));
	}

	// Utility

	void swap(Vector3D& lhs, Vector3D& rhs)
	{
		std::swap(lhs.x, rhs.x);
		std::swap(lhs.y, rhs.y);
		std::swap(lhs.z, rhs.z);
	}

}
