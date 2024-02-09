#include "OrthographicCamera.h"
#include <iostream>
#include "Engine/Core/Math/Trigonometry.h"
#include "Engine/Gameplay/EventSystem/Event.h"
#include "Engine/HIDEngine/InputOutput/InputSystem.h"
#include "Engine/Renderer/Components/Camera.h"
#include "Engine/Renderer/Systems/Renderer3D/Renderer3D.h"
#include "Engine/Core/IDS/IDManager.h"
#include "Engine/SceneGraph/Components/Transform.h"

namespace Turbo
{

	OrthographicCamera::OrthographicCamera(std::shared_ptr<IDManager> id_manager) : GameObject(id_manager->generateID(), "Camera")
	{
		this->name = "OrthographicCamera";

		/*std::shared_ptr<Component> transform = std::make_unique<Transform>();
		addComponent(transform);

		std::shared_ptr<Component> cam = std::make_unique<Camera>();
		addComponent(cam);*/

		//direction = { 0.0f, 0.0f, 0.0f };
		//up = { 0.0f, 1.0f, 0.0f };
	}

	void OrthographicCamera::onEvent(Event event)
	{
		/*std::shared_ptr<Transform> transform = std::dynamic_pointer_cast<Transform>(getComponentByName(TRANSFORM));

		if(event.type == KEY_PRESS)
		{
			if (event.args[0].param == "W")
			{
				transform->position += direction;
			}

			if (event.args[0].param == "A")
			{
				transform->position -= Vector3D::getNormalized(Vector3D::crossProduct(direction, up));
			}

			if (event.args[0].param == "S")
			{
				transform->position -= direction;
			}

			if (event.args[0].param == "D")
			{
				transform->position += Vector3D::getNormalized(Vector3D::crossProduct(direction, up));
			}
		}

		if (event.type == MOUSE_MOVEMENT)
		{
			const float sensitivity = 0.3f;
			yaw += (InputSystem::getMouseXOffset() * sensitivity);
			pitch += (InputSystem::getMouseYOffset() * sensitivity);

			if (pitch > 89.0f)
				pitch = 89.0f;
			if (pitch < -89.0f)
				pitch = -89.0f;

			Vector3D dir;

			dir.x = Trigonometry::cos(Trigonometry::fromDegreesToRadians(yaw)) * Trigonometry::cos(Trigonometry::fromDegreesToRadians(pitch));
			dir.y = Trigonometry::sin(Trigonometry::fromDegreesToRadians(pitch));
			dir.z = Trigonometry::sin(Trigonometry::fromDegreesToRadians(yaw)) * Trigonometry::cos(Trigonometry::fromDegreesToRadians(pitch));

			direction = Vector3D::getNormalized(dir);
		}*/
	}
}
