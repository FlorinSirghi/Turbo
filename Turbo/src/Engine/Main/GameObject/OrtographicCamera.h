#pragma once

#include "GameObject.h"

namespace Turbo
{
	class OrtographicCamera : public GameObject
	{
	public:

		void onEvent(Event event) override;

		void update() override;
	};
}