#ifndef ENGINE_PHYSICS_COMPONENTS_CONTACT_CONTACT_H
#define ENGINE_PHYSICS_COMPONENTS_CONTACT_CONTACT_H
#include <array>
#include <memory>

#include "Engine/Physics/Components/Colliders/BoxCollider.h"

namespace Turbo
{
	class Contact
	{
		// The colliders that have come in contact
		std::array<std::shared_ptr<BoxCollider>, 2> colliders;

		Vector3D contactNormal;
		float restitutionCoefficient;

		// The amount of penetration
		float penetration;
	};
}

#endif // ENGINE_PHYSICS_COMPONENTS_CONTACT_CONTACT_H
