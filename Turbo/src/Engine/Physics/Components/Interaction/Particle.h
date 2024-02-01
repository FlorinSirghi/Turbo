#ifndef ENGINE_PHYSICS_COMPONENTS_PROPERTIES_PARTICLE_H_
#define ENGINE_PHYSICS_COMPONENTS_PROPERTIES_PARTICLE_H_

#include "Engine/Core/Math/Vector/Vector3D.h"
#include "Engine/Gameplay/GameObject/GameObjectModel/Property.h"

namespace Turbo
{
	class Particle : public Property
	{
		Vector3D velocity;
		Vector3D acceleration;

		float damping;

		float inverse_mass;
	};
}

#endif // ENGINE_PHYSICS_COMPONENTS_PROPERTIES_PARTICLE_H_
