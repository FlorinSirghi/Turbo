#ifndef ENGINE_PHYSICS_COMPONENTS_COLLIDERS_BOXCOLLIDER_H_
#define ENGINE_PHYSICS_COMPONENTS_COLLIDERS_BOXCOLLIDER_H_

#include "Engine/Core/Math/Vector/Vector3D.h"

namespace Turbo
{
	struct BoxCollider
	{
		Vector3D originalCenter;
		Vector3D originalRadius;

		Vector3D center;
		Vector3D radius;

		//std::shared_ptr<Mesh> visualRepresentation;

		//BoxCollider() : visualRepresentation(std::make_shared<Mesh>(MeshType::CUBE)){}
	};
}

#endif // ENGINE_PHYSICS_COMPONENTS_COLLIDERS_BOXCOLLIDER_H_
