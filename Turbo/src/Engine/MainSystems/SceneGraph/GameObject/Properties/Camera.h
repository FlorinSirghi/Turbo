#pragma once

#include "Property.h"
#include "../../../Renderer/Renderer2D/Renderer2D.h"
#include "../../../Renderer/Renderer3D/Renderer3D.h"

namespace Turbo
{
	class Camera : public Property
	{
	public:

		Camera(std::shared_ptr<GameObject> go) : Property(go)
		{
			name = CAMERA;
		}

		void effect()
		{
			Vector3D cameraPos = std::dynamic_pointer_cast<Position>(game_object->getPropertyByName(POSITION))->pos;
			//Renderer2D::camera_position = cameraPos;
			//Renderer3D::camera_position = cameraPos;
		}

	};
}