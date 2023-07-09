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

		// Specific for each game object

		virtual void onEvent(Event event) = 0;
		virtual void update() = 0;

		// Same for all objects

		std::shared_ptr<Property> getPropertyByName(std::string_view name);
		void addProperty(std::shared_ptr<Property> property);


		virtual ~GameObject() = default;

		// Setters & Getters

		std::string getName() { return name; }

	protected:
		std::string name;
		std::vector<std::shared_ptr<Property>> properties;

	};

}