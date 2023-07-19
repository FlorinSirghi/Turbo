#include "Application.h"
#include "../Engine/MainSystems/Renderer/Renderer2D/Renderer2D.h"
#include "memory"
#include "chrono"
#include "imgui.h"
#include "../Engine/CoreSystems/Time/Time.h"
#include "../Engine/CoreSystems/InputOutput/InputManager.h"
#include "Editor/EditorUI.h"
#include "Editor/imgui_impl_opengl3.h"
#include "Engine/MainSystems/SceneGraph/GameObject/Properties/Camera.h"
#include "Engine/MainSystems/SceneGraph/GameObject/Properties/Mesh.h"
#include "Engine/MainSystems/SceneGraph/GameObject/UtilityObjects/OrthographicCamera.h"

namespace Turbo
{
	Application::Application() : app_window("MyApplication", 1600, 900)
	{
		EditorUI::start(app_window.getGLFWWindow());

		scene = std::make_unique<Scene>();

		for(int i = 0; i < 2; i++)
		{
			std::shared_ptr<GameObject> go = std::make_unique<GameObject>("Triangle" + std::to_string(i));

			std::shared_ptr<Property> position = std::make_unique<Position>(go);
			go->addProperty(position);
			std::shared_ptr<Position> pos = std::dynamic_pointer_cast<Position>(go->getPropertyByName(POSITION));
			pos->pos.x = i;

			if (i == 0)
			{
				std::shared_ptr<Property> mesh = std::make_unique<Mesh>(go, MESH_SQUARE);
				go->addProperty(mesh);
			}
			else
			{
				std::shared_ptr<Property> mesh = std::make_unique<Mesh>(go, MESH_TRIANGLE);
				go->addProperty(mesh);
			}

			go->setName("Triangle" + std::to_string(i));
			scene->addObject(go);
		}

		std::shared_ptr<GameObject> camera = std::make_unique<OrthographicCamera>();
		scene->addObject(camera);
		EventManager::getInstance().addListener(camera);
	}

	void Application::run()
	{
		this->start();

		while (!glfwWindowShouldClose(app_window.getGLFWWindow()))
		{
			double frame_time = 1.0 / 144.0;
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
				EventManager::getInstance().pollEvent(); // se pun mai multe eventuri intr-un loop decat se da pool si de asta e slow
			}

			double end_time = glfwGetTime();

			Time::delta_time = end_time - start_time;
			if (Time::delta_time < frame_time)
				Time::delta_time = frame_time;
			//std::cout << 1.0f / Time::delta_time << " FPS" << '\n'; 

			EditorUI::update(1.0 / Time::delta_time); 

			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			glfwSwapBuffers(app_window.getGLFWWindow());
			glfwPollEvents();
			EventManager::getInstance().pollEvent();
		}
	}

}
