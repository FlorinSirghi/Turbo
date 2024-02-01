#include "TransformSystem.h"

namespace Turbo
{
	std::unordered_map<std::string, Vector3D> TransformSystem::positions{};
	std::unordered_map<std::string, Vector3D> TransformSystem::scales{};
	std::unordered_map<std::string, Vector3D> TransformSystem::rotations{};
}