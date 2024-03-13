#include "ObjectCreator.h"

#include <memory>

#include "Engine/Core/Math/Vector/Vector3D.h"
#include "Engine/Physics/Components/Colliders/BoxCollider.h"
#include "Engine/Physics/Components/Interaction/RigidBody.h"
#include "Engine/Renderer/Components/Mesh.h"
#include "Engine/SceneGraph/Components/Transform.h"

namespace Turbo
{
	ObjectCreator::ObjectCreator(std::shared_ptr<IDManager> id_manager)
	{
		this->id_manager = id_manager;
	}

	void ObjectCreator::createCube(std::shared_ptr<Scene>& scene)
	{
		std::shared_ptr<GameObject> go = std::make_unique<GameObject>(id_manager->generateID(), "dasdsa");
		scene->addObject(go);

		Vector3D position{ float(rand() % 20 * (rand() % 2 == 1 ? 1 : -1)),
						   float(rand() % 20 * (rand() % 2 == 1 ? 1 : -1)),
						   float(rand() % 20 * (rand() % 2 == 1 ? 1 : -1)) };
		Vector3D scale{ float(rand() % 10 + 1),
						float(rand() % 10 + 1),
						float(rand() % 10 + 1) };

		Vector3D rotation{ 45.0f, .0f, .0f };
		/*Vector3D position{0.0f, 0.0f, 0.0f};
		Vector3D scale{ 1.0f, 1.0f, 1.0f };*/


		//Vector3D rotation{ 0.0f, 0.0f, 0.0f };

		Transform* transform = scene->assignComponent<Transform>(go->getID());
		transform->position = position;
		transform->scale = scale;
		transform->rotation = rotation;

		scene->assignComponent<Mesh>(go->getID(), MeshType::CUBE);
		auto bc = scene->assignComponent<BoxCollider>(go->getID());
		/*bc->center = position;
		bc->originalCenter = position;*/
		bc->radius = { scale.x / 2.0f, scale.y / 2.0f, scale.z / 2.0f };
		bc->originalRadius = bc->radius;
		scene->assignComponent<RigidBody>(go->getID());
	}
}
