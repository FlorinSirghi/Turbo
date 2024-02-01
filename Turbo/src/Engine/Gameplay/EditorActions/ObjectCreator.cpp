#include "ObjectCreator.h"

#include <memory>

#include "Engine/Core/Math/Vector/Vector3D.h"
#include "Engine/Gameplay/GameObject/GameObjectModel/Component.h"
#include "Engine/SceneGraph/Components/Transform.h"

namespace Turbo
{
	ObjectCreator::ObjectCreator(std::shared_ptr<IDManager> id_manager)
	{
		this->id_manager = id_manager;
	}

	void ObjectCreator::createCube()
	{
		/*std::shared_ptr<GameObject> go = std::make_unique<GameObject>(id_manager->generateID(), "Cube");

		Vector3D position{ float(rand() % 20 * (rand() % 2 == 1 ? 1 : -1)),
						   float(rand() % 20 * (rand() % 2 == 1 ? 1 : -1)),
						   float(rand() % 20 * (rand() % 2 == 1 ? 1 : -1)) };
		Vector3D scale{ float(rand() % 5 + 1),
						float(rand() % 5 + 1),
						float(rand() % 5 + 1) };

		Vector3D rotation{ float(rand() % 3 + 1),
						  float(rand() % 3 + 1),
						  float(rand() % 3 + 1) };

		std::shared_ptr<Component> transform = std::make_unique<Transform>(position, scale, rotation);
		go->addComponent(transform);

		std::shared_ptr<Component> mesh = std::make_shared<Mesh>(MeshType::CUBE);
		go->addComponent(mesh);*/
	}
}
