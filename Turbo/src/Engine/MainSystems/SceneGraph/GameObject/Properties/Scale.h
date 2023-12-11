#pragma once

#include "../../../../CoreSystems/Math/Vector/Vector3D.h"
#include "Property.h"
#include "../../../TransformSystem/TransformSystem.h"
#include "Engine/MainSystems/SceneGraph/GameObject/GameObject.h"

namespace Turbo
{
	class Scale : public Property
	{
	public:

		Vector3D scale;

		Scale(std::shared_ptr<GameObject> go) : Property(go)
		{
			name = SCALE;
			scale = { 1.0f, 1.0f, 0.0f };
		}

		void effect() override
		{
			TransformSystem::scales[game_object->getName()] = scale;
		}
	};
}
