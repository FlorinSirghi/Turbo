#include "PerspectiveCamera.h"

#include "OrthographicCamera.h"
#include <iostream>
#include "../../../Renderer/Renderer2D/Renderer2D.h"
#include "../Properties/Position.h"
#include "../Properties/Camera.h"

namespace Turbo
{

	PerspectiveCamera::PerspectiveCamera() : GameObject("Camera")
	{
		this->name = "Camera";
		std::shared_ptr<Property> position = std::make_unique<Position>(std::make_shared<GameObject>(*this));
		addProperty(position);
		std::shared_ptr<Property> cam = std::make_unique<Camera>(std::make_shared<GameObject>(*this));
		addProperty(cam);
	}

	void PerspectiveCamera::onEvent(Event event)
	{
		if (event.type == KEY_PRESS)
		{
			if (event.args[0].param == "W")
			{
				std::shared_ptr<Position> position = std::dynamic_pointer_cast<Position>(getPropertyByName(POSITION));

				position->pos.z += 0.5f;
			}

			if (event.args[0].param == "A")
			{
				std::shared_ptr<Position> position = std::dynamic_pointer_cast<Position>(getPropertyByName(POSITION));

				position->pos.x += -0.5f;
			}

			if (event.args[0].param == "S")
			{
				std::shared_ptr<Position> position = std::dynamic_pointer_cast<Position>(getPropertyByName(POSITION));

				position->pos.z += -0.5f;
			}

			if (event.args[0].param == "D")
			{
				std::shared_ptr<Position> position = std::dynamic_pointer_cast<Position>(getPropertyByName(POSITION));

				position->pos.x += 0.5f;
			}
		}
		else if (event.type == MOUSE_MOVEMENT)
		{
			std::shared_ptr<Position> position = std::dynamic_pointer_cast<Position>(getPropertyByName(POSITION));

			position->pos.x -= std::stof(event.args[0].param);
			position->pos.y += std::stof(event.args[1].param);
		}
	}

	void PerspectiveCamera::update()
	{
		for (const auto& prop : properties)
			prop->effect();
	}
}