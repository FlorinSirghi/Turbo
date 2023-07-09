#pragma once

#include "../GameObject.h"
#include "../Properties/Mesh.h"
#include "../Properties/Position.h"

namespace Turbo
{
	class Triangle : public GameObject
	{
	public:
		Triangle()
		{
			this->name = "Triangle";
			std::shared_ptr<Property> position = std::make_unique<Position>(name);
			addProperty(position);

			std::shared_ptr<Property> mesh = std::make_unique<Mesh>(name);
			addProperty(mesh);
		}

		void update() override
		{
			for (const auto& prop : properties)
				prop->effect(std::make_shared<Triangle>(*this));
		}

		void onEvent(Event event) override
		{
		
		}
	};
}