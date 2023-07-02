#include "Application.h"
#include "../Engine/Subsystems/Renderer/Renderer2D/Renderer2D.h"
#include "memory"


namespace Turbo 
{
	Application::Application() : app_window("MyApplication", 1000, 800)
	{
		//scene->hierarchy.push_back(std::make_unique<GameObject>());
	}

	void Application::run()
	{
		this->start();

		while (!glfwWindowShouldClose(app_window.getGLFWWindow()))
		{
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			Renderer2D::draw(scene);

			glfwSwapBuffers(app_window.getGLFWWindow());
			glfwPollEvents();
			EventManager::getInstance().pollEvent();
		}
	}

}