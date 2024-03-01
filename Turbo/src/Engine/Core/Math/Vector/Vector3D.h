#ifndef ENGINE_CORE_MATH_VECTOR3_H_
#define ENGINE_CORE_MATH_VECTOR3_H_
#include <array>

namespace Turbo
{

	class Vector3D
	{

	public:

		// Predefined vectors

		static const Vector3D zero;
		static const Vector3D up;
		static const Vector3D down;
		static const Vector3D left;
		static const Vector3D right;

		// Fields

		float x;
		float y;
		float z;

		// Constructors

		Vector3D(const float& X, const float& Y, const float& Z);
		Vector3D();

		// Operators

		Vector3D& operator=(Vector3D rhs);

		Vector3D& operator+=(const Vector3D& rhs);
		Vector3D& operator-=(const Vector3D& rhs);
		friend Vector3D operator+(Vector3D lhs, const Vector3D& rhs);
		friend Vector3D operator-(Vector3D lhs, const Vector3D& rhs);
		friend bool operator!=(const Vector3D& lhs, const Vector3D& rhs);

		Vector3D& operator-();

		// Functions

		void set(const std::array<float, 3>&);
		std::array<float, 3> getIterable();
		void scale(const float& scalar);
		Vector3D scaled(const float& scalar);
		float getMagnitude() const;
		void normalize();

		static float dotProduct(const Vector3D& lhs, const Vector3D& rhs);
		static Vector3D crossProduct(const Vector3D& lhs, const Vector3D& rhs);
		static Vector3D getNormalized(const Vector3D& v);
		static float angleBetweenVectors(const Vector3D& lhs, const Vector3D& rhs);


		// Utility

		friend void swap(Vector3D& lhs, Vector3D& rhs);
	};
}

#endif // ENGINE_CORE_MATH_VECTOR3_H_
