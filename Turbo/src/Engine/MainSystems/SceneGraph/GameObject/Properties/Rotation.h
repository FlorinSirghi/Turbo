#pragma once

#include "../../../../CoreSystems/Math/Vector/Vector3D.h"
#include "Property.h"
#include "../../../TransformSystem/TransformSystem.h"
#include "Engine/MainSystems/SceneGraph/GameObject/GameObject.h"

namespace Turbo
{
	class Rotation : public Property
	{
	public:

		Vector3D rotation;

		Rotation(std::shared_ptr<GameObject> go) : Property(go)
		{
			name = ROTATION;
			rotation = { 1.0f, 1.0f, 0.0f };
		}

		void effect() override
		{
			TransformSystem::scales[game_object->getName()] = rotation;
		}
	};
}
