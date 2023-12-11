#pragma once

#include "../../CoreSystems/Math/Vector/Vector3D.h"

#include <unordered_map>
#include <string>

namespace Turbo
{
	class TransformSystem
	{
	public:

		static std::unordered_map<std::string, Vector3D> positions;
		static std::unordered_map<std::string, Vector3D> scales;
		static std::unordered_map<std::string, Vector3D> rotations;
	};
}

