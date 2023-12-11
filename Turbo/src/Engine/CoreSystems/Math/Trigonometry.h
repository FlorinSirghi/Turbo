#pragma once

#include <intrin.h>

namespace Turbo
{
	class Trigonometry
	{
	public:

		static float cos(float angle)
		{
			return std::cos(angle);
			//return _mm_cos_pd(angle);
		}

		static float sin(float angle)
		{
			return std::sin(angle);
			//return _mm_sin_pd(angle);
		}

		static float fromRadiansToDegrees(float angle)
		{
			return angle * 180.0f / 3.14159265359f;
		}

		static float fromDegreesToRadians(float angle)
		{
			return angle * 3.14159265359f / 180.0f;
		}
	};
}
