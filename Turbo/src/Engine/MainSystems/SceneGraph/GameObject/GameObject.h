#pragma once

#include "../../../CoreSystems/EventSystem/Event.h"
#include "../../GameSystem.h"
#include "Properties/Property.h"
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