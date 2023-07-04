#pragma once

#include "../../Subsystems/EventSystem/Event.h"
#include "../../Subsystems/GameSystem.h"
#include "Property.h"
#include <memory>

#include <vector>

namespace Turbo
{
	class GameObject
	{
	public:

		virtual void onEvent(Event event) = 0;

		virtual void update() = 0;

		virtual ~GameObject() = default;

		std::vector<std::shared_ptr<Property>> properties;
	};

}