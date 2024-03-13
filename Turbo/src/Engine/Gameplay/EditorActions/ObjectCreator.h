#ifndef EDITOR_EDITORACTIONS_OBJECTCREATOR_H
#define EDITOR_EDITORACTIONS_OBJECTCREATOR_H

#include "Engine/Core/IDs/IDManager.h"
#include "Engine/SceneGraph/Scene/Scene.h"

namespace Turbo
{
	class ObjectCreator
	{
	public:

		ObjectCreator(std::shared_ptr<IDManager> id_manager);

		void createCube(std::shared_ptr<Scene>& scene);

	private:

		std::shared_ptr<IDManager> id_manager;

	};
}

#endif // EDITOR_EDITORACTIONS_OBJECTCREATOR_H