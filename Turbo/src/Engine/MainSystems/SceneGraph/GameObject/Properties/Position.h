#pragma once

#include "../../../../CoreSystems/Math/Vector/Vector3D.h"
#include "Property.h"
#include "../../../TransformSystem/TransformSystem.h"

namespace Turbo
{
	class Position : public Property
	{
	public:

		Vector3D pos;

		Position(const std::string& game_object_name)
		{
			name = POSITION;
			pos = {0.0f, 0.0f, 0.0f};
			object_name = game_object_name;

		}

		void effect(std::shared_ptr<GameObject> go) override
		{
			TransformSystem::positions[object_name] = pos;
		}
	};
}
