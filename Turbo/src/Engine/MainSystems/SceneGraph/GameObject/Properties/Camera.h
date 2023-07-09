#pragma once

#include "Property.h"
#include "../../../Renderer/Renderer2D/Renderer2D.h"

namespace Turbo
{
	class Camera : public Property
	{
	public:

		Camera()
		{
			name = CAMERA;
		}

		void effect(std::shared_ptr<GameObject> go) override
		{
			Vector3D cameraPos = std::dynamic_pointer_cast<Position>(go->getPropertyByName(POSITION))->pos;
			Renderer2D::camera_position = cameraPos;
		}

	};
}