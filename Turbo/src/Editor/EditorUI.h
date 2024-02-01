#ifndef EDITOR_EDITOR_UI_H_
#define EDITOR_EDITOR_UI_H_

#include "Engine/Core/IDs/IDManager.h"
#include "Engine/PlatformIndependenceLayer/Window/Window.h"

namespace Turbo
{
	class EditorUI
	{
	public:

		EditorUI(std::shared_ptr<IDManager> id_manager, GLFWwindow* window);

		// Structure

		void init(GLFWwindow* window);
		void update(double FPS, std::vector<std::shared_ptr<GameObject>> hierarchy);

		// UI actions

		void createNewObject();

	private:
	};
}

#endif
