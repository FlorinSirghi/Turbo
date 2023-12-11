#pragma once

#include "../GameObject.h"
#include "Engine/CoreSystems/Math/Vector/Vector3D.h"

namespace Turbo
{
	class OrthographicCamera : public GameObject
	{
	public:

		Vector3D direction;
		Vector3D up;

		float pitch = 0.0f;
		float yaw = 0.0f;

		OrthographicCamera();

		void onEvent(Event event) override;

		void update() override;
	};
}
