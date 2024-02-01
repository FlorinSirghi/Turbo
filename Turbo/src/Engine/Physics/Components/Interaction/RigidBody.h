#ifndef SCENEGRAPH_PHYSICSOBJECT_H_
#define SCENEGRAPH_PHYSICSOBJECT_H_

#include "Engine/Core/Math/Vector/Vector3D.h"
#include "Engine/Gameplay/GameObject/GameObjectModel/GameObject.h"
#include "Engine/PlatformIndependenceLayer/Time/Time.h"

namespace Turbo
{
	class RigidBody : public Component
	{

	public:

		Vector3D velocity;
		Vector3D acceleration;

		float inverseMass;

		float damping;

		bool movable;

		RigidBody(bool movable = true) : Component()
		{
			name = RIGIDBODY;
			velocity = { 0.0f, 0.0f, 0.0f };
			acceleration = { 0.0f, 0.0f, 0.0f };
			inverseMass = 1.0f;
			damping = 0.9f;
			this->movable = movable;
		}

		void update() override
		{
			
		}
	};
}

#endif // SCENEGRAPH_PHYSICSOBJECT_H_