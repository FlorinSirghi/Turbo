#pragma once

#include <memory>

#include "Editor/EditorUI.h"
#include "Engine/SceneGraph/Scene/Scene.h"
#include "Engine/Core/Definitions.h"
#include "Engine/Core/IDs/IDManager.h"
#include "Engine/Physics/Systems/PhysicsSystem.h"
#include "Engine/PlatformIndependenceLayer/Window/Window.h"
#include "Engine/Renderer/Systems/Renderer3D/Renderer3D.h"

// Application to be defined in project

namespace Turbo 
{
	class TURBO_API Application
	{
	public:

		Application();

		void run();

	protected:

		virtual void start() = 0;
		virtual void update() = 0;

	private:

		const int window_height = 1000, window_width = 1920;

		Window app_window;

		std::shared_ptr<Scene> scene;

		// Managers
		std::shared_ptr<IDManager> id_manager;
		std::shared_ptr<Renderer3D> renderer3D;
		std::shared_ptr<EditorUI> editor_ui;
		std::shared_ptr<PhysicsSystem> physics_system;
	};
}
