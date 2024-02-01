#ifndef ENGINE_CORE_MATH_VECTOR2_H_
#define ENGINE_CORE_MATH_VECTOR2_H_

namespace Turbo
{

	class Vector2D
	{

	public:

		// Predefined vectors

		static Vector2D zero;
		static Vector2D up;
		static Vector2D down;
		static Vector2D left;
		static Vector2D right;

		// Fields

		float x;
		float y;

		// Constructors

		Vector2D(const float& X, const float& Y);

		// Operators

		Vector2D& operator=(Vector2D rhs);

		Vector2D& operator+=(const Vector2D& rhs);
		Vector2D& operator-=(const Vector2D& rhs);
		friend Vector2D operator+(Vector2D lhs, const Vector2D& rhs);
		friend Vector2D operator-(Vector2D lhs, const Vector2D& rhs);

		Vector2D& operator-();

		// Functions

		void scale(const float& scalar);
		float getMagnitude() const;
		void normalize();

		static float dotProduct(const Vector2D& lhs, const Vector2D& rhs);
		static Vector2D& getNormalized(const Vector2D& v);
		static float angleBetweenVectors(const Vector2D& lhs, const Vector2D& rhs);


		// Utility

		friend void swap(Vector2D& lhs, Vector2D& rhs);
	};
}

#endif // ENGINE_CORE_MATH_VECTOR2_H_