#include "OrthographicCamera.h"
#include <iostream>
#include "../../../Renderer/Renderer2D/Renderer2D.h"
#include "../Properties/Position.h"
#include "../Properties/Camera.h"
#include "Engine/CoreSystems/InputOutput/InputManager.h"
#include "Engine/CoreSystems/Math/Trigonometry.h"

namespace Turbo
{

	OrthographicCamera::OrthographicCamera() : GameObject("Camera")
	{
		this->name = "Camera";
		std::shared_ptr<Property> position = std::make_unique<Position>(std::make_shared<GameObject>(*this));
		addProperty(position);
		std::shared_ptr<Property> cam = std::make_unique<Camera>(std::make_shared<GameObject>(*this));
		addProperty(cam);
		std::shared_ptr<Position> p = std::dynamic_pointer_cast<Position>(getPropertyByName(POSITION));

		direction = { 0.0f, 0.0f, 0.0f };
		up = { 0.0f, 1.0f, 0.0f };
	}

	void OrthographicCamera::onEvent(Event event)
	{
		if(event.type == KEY_PRESS)
		{
			if (event.args[0].param == "W")
			{
				std::shared_ptr<Position> position = std::dynamic_pointer_cast<Position>(getPropertyByName(POSITION));

				position->pos += direction;
				//position->pos.scale(0.1f);
			}

			if (event.args[0].param == "A")
			{
				std::shared_ptr<Position> position = std::dynamic_pointer_cast<Position>(getPropertyByName(POSITION));

				position->pos -= Vector3D::getNormalized(Vector3D::crossProduct(direction, up));
				//position->pos.scale(0.1f);
			}

			if (event.args[0].param == "S")
			{
				std::shared_ptr<Position> position = std::dynamic_pointer_cast<Position>(getPropertyByName(POSITION));

				position->pos -= direction;
				//position->pos.scale(0.1f);
			}

			if (event.args[0].param == "D")
			{
				std::shared_ptr<Position> position = std::dynamic_pointer_cast<Position>(getPropertyByName(POSITION));

				position->pos += Vector3D::getNormalized(Vector3D::crossProduct(direction, up));
				//position->pos.scale(0.1f);
			}
		}

		if (event.type == MOUSE_MOVEMENT)
		{
			yaw += InputManager::getMouseXOffset();
			pitch += InputManager::getMouseYOffset();

			if (pitch > 89.0f)
				pitch = 89.0f;
			if (pitch < -89.0f)
				pitch = -89.0f;

			Vector3D dir;

			dir.x = Trigonometry::cos(Trigonometry::fromDegreesToRadians(yaw)) * Trigonometry::cos(Trigonometry::fromDegreesToRadians(pitch));
			dir.y = Trigonometry::sin(Trigonometry::fromDegreesToRadians(pitch));
			dir.z = Trigonometry::sin(Trigonometry::fromDegreesToRadians(yaw)) * Trigonometry::cos(Trigonometry::fromDegreesToRadians(pitch));

			direction = Vector3D::getNormalized(dir);
		}

		std::shared_ptr<Position> position = std::dynamic_pointer_cast<Position>(getPropertyByName(POSITION));

		Renderer3D::camera_position = position->pos;
		Renderer3D::camera_direction = direction;
		Renderer3D::camera_up = up;
	}

	void OrthographicCamera::update()
	{
		for (const auto& prop : properties)
			prop->effect();
	}
}
