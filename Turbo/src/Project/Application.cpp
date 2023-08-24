#include "Application.h"
#include "../Engine/MainSystems/Renderer/Renderer2D/Renderer2D.h"
#include "memory"
#include "chrono"
#include "imgui.h"
#include "../Engine/CoreSystems/Time/Time.h"
#include "../Engine/CoreSystems/InputOutput/InputManager.h"
#include "Editor/EditorUI.h"
#include "Editor/imgui_impl_opengl3.h"
#include "Engine/CoreSystems/Platform/Windows.h"
#include "Engine/MainSystems/Physics/PhysicsSystem.h"
#include "Engine/MainSystems/SceneGraph/GameObject/Properties/Camera.h"
#include "Engine/MainSystems/SceneGraph/GameObject/Properties/Sprite.h"
#include "Engine/MainSystems/SceneGraph/GameObject/UtilityObjects/OrthographicCamera.h"

namespace Turbo
{
	Application::Application() : app_window("MyApplication", 1920, 1032)
	{
		EditorUI::start(app_window.getGLFWWindow());

		scene = std::make_unique<Scene>();

		for(int i = 0; i < 10; i++)
		{
			std::shared_ptr<GameObject> go = std::make_unique<GameObject>("Triangle" + std::to_string(i));

			std::shared_ptr<Property> position = std::make_unique<Position>(go);
			go->addProperty(position);
			std::shared_ptr<Position> pos = std::dynamic_pointer_cast<Position>(go->getPropertyByName(POSITION));
			pos->pos.x = i;

			if (i % 2 == 0)
			{
				std::shared_ptr<Property> mesh = std::make_unique<Sprite>(go, SpriteType::RECTANGLE);
				go->addProperty(mesh);
			}
			if(i == 1)
			{
				std::shared_ptr<Property> mesh = std::make_unique<Sprite>(go, SpriteType::TRIANGLE);
				go->addProperty(mesh);
			}
			if(i == 2)
			{
				std::shared_ptr<Property> mesh = std::make_unique<Sprite>(go, SpriteType::LINE);
				go->addProperty(mesh);
			}

			go->setName("Triangle" + std::to_string(i));
			scene->addObject(go);
		}

		std::shared_ptr<GameObject> camera = std::make_unique<OrthographicCamera>();
		scene->addObject(camera);
		EventManager::getInstance().addListener(camera);

		printWorkArea();
	}

	void Application::run()
	{
		this->start();

		float mouse_xpos = InputManager::getMouseXPos();
		float mouse_ypos = InputManager::getMouseYPos();

		while (!glfwWindowShouldClose(app_window.getGLFWWindow()))
		{
			double frame_time = 1.0 / 144.0;
			double start_time = glfwGetTime();

			glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			for (const auto& go : scene->hierarchy)
			{
				go->update();
			}

			PhysicsSystem::checkIfObjectClicked(mouse_xpos, mouse_ypos, scene->hierarchy);

			Renderer2D::draw();

			//for (char c : InputManager::getAllHeldDown())
			//{
			//	Event e;

			//	e.argCount = 1;
			//	e.type = KEY_PRESS;
			//	EventArg<std::string> arg;

			//	arg.param = c;

			//	e.args.emplace_back(arg); 

			//	EventManager::getInstance().postEvent(e);
			//	EventManager::getInstance().pollEvent(); // se pun mai multe eventuri intr-un loop decat se da pool si de asta e slow
			//}

			//std::cout << mouse_xpos << ' ' << mouse_ypos << '\n';

			if(InputManager::isMouseButtonHoldDown('l') && mouse_xpos > 260 && mouse_xpos < 1560 && mouse_ypos > 100)
			{
				Event e;

				e.argCount = 2;
				e.type = MOUSE_MOVEMENT;
				EventArg<std::string> arg;
				arg.param = std::to_string(InputManager::getMouseXPos() - mouse_xpos);

				EventArg<std::string> arg2;
				arg2.param = std::to_string(InputManager::getMouseYPos() - mouse_ypos);

				e.args.emplace_back(arg);
				e.args.emplace_back(arg2);

				EventManager::getInstance().postEvent(e);
				EventManager::getInstance().pollEvent();
			}

			mouse_xpos = InputManager::getMouseXPos();
			mouse_ypos = InputManager::getMouseYPos();

			double end_time = glfwGetTime();

			Time::delta_time = end_time - start_time;
			if (Time::delta_time < frame_time)
				Time::delta_time = frame_time;
			//std::cout << 1.0f / Time::delta_time << " FPS" << '\n'; 

			EditorUI::update(1.0 / Time::delta_time); 

			glfwSwapBuffers(app_window.getGLFWWindow());
			glfwPollEvents();
			EventManager::getInstance().pollEvent();
		}
	}

}
