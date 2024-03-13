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
}
