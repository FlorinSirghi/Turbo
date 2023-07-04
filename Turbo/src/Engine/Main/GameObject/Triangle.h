#pragma once

#include "GameObject.h"
#include "Property.h"
#include "../../Subsystems/Renderer/Renderer2D/Renderer2D.h"

namespace Turbo
{
	class Triangle : public GameObject
	{
	public:
		Triangle()
		{
			std::cout << "Constructor called!";
			std::shared_ptr<Property> mesh = std::make_unique<Mesh>();
			properties.push_back(mesh);
		}

		void update() override
		{
			for (const auto& prop : properties)
				prop->effect();
		}

		void onEvent(Event event) override
		{
		
		}
	};
}