#pragma once

#include "../GameObject.h"

namespace Turbo
{
	class OrthographicCamera : public GameObject
	{
	public:

		OrthographicCamera();

		void onEvent(Event event) override;

		void update() override;
	};
}