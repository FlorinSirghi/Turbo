#ifndef EDITOR_EDITOR_UI_H_
#define EDITOR_EDITOR_UI_H_

#include <memory>

#include "Engine/Core/IDs/IDManager.h"
#include "Engine/PlatformIndependenceLayer/Window/Window.h"
#include "Engine/SceneGraph/Scene/Scene.h"
#include "Engine/Gameplay/EditorActions/ObjectCreator.h"

namespace Turbo
{
	class EditorUI
	{
	public:

		EditorUI(std::shared_ptr<IDManager> id_manager, GLFWwindow* window, std::shared_ptr<Scene>& scene);

		// Structure

		void init(GLFWwindow* window);
		void update(double FPS, std::shared_ptr<Scene>& s);

		// UI actions

		void createNewObject();

	private:

		std::shared_ptr<ObjectCreator> object_creator;
		std::shared_ptr<Scene> scene;
		int selected;
	};
}

#endif
