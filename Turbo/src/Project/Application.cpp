#include "Application.h"
#include "../Engine/MainSystems/Renderer/Renderer2D/Renderer2D.h"
#include "memory"
#include "../Engine/MainSystems/SceneGraph/GameObject/PrimitiveShapes/Triangle.h"
#include "../Engine/MainSystems/SceneGraph/GameObject/UtilityObjects/OrthographicCamera.h"

namespace Turbo 
{
	Application::Application() : app_window("MyApplication", 1000, 800)
	{
		scene = std::make_unique<Scene>();

		std::shared_ptr<GameObject> go = std::make_unique<Triangle>();
		scene->addObject(go);
		std::shared_ptr<GameObject> camera = std::make_unique<OrthographicCamera>();
		scene->addObject(camera);
		EventManager::getInstance().addListener(camera);
	}

	void Application::run()
	{
		this->start();

		while (!glfwWindowShouldClose(app_window.getGLFWWindow()))
		{
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);


			for (const auto& go : scene->hierarchy)
			{
				go->update();
			}
			

			glfwSwapBuffers(app_window.getGLFWWindow());
			glfwPollEvents();
			EventManager::getInstance().pollEvent();
		}
	}

}