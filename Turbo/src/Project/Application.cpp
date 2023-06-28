#include "Application.h"
#include "../Engine/Subsystems/Renderer/Renderer2D/Renderer2D.h"


namespace Turbo 
{
	Application::Application() : app_window("MyApplication", 1000, 800)
	{

	}

	void Application::run()
	{
		Turbo::Renderer2D renderer;
		renderer.createTriangle();
		this->start();

		app_window.loop();
	}

}