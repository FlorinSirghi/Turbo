#pragma once

#include "../GameObject.h"
#include "../Properties/Mesh.h"

namespace Turbo
{
	class Triangle : public GameObject
	{
	public:
		Triangle()
		{
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