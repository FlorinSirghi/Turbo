#pragma once

#include "../Engine/CoreSystems/Definitions.h"
#include "../Engine/CoreSystems/InputOutput/Window.h"
#include "../Engine/MainSystems/SceneGraph/Scene/Scene.h"
#include "../Engine/CoreSystems/Math/Vector/Vector3D.h"
#include "../Engine/MainSystems/SceneGraph/GameObject/Properties/Position.h"

// Application to be defined in project

namespace Turbo 
{
	class TURBO_API Application
	{
	public:

		Application();

		void run();

		Vector3D getCameraPosition()
		{
			for(const auto& go : scene->hierarchy)
			{
				if (go->getName() == "Camera")
					return std::dynamic_pointer_cast<Position>(go->getPropertyByName("Position"))->pos;
			}
		}

	protected:

		virtual void start() = 0;
		virtual void update() = 0;

	private:

		const int window_height = 1000, window_width = 1920;

		Window app_window;

		std::shared_ptr<Scene> scene;
	};
}
