#pragma once

#include "../GameObject.h"

namespace Turbo
{
	class PerspectiveCamera : public GameObject
	{
	public:

		PerspectiveCamera();

		void onEvent(Event event) override;

		void update() override;
	};
}