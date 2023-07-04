#pragma once

#include "GameObject.h"

namespace Turbo
{
	class OrthographicCamera : public GameObject
	{
	public:

		void onEvent(Event event) override;

		void update() override;
	};
}