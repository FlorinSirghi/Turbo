#include "OrthographicCamera.h"
#include <iostream>
#include "../../../Renderer/Renderer2D/Renderer2D.h"
#include "../Properties/Position.h"
#include "../Properties/Camera.h"

namespace Turbo
{

	OrthographicCamera::OrthographicCamera() : GameObject("Camera")
	{
		this->name = "Camera";
		std::shared_ptr<Property> position = std::make_unique<Position>(std::make_shared<GameObject>(*this));
		addProperty(position);
		std::shared_ptr<Property> cam = std::make_unique<Camera>(std::make_shared<GameObject>(*this));
		addProperty(cam);
	}

	void OrthographicCamera::onEvent(Event event)
	{
		std::shared_ptr<Position> position = std::dynamic_pointer_cast<Position>(getPropertyByName(POSITION));

		position->pos.x -= std::stof(event.args[0].param) / 10;
		position->pos.y += std::stof(event.args[1].param) / 10;

		/*if (event.args[0].param == "W")
		{
			std::shared_ptr<Position> position = std::dynamic_pointer_cast<Position>(getPropertyByName(POSITION));

			position->pos.y += 0.1f;
		}

		if (event.args[0].param == "A")
		{
			std::shared_ptr<Position> position = std::dynamic_pointer_cast<Position>(getPropertyByName(POSITION));

			position->pos.x += -0.1f;
		}

		if (event.args[0].param == "S")
		{
			std::shared_ptr<Position> position = std::dynamic_pointer_cast<Position>(getPropertyByName(POSITION));

			position->pos.y += -0.1f;
		}

		if (event.args[0].param == "D")
		{
			std::shared_ptr<Position> position = std::dynamic_pointer_cast<Position>(getPropertyByName(POSITION));

			position->pos.x += 0.1f;
		}*/

		
	}

	void OrthographicCamera::update()
	{
		for (const auto& prop : properties)
			prop->effect();
	}
}