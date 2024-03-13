#include "CollisionSystem.h"

#include "Engine/Core/Math/Matrix/Matrix3.h"
#include "Engine/Core/Math/Matrix/Matrix4.h"
#include "Engine/Physics/Components/Contact/Contact.h"
#include "Engine/Physics/Components/Interaction/RigidBody.h"

namespace Turbo
{
	int CollisionSystem::TestAABBAABB(BoxCollider* a, BoxCollider* b)
	{
		if (abs(a->center.x - b->center.x) > (a->radius.x + b->radius.x))
		{
			//std::cout << "Didnt";
			return 0;
		}
		if (abs(a->center.y - b->center.y) > (a->radius.y + b->radius.y))
		{
			//std::cout << "Didnt";
			return 0;
		}
		if (abs(a->center.z - b->center.z) > (a->radius.z + b->radius.z))
		{
			//std::cout << "Didnt";
			return 0;
		}

		//std::cout << "Collided";
		return 1;
	}

	void CollisionSystem::ResolveAABBAABB(std::shared_ptr<Scene> scene, std::shared_ptr<GameObject> a, std::shared_ptr<GameObject> b)
	{
		//BoxCollider* boxColliderA = scene->getComponent<BoxCollider>(a->getID());
		//BoxCollider* boxColliderB = scene->getComponent<BoxCollider>(b->getID());
		//Transform* transformB = scene->getComponent<Transform>(a->getID());

		//std::cout << "Obiect A" << a->getName() << '\n';
		//std::cout << "Obiect B" << b->getName() << "\n\n";

		//Vector3D penetration = Vector3D(0.0f, 0.0f, 0.0f);

		//if (abs(boxColliderA->center.x - boxColliderB->center.x) <= (boxColliderA->radius.x + boxColliderB->radius.x))
		//{
		//	//penetration.x = sqrt(pow((boxColliderA->center.x + boxColliderA->radius.x) - (boxColliderB->center.x + boxColliderB->radius.x), 2));
		//}
		//if (abs(boxColliderA->center.y - boxColliderB->center.y) <= (boxColliderA->radius.y + boxColliderB->radius.y))
		//{
		//	penetration.y = sqrt(pow((boxColliderA->center.y + boxColliderA->radius.y) - (boxColliderB->center.y + boxColliderB->radius.y), 2));
		//}
		//if (abs(boxColliderA->center.z - boxColliderB->center.z) <= (boxColliderA->radius.z + boxColliderB->radius.z))
		//{
		//	//penetration.z = sqrt(pow((boxColliderA->center.z + boxColliderA->radius.z) - (boxColliderB->center.z + boxColliderB->radius.z), 2));
		//}

		//transformB->position += penetration;

		RigidBody* rigid_body_A = scene->getComponent<RigidBody>(a->getID());
		RigidBody* rigid_body_B = scene->getComponent<RigidBody>(b->getID());
		Transform* transformA = scene->getComponent<Transform>(a->getID());
		Transform* transformB = scene->getComponent<Transform>(b->getID());

		Contact* contact = new Contact();

		if (b->name == "Floor")
		{
			contact->rigid_bodies[0] = rigid_body_A;
			//contact->rigid_bodies[1] = rigid_body_B;
			contact->restitution_coefficient = 0.1f;
			//contact->contact_normal = Vector3D::getNormalized((transformA->position - transformB->position));
			contact->contact_normal = { 0.0f, 1.0f, 0.0f };

			contact->resolve();

			//std::cout << rigid_body_A->velocity.x << ' ' << rigid_body_A->velocity.y << ' ' << rigid_body_A->velocity.z << '\n';
		}
		else if (a->name == "Floor")
		{
			contact->rigid_bodies[0] = rigid_body_B;
			//contact->rigid_bodies[1] = rigid_body_B;
			contact->restitution_coefficient = 0.1f;
			//contact->contact_normal = Vector3D::getNormalized((transformA->position - transformB->position));
			contact->contact_normal = { 0.0f, 1.0f, 0.0f };

			contact->resolve();

			//std::cout << rigid_body_A->velocity.x << ' ' << rigid_body_A->velocity.y << ' ' << rigid_body_A->velocity.z << '\n';
		}
		else
		{
			contact->rigid_bodies[0] = rigid_body_A;
			contact->rigid_bodies[1] = rigid_body_B;
			contact->restitution_coefficient = 0.1f;
			contact->contact_normal = Vector3D::getNormalized((transformA->position - transformB->position));
			//contact->contact_normal = { 0.0f, 1.0f, 0.0f };

			contact->resolve();

			//std::cout << rigid_body_A->velocity.x << ' ' << rigid_body_A->velocity.y << ' ' << rigid_body_A->velocity.z << '\n';
		}
	}

	void CollisionSystem::update(std::shared_ptr<Scene>& scene)
	{
		updateAABB(scene);
	}

	void CollisionSystem::updateAABB(std::shared_ptr<Scene>& scene)
	{
		int bcID = getID<BoxCollider>();

		for (auto go : scene->hierarchy)
		{
			if (go->componentMask[bcID])
			{
				Transform* transform = scene->getComponent<Transform>(go->getID());
				BoxCollider* boxcollider = scene->getComponent<BoxCollider>(go->getID());
				RigidBody* rb{ scene->getComponent<RigidBody>(go->getID()) };

				Matrix4 rotation = Matrix4::rotationMatrix(transform->rotation);

				Vector3D t = transform->position;

				auto m = rotation.getIterable();

				std::array<float, 3> bc = { 0.0f, 0.0f, 0.0f };
				std::array<float, 3> br = { 0.0f, 0.0f, 0.0f };

				for (int i = 0; i < 3; i++)
				{
					bc[i] = t.getIterable()[i];
					br[i] = 0.0f;
					for (int j = 0; j < 3; j++)
					{
						bc[i] += m[i][j] * boxcollider->originalCenter.getIterable()[j];
						br[i] += abs(m[i][j]) * boxcollider->originalRadius.getIterable()[j];
					}
				}

				/*std::cout << "Center : ";
				for (auto val : bc)
					std::cout << val << ' ';
				std::cout << '\n';*/

				boxcollider->center.set(bc);
				boxcollider->radius.set(br);
				rb->rotated = false;
			}
		}
	}
}
