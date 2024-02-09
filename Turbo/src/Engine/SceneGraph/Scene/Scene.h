#ifndef SCENEGRAPH_SCENE_H_
#define SCENEGRAPH_SCENE_H_

#include <memory>

#include "Engine/Gameplay/GameObject/GameObjectModel/ComponentPool.h"
#include "Engine/Gameplay/GameObject/GameObjectModel/GameObject.h"

namespace Turbo
{
	class Scene
	{
	public:

		void addObject(std::shared_ptr<GameObject>);
		std::shared_ptr<GameObject> getObjectByName(std::string_view);

		template<typename T, typename... Args>
		T* assignComponent(const ID& id, Args&&... args)
		{
			int componentID = getID<T>();

			//std::cout << "Id " << componentID << '\n';

			if(component_pools.size() <= componentID)
			{
				component_pools.resize(componentID + 1, nullptr);
			}

			if(component_pools[componentID] == nullptr)
			{
				component_pools[componentID] = new ComponentPool(sizeof(T));
			}

			T* component = new (component_pools[componentID]->get(id.getID())) T(std::forward<Args>(args)...);

			hierarchy[id.getID()]->componentMask.set(componentID);

			return component;
		}

		template<typename T>
		T* getComponent(const ID& id)
		{
			int componentID = getID<T>();

			//std::cout << "Id " << componentID << '\n';

			if (!hierarchy[id.getID()]->componentMask[componentID])
				return nullptr;

			T* component = static_cast<T*>(component_pools[componentID]->get(id.getID()));
			return component;
		}

		std::vector<std::shared_ptr<GameObject>> hierarchy;
		std::vector<ComponentPool*> component_pools;
	};
}

#endif // SCENEGRAPH_SCENE_H_
