#pragma once

#include <string>
#include <string_view>
#include <memory>

namespace Turbo
{
	class GameObject;
	constexpr std::string_view MESH = "Mesh";
	constexpr std::string_view POSITION = "Position";
	constexpr std::string_view CAMERA = "Camera";


	class Property
	{
	public:

		std::string name;
		std::string object_name;

		virtual void effect(std::shared_ptr<GameObject> go) = 0;
	};
}