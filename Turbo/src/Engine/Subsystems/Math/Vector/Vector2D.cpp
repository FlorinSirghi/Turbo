#include "Vector2D.h"
#include <iostream>
#include <cmath>

namespace Turbo
{

	// Predefined vectors

	Vector2D Vector2D::zero = Vector2D(0, 0);
	Vector2D Vector2D::up = Vector2D(0, 1);
	Vector2D Vector2D::down = Vector2D(0, -1);
	Vector2D Vector2D::left = Vector2D(-1, 0);
	Vector2D Vector2D::right = Vector2D(1, 0);

	// Constructors

	Vector2D::Vector2D(const float& X, const float& Y) : x(X), y(Y) {
	}

	// Operators

	Vector2D& Vector2D::operator=(Vector2D rhs)
	{
		swap(*this, rhs);
		return *this;
	}

	Vector2D& Vector2D::operator+=(const Vector2D& rhs)
	{
		this->x += rhs.x;
		this->y += rhs.y;

		return *this;
	}

	Vector2D operator+(Vector2D lhs, const Vector2D& rhs)
	{
		lhs += rhs;

		return lhs;
	}

	Vector2D& Vector2D::operator-=(const Vector2D& rhs)
	{
		this->x -= rhs.x;
		this->y -= rhs.y;

		return *this;
	}

	Vector2D operator-(Vector2D lhs, const Vector2D& rhs)
	{
		lhs -= rhs;

		return lhs;
	}

	Vector2D& Vector2D::operator-()
	{
		Vector2D tmp(*this);
		tmp.x = -tmp.x;
		tmp.y = -tmp.y;
		return tmp;
	}

	// Functions

	void Vector2D::scale(const float& scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
	}

	float Vector2D::getMagnitude() const
	{
		return sqrt(x * x + y * y);
	}

	void Vector2D::normalize()
	{
		float magnitude = getMagnitude();

		this->x = this->x / magnitude;
		this->y = this->y / magnitude;
	}

	float Vector2D::dotProduct(const Vector2D& lhs, const Vector2D& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	Vector2D& Vector2D::getNormalized(const Vector2D& v)
	{
		Vector2D normalized = v;
		normalized.normalize();

		return normalized;
	}

	float Vector2D::angleBetweenVectors(const Vector2D& lhs, const Vector2D& rhs)
	{
		std::cout << dotProduct(lhs, rhs) << '\n';

		return acos(dotProduct(lhs, rhs) / (lhs.getMagnitude() * rhs.getMagnitude()));
	}

	// Utility

	void swap(Vector2D& lhs, Vector2D& rhs)
	{
		std::swap(lhs.x, rhs.x);
		std::swap(lhs.y, rhs.y);
	}


}