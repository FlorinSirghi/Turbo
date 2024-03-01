#ifndef ENGINE_PHYSICS_SYSTEMS_COLLISIONSYSTEM_H_
#define ENGINE_PHYSICS_SYSTEMS_COLLISIONSYSTEM_H_

#include <cmath>
#include <iostream>

#include "Engine/Gameplay/GameObject/GameObjectModel/GameObject.h"
#include "Engine/Physics/Components/Colliders/BoxCollider.h"
#include "Engine/SceneGraph/Components/Transform.h"
#include "Engine/SceneGraph/Scene/Scene.h"

namespace Turbo
{
	class CollisionSystem
	{
	public:
		int updated = 0;
		int TestAABBAABB(BoxCollider* a, BoxCollider* b);
		void ResolveAABBAABB(std::shared_ptr<Scene> scene, std::shared_ptr<GameObject> a, std::shared_ptr<GameObject> b);

		void update(std::shared_ptr<Scene>& scene);
		void updateAABB(std::shared_ptr<Scene>& scene);
	};
}

#endif// ENGINE_PHYSICS_SYSTEMS_COLLISIONSYSTEM_H_
