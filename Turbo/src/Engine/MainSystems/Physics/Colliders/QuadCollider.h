#pragma once

#include "ICollider.h"
#include "Engine/MainSystems/SceneGraph/GameObject/Properties/Property.h"

namespace Turbo
{
	class QuadCollider : public ICollider, Property
	{
		float top_left_x, top_left_y, width, height;

		QuadCollider(std::shared_ptr<GameObject> go) : Property(go)
		{
			// calculeaza pozitiile bazat pe pozitia obiectului
		}

		void effect() override
		{
			
		}
	};
}
