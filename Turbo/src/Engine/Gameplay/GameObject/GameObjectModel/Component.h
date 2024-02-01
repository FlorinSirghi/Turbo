#ifndef ENGINE_GAMEPLAY_GAMEOBJECT_GAMEOBJECTMODEL_COMPONENT_H_
#define ENGINE_GAMEPLAY_GAMEOBJECT_GAMEOBJECTMODEL_COMPONENT_H_

#include <memory>
#include <string>

namespace Turbo
{
	constexpr std::string_view TRANSFORM = "TRANSFORM";
	constexpr std::string_view SPRITE = "SPRITE";
	constexpr std::string_view CAMERA = "CAMERA";
	constexpr std::string_view RIGIDBODY = "RIGIDBODY";
	constexpr std::string_view BOXCOLLIDER = "BOXCOLLIDER";

	class Component
	{
	public:

		std::string name;

		Component() = default;

		virtual void update() = 0;
	};
}

#endif // ENGINE_GAMEPLAY_GAMEOBJECT_GAMEOBJECTMODEL_COMPONENT_H_
