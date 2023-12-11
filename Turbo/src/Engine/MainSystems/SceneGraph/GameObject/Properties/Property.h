#pragma once

#include <string>
#include <string_view>
#include <memory>

namespace Turbo
{
	class GameObject;
	constexpr std::string_view SPRITE = "Sprite";
	constexpr std::string_view POSITION = "Position";
	constexpr std::string_view SCALE = "Scale";
	constexpr std::string_view ROTATION = "Rotation";
	constexpr std::string_view CAMERA = "Camera";

	class Property
	{
	public:

		std::shared_ptr<GameObject> game_object;
		std::string name;

		Property(std::shared_ptr<GameObject>& go)
		{
			game_object = go;
		}

		virtual void effect() = 0;
	};
}