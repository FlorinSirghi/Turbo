#ifndef ENGINE_PHYSICS_COMPONENTS_CONTACT_CONTACT_H
#define ENGINE_PHYSICS_COMPONENTS_CONTACT_CONTACT_H
#include <array>
#include <memory>

#include "Engine/Physics/Components/Interaction/RigidBody.h"

namespace Turbo
{
	class Contact
	{
	public:

		// The colliders that have come in contact
		std::array<RigidBody*, 2> rigid_bodies;

		Vector3D contact_normal;
		float restitution_coefficient;

		// The amount of penetration
		float penetration;

		void resolve();
		float computeSeparatingVelocity() const;
		void resolveVeloctiy();
	};
}

#endif // ENGINE_PHYSICS_COMPONENTS_CONTACT_CONTACT_H
