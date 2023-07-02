#pragma once

#include "../Engine/Main/Definitions.h"
#include "../Engine/Subsystems/InputOutput/Window.h"
#include "../Engine/Main/Scene/Scene.h"

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

		Window app_window;

		std::shared_ptr<Scene> scene;
	};
}
