#pragma once

namespace Turbo
{

	class Vector4D
	{

	public:

		// Predefined vectors

		static Vector4D zero;
		static Vector4D up;
		static Vector4D down;
		static Vector4D left;
		static Vector4D right;

		// Fields

		float x;
		float y;
		float z;
		float w;

		// Constructors

		Vector4D(const float& X, const float& Y, const float& Z, const float& W);

		// Operators

		Vector4D& operator=(Vector4D rhs);

		Vector4D& operator+=(const Vector4D& rhs);
		Vector4D& operator-=(const Vector4D& rhs);
		friend Vector4D operator+(Vector4D lhs, const Vector4D& rhs);
		friend Vector4D operator-(Vector4D lhs, const Vector4D& rhs);

		Vector4D& operator-();

		// Functions

		void scale(const float& scalar);
		float getMagnitude() const;
		void normalize();

		static float dotProduct(const Vector4D& lhs, const Vector4D& rhs);
		static Vector4D& getNormalized(const Vector4D& v);
		static float angleBetweenVectors(const Vector4D& lhs, const Vector4D& rhs);


		// Utility

		friend void swap(Vector4D& lhs, Vector4D& rhs);
	};
}
