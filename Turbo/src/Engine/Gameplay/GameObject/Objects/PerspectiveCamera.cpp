#include "PerspectiveCamera.h"

#include "OrthographicCamera.h"
#include <iostream>
#include "Engine/Renderer/Components/Camera.h"
#include "Engine/SceneGraph/Components/Transform.h"

namespace Turbo
{

	PerspectiveCamera::PerspectiveCamera(IDManager id_manager) : GameObject(id_manager.generateID(), "Camera")
	{
		this->name = "Camera";
		/*std::shared_ptr<Component> transform = std::make_unique<Transform>();
		addComponent(transform);
		std::shared_ptr<Component> cam = std::make_unique<Camera>();
		addComponent(cam);*/
	}

	void PerspectiveCamera::onEvent(Event event)
	{
		/*std::shared_ptr<Transform> transform = std::dynamic_pointer_cast<Transform>(getComponentByName(TRANSFORM));

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
		}*/
	}

	//void PerspectiveCamera::update()
	//{
	//	/*for (const auto& prop : properties)
	//		prop->effect();*/
	//}
}
