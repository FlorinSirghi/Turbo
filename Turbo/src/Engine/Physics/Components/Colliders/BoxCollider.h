#ifndef ENGINE_PHYSICS_COMPONENTS_COLLIDERS_BOXCOLLIDER_H_
#define ENGINE_PHYSICS_COMPONENTS_COLLIDERS_BOXCOLLIDER_H_

#include "Engine/Core/Math/Vector/Vector3D.h"
#include "Engine/Gameplay/GameObject/GameObjectModel/Component.h"

namespace Turbo
{
	class BoxCollider : public Component
	{
	public:

		BoxCollider();

		Vector3D center;
		float rx, ry, rz;

		void update() override
		{
		}
	};
}

#endif // ENGINE_PHYSICS_COMPONENTS_COLLIDERS_BOXCOLLIDER_H_
