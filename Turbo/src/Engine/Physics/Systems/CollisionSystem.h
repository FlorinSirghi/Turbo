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

		static int TestAABBAABB(BoxCollider* a, BoxCollider* b)
		{
			if (abs(a->center.x - b->center.x) > (a->rx + b->rx))
			{
				//std::cout << "Didnt";
				return 0;
			}
			if (abs(a->center.y - b->center.y) > (a->ry + b->ry))
			{
				//std::cout << "Didnt";
				return 0;
			}
			if (abs(a->center.z - b->center.z) > (a->rz + b->rz))
			{
				//std::cout << "Didnt";
				return 0;
			}

			//std::cout << "Collided";
			return 1;
		}

		static void ResolveAABBAABB(std::shared_ptr<Scene> scene, std::shared_ptr<GameObject> a, std::shared_ptr<GameObject> b)
		{
			BoxCollider* boxColliderA = scene->getComponent<BoxCollider>(a->getID());
			BoxCollider* boxColliderB = scene->getComponent<BoxCollider>(b->getID());
			Transform* transformB = scene->getComponent<Transform>(b->getID());

			/*Vector3D penetration = Vector3D(
				sqrt(pow((boxColliderA->center.x + boxColliderA->rx) - (boxColliderB->center.x + boxColliderB->rx), 2)),
				sqrt(pow((boxColliderA->center.y + boxColliderA->ry) - (boxColliderB->center.y + boxColliderB->ry), 2)),
				sqrt(pow((boxColliderA->center.z + boxColliderA->rz) - (boxColliderB->center.z + boxColliderB->rz), 2))
			);*/

			Vector3D penetration = Vector3D(
				0.0f,
				sqrt(pow((boxColliderA->center.y + boxColliderA->ry) - (boxColliderB->center.y + boxColliderB->ry), 2)),
				0.0f);

			/*if (abs(boxColliderA->center.x - boxColliderB->center.x) <= (boxColliderA->rx + boxColliderB->rx))
			{
				penetration.x = sqrt(pow((boxColliderA->center.x + boxColliderA->rx) - (boxColliderB->center.x + boxColliderB->rx), 2));
			}
			if (abs(boxColliderA->center.y - boxColliderB->center.y) <= (boxColliderA->ry + boxColliderB->ry))
			{
				penetration.y = sqrt(pow((boxColliderA->center.y + boxColliderA->ry) - (boxColliderB->center.y + boxColliderB->ry), 2));
			}
			if (abs(boxColliderA->center.z - boxColliderB->center.z) <= (boxColliderA->rz + boxColliderB->rz))
			{
				penetration.z = sqrt(pow((boxColliderA->center.z + boxColliderA->rz) - (boxColliderB->center.z + boxColliderB->rz), 2))
			}*/

			transformB->position += penetration;
		}
	};
}

#endif// ENGINE_PHYSICS_SYSTEMS_COLLISIONSYSTEM_H_
