#include "Scene.h"

#include <iostream>

namespace Turbo
{
	void Scene::addObject(std::shared_ptr<GameObject> go)
	{
		hierarchy.emplace_back(go);
	}

	std::shared_ptr<GameObject> Scene::getObjectByName(std::string_view name)
	{
		for (const auto& go : hierarchy)
			if (go->getName() == name)
				return go;
	}
}
