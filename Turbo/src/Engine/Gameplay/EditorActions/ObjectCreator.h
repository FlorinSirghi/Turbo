#ifndef EDITOR_EDITORACTIONS_OBJECTCREATOR_H
#define EDITOR_EDITORACTIONS_OBJECTCREATOR_H

#include "Engine/Core/IDs/IDManager.h"

namespace Turbo
{
	class ObjectCreator
	{
	public:

		ObjectCreator(std::shared_ptr<IDManager> id_manager);

		void createCube();

	private:

		std::shared_ptr<IDManager> id_manager;

	};
}

#endif // EDITOR_EDITORACTIONS_OBJECTCREATOR_H