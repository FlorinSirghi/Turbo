#include "CameraSystem.h"

#include "Engine/Core/Math/Trigonometry.h"
#include "Engine/Core/Math/Vector/Vector3D.h"
#include "Engine/HIDEngine/InputOutput/InputSystem.h"
#include "Engine/PlatformIndependenceLayer/Time/Time.h"
#include "Engine/Renderer/Components/Camera.h"
#include "Engine/SceneGraph/Components/Transform.h"
#include "Engine/SceneGraph/Scene/Scene.h"

namespace Turbo
{
	void CameraSystem::processCameras(std::shared_ptr<Scene> scene)
	{
		for (int i = 0; i < scene->hierarchy.size(); i++)
		{
			auto camera_component = scene->getComponent<Camera>(scene->hierarchy[i]->getID());

			if (camera_component)
			{
				auto transform_component = scene->getComponent<Transform>(scene->hierarchy[i]->getID());

				if (InputSystem::isKeyHoldDown('W'))
				{
					transform_component->position += camera_component->direction.scaled(Time::delta_time * speed);
				}

				if (InputSystem::isKeyHoldDown('A'))
				{
					transform_component->position -= Vector3D::getNormalized(Vector3D::crossProduct(camera_component->direction, camera_component->up)).scaled(Time::delta_time * speed);
				}

				if (InputSystem::isKeyHoldDown('S'))
				{
					transform_component->position -= camera_component->direction.scaled(Time::delta_time * speed);
				}

				if (InputSystem::isKeyHoldDown('D'))
				{
					transform_component->position += Vector3D::getNormalized(Vector3D::crossProduct(camera_component->direction, camera_component->up)).scaled(Time::delta_time * speed);
				}

				if (InputSystem::isMouseButtonHoldDown('l'))
				{

					if (const auto last_mouse_left_click_positions = InputSystem::getLastMouseLeftClickPositions(); 
						last_mouse_left_click_positions.x >= 200 && last_mouse_left_click_positions.x <= 1300 &&
						last_mouse_left_click_positions.y >= 180 && last_mouse_left_click_positions.y <= 1080)
					{

						camera_component->yaw += (InputSystem::getMouseXOffset() * sensitivity);
						camera_component->pitch += (InputSystem::getMouseYOffset() * sensitivity);

						if (camera_component->pitch > 89.0f)
							camera_component->pitch = 89.0f;
						if (camera_component->pitch < -89.0f)
							camera_component->pitch = -89.0f;

						Vector3D dir;

						dir.x = Trigonometry::cos(Trigonometry::fromDegreesToRadians(camera_component->yaw)) *
							Trigonometry::cos(Trigonometry::fromDegreesToRadians(camera_component->pitch));
						dir.y = Trigonometry::sin(Trigonometry::fromDegreesToRadians(camera_component->pitch));
						dir.z = Trigonometry::sin(Trigonometry::fromDegreesToRadians(camera_component->yaw)) *
							Trigonometry::cos(Trigonometry::fromDegreesToRadians(camera_component->pitch));

						camera_component->direction = Vector3D::getNormalized(dir);

						//std::cout << transform_component->position.x << ' ' << transform_component->position.y << ' ' << transform_component->position.y << '\n';
					}
				}
			}
		}
	}
}