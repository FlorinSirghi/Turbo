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

		GameObject(const std::string& obj_name) : name(obj_name){
		} 

		// Specific for each game object

		virtual void onEvent(Event event)
		{
			
		}
		virtual void update()
		{
			for (const auto& prop : properties)
				prop->effect();
		}

		// Same for all objects

		std::shared_ptr<Property> getPropertyByName(std::string_view name);
		void addProperty(std::shared_ptr<Property> property);


		virtual ~GameObject() = default;

		// Setters & Getters

		std::string getName() { return name; }
		void setName(const std::string_view name) { this->name = name; }

	protected:

		std::string name;
		std::vector<std::shared_ptr<Property>> properties;

	};

}
