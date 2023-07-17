#include "Application.h"
#include "../Engine/MainSystems/Renderer/Renderer2D/Renderer2D.h"
#include "memory"
#include "../Engine/MainSystems/SceneGraph/GameObject/PrimitiveShapes/Triangle.h"
#include "../Engine/MainSystems/SceneGraph/GameObject/UtilityObjects/OrthographicCamera.h"
#include "chrono"
#include "imgui.h"
#include "../Engine/CoreSystems/Time/Time.h"
#include "../Engine/CoreSystems/InputOutput/InputManager.h"
#include "Editor/EditorUI.h"
#include "Editor/imgui_impl_opengl3.h"

namespace Turbo
{
	Application::Application() : app_window("MyApplication", 1000, 800)
	{
		EditorUI::start(app_window.getGLFWWindow());

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
			double frame_time = 1.0 / 60.0;
			double start_time = glfwGetTime();

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			for (const auto& go : scene->hierarchy)
			{
				go->update();
			}

			for (char c : InputManager::getAllHeldDown())
			{
				Event e;

				e.argCount = 1;
				e.type = KEY_PRESS;
				EventArg<std::string> arg;

				arg.param = c;

				e.args.emplace_back(arg);

				EventManager::getInstance().postEvent(e);
			}

			EditorUI::update();

			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			glfwSwapBuffers(app_window.getGLFWWindow());
			glfwPollEvents();
			EventManager::getInstance().pollEvent();

			double end_time = glfwGetTime();

			Time::delta_time = end_time - start_time;
			if (Time::delta_time < frame_time)
				Time::delta_time = frame_time;
			//std::cout << 1 / Time::delta_time << " FPS" << '\n';
		}
	}

}
