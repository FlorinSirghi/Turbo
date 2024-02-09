#ifndef ENGINE_PHYSICS_COMPONENTS_COLLIDERS_BOXCOLLIDER_H_
#define ENGINE_PHYSICS_COMPONENTS_COLLIDERS_BOXCOLLIDER_H_

#include "Engine/Core/Math/Vector/Vector3D.h"

namespace Turbo
{
	struct BoxCollider
	{
		Vector3D center;
		float rx, ry, rz;
	};
}

#endif // ENGINE_PHYSICS_COMPONENTS_COLLIDERS_BOXCOLLIDER_H_
