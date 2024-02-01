#ifndef SCENEGRAPH_SCENE_H_
#define SCENEGRAPH_SCENE_H_

#include <memory>

#include "Engine/Gameplay/GameObject/GameObjectModel/GameObject.h"

namespace Turbo
{
	class Scene
	{
	public:

		void addObject(std::shared_ptr<GameObject>);
		std::shared_ptr<GameObject> getObjectByName(std::string_view);

		std::vector<std::shared_ptr<GameObject>> hierarchy;

	private:

	};
}

#endif // SCENEGRAPH_SCENE_H_
