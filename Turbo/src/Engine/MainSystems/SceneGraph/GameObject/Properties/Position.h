#pragma once

#include "../../../../CoreSystems/Math/Vector/Vector3D.h"
#include "Property.h"
#include "../../../TransformSystem/TransformSystem.h"
#include "Engine/MainSystems/SceneGraph/GameObject/GameObject.h"

namespace Turbo
{
	class Position : public Property
	{
	public:

		Vector3D pos;

		Position(std::shared_ptr<GameObject> go) : Property(go)
		{
			name = POSITION;
			pos = {0.0f, 0.0f, 0.0f};
		}

		void effect() override
		{
			TransformSystem::positions[game_object->getName()] = pos;
		}
	};
}
