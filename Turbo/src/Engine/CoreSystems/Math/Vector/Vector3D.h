#pragma once

namespace Turbo
{

	class Vector3D
	{

	public:

		// Predefined vectors

		static Vector3D zero;
		static Vector3D up;
		static Vector3D down;
		static Vector3D left;
		static Vector3D right;

		// Fields

		float x;
		float y;
		float z;

		// Constructors

		Vector3D(const float& X, const float& Y, const float& Z);

		// Operators

		Vector3D& operator=(Vector3D rhs);

		Vector3D& operator+=(const Vector3D& rhs);
		Vector3D& operator-=(const Vector3D& rhs);
		friend Vector3D operator+(Vector3D lhs, const Vector3D& rhs);
		friend Vector3D operator-(Vector3D lhs, const Vector3D& rhs);

		Vector3D& operator-();

		// Functions

		void scale(const float& scalar);
		float getMagnitude() const;
		void normalize();

		static float dotProduct(const Vector3D& lhs, const Vector3D& rhs);
		static Vector3D& crossProduct(const Vector3D& lhs, const Vector3D& rhs);
		static Vector3D& getNormalized(const Vector3D& v);
		static float angleBetweenVectors(const Vector3D& lhs, const Vector3D& rhs);


		// Utility

		friend void swap(Vector3D& lhs, Vector3D& rhs);
	};
}
