#include "OrthographicCamera.h"
#include <iostream>
#include "../../../Renderer/Renderer2D/Renderer2D.h"
#include "../Properties/Position.h"
#include "../Properties/Camera.h"

namespace Turbo
{

	OrthographicCamera::OrthographicCamera()
	{
		this->name = "Camera";
		std::shared_ptr<Property> position = std::make_unique<Position>(name);
		addProperty(position);
		std::shared_ptr<Property> cam = std::make_unique<Camera>();
		addProperty(cam);
	}

	void OrthographicCamera::onEvent(Event event)
	{
		if (event.args[0].param == "W")
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
		}
	}

	void OrthographicCamera::update()
	{
		for (const auto& prop : properties)
			prop->effect(std::make_shared<OrthographicCamera>(*this));
	}
}