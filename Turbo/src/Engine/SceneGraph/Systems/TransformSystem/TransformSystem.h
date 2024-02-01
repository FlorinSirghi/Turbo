#ifndef SCENEGRAPH_TRANSFORMSYSTEM_H_
#define SCENEGRAPH_TRANSFORMSYSTEM_H_

#include <unordered_map>
#include <string>

#include "Engine/Core/Math/Vector/Vector3D.h"

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

#endif // SCENEGRAPH_TRANSFORMSYSTEM_H_
