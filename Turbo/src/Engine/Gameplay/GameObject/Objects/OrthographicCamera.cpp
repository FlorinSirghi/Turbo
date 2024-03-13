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
}
