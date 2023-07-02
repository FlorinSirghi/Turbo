#include "Vector4D.h"
#include <iostream>
#include <cmath>

namespace Turbo
{

	// Predefined vectors

	Vector4D Vector4D::zero = Vector4D(0, 0, 0, 0);
	Vector4D Vector4D::up = Vector4D(0, 1, 0, 0);
	Vector4D Vector4D::down = Vector4D(0, -1, 0, 0);
	Vector4D Vector4D::left = Vector4D(-1, 0, 0, 0);
	Vector4D Vector4D::right = Vector4D(1, 0, 0, 0);

	// Constructors

	Vector4D::Vector4D(const float& X, const float& Y, const float& Z, const float& W) : x(X), y(Y), z(Z), w(W) {
	}

	// Operators

	Vector4D& Vector4D::operator=(Vector4D rhs)
	{
		swap(*this, rhs);
		return *this;
	}

	Vector4D& Vector4D::operator+=(const Vector4D& rhs)
	{
		this->x += rhs.x;
		this->y += rhs.y;
		this->z += rhs.z;
		this->w += rhs.w;

		return *this;
	}

	Vector4D operator+(Vector4D lhs, const Vector4D& rhs)
	{
		lhs += rhs;

		return lhs;
	}

	Vector4D& Vector4D::operator-=(const Vector4D& rhs)
	{
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;
		this->w -= rhs.w;

		return *this;
	}

	Vector4D operator-(Vector4D lhs, const Vector4D& rhs)
	{
		lhs -= rhs;

		return lhs;
	}

	Vector4D& Vector4D::operator-()
	{
		Vector4D tmp(*this);
		tmp.x = -tmp.x;
		tmp.y = -tmp.y;
		tmp.z = -tmp.z;
		tmp.w = -tmp.w;
		return tmp;
	}

	// Functions

	void Vector4D::scale(const float& scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
		this->w *= scalar;
	}

	float Vector4D::getMagnitude() const
	{
		return sqrt(x * x + y * y + z * z + w * w);
	}

	void Vector4D::normalize()
	{
		float magnitude = getMagnitude();

		this->x = this->x / magnitude;
		this->y = this->y / magnitude;
		this->z = this->z / magnitude;
		this->w = this->w / magnitude;
	}

	float Vector4D::dotProduct(const Vector4D& lhs, const Vector4D& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}

	Vector4D& Vector4D::getNormalized(const Vector4D& v)
	{
		Vector4D normalized = v;
		normalized.normalize();

		return normalized;
	}

	float Vector4D::angleBetweenVectors(const Vector4D& lhs, const Vector4D& rhs)
	{
		return acos(dotProduct(lhs, rhs) / (lhs.getMagnitude() * rhs.getMagnitude()));
	}

	// Utility

	void Vector4D::getPointer(float*& data) const
	{
		float data2[] = { x, y, z, w };

		data = data2;
	}

	void swap(Vector4D& lhs, Vector4D& rhs)
	{
		std::swap(lhs.x, rhs.x);
		std::swap(lhs.y, rhs.y);
		std::swap(lhs.z, rhs.z);
		std::swap(lhs.w, rhs.w);
	}
}


