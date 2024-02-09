#include "Application.h"

#include "memory"
#include "chrono"
#include "imgui.h"

#include "Engine/PlatformIndependenceLayer/Time/Time.h"
#include "Engine/HIDEngine/InputOutput/InputSystem.h"
#include "Editor/EditorUI.h"
#include "Editor/imgui_impl_opengl3.h"
#include "Engine/PlatformIndependenceLayer/Platform/Windows.h"
#include "Engine/SceneGraph/Scene/Scene.h"
#include "Engine/Gameplay/EventSystem/EventManager.h"
#include "Engine/Gameplay/GameObject/Objects/OrthographicCamera.h"
#include "Engine/Physics/Components/Colliders/BoxCollider.h"
#include "Engine/Physics/Components/Interaction/RigidBody.h"
#include "Engine/Physics/Systems/CollisionSystem.h"
#include "Engine/Physics/Systems/PhysicsSystem.h"
#include "Engine/Renderer/Components/Camera.h"
#include "Engine/Renderer/Components/Mesh.h"
#include "Engine/Renderer/Systems/Renderer3D/MeshType.h"
#include "Engine/Renderer/Systems/Renderer3D/Renderer3D.h"
#include "Engine/SceneGraph/Components/Transform.h"

namespace Turbo
{
	Application::Application() : app_window("MyApplication", window_width, window_height)
	{
		// Manager initialization need to be moved to delegate constructors
		id_manager	   = std::make_unique<IDManager>();
		renderer3D	   = std::make_unique<Renderer3D>();
		editor_ui	   = std::make_unique<EditorUI>(id_manager, app_window.getGLFWWindow());
		physics_system = std::make_unique<PhysicsSystem>();
		camera_system  = std::make_unique<CameraSystem>();

		scene = std::make_unique<Scene>();

		// De facut pe data urmatoare : coliziuni, sa pot sa lipesc obiecte, editor, materiale

		for (int i = 0; i < 10; i++)
		{
			std::shared_ptr<GameObject> go = std::make_unique<GameObject>(id_manager->generateID(), "Cube" + std::to_string(i));
			scene->addObject(go);

			Vector3D position{ float(rand() % 20 * (rand() % 2 == 1 ? 1 : -1)),
				               float(rand() % 20 * (rand() % 2 == 1 ? 1 : -1)),
				               float(rand() % 20 * (rand() % 2 == 1 ? 1 : -1)) };
			Vector3D scale{ float(rand() % 5 + 1),
							float(rand() % 5 + 1),
							float(rand() % 5 + 1) };

			Vector3D rotation{ float(rand() % 3 + 1),
			                  float(rand() % 3 + 1),
							  float(rand() % 3 + 1) };

			//std::cout << "Componenta transform " << ' ';
			Transform* transform = scene->assignComponent<Transform>(go->getID());
			//std::cout << "Componenta transform " << ' ';
			transform->position = position;
			transform->scale = scale;
			transform->rotation = rotation;

			//std::cout << "Componenta mesh " << ' ';
			scene->assignComponent<Mesh>(go->getID(), MeshType::CUBE);
			//std::cout << "Componenta mesh " << ' ';

			//std::cout << "Componenta boxcollider " << ' ';
			scene->assignComponent<BoxCollider>(go->getID());
			//std::cout << "Componenta rigidbody " << ' ';
			scene->assignComponent<RigidBody>(go->getID());

			/*std::shared_ptr<Component> transform = std::make_unique<Transform>(position, scale, rotation);
			go->addComponent<Transform>();

			std::shared_ptr<Component> mesh = std::make_unique<Mesh>(MeshType::CUBE);
			go->addComponent(mesh);

			std::shared_ptr<Component> collider = std::make_unique<BoxCollider>();
			go->addComponent(collider);

			std::shared_ptr<Component> rigidBody = std::make_unique<RigidBody>();
			go->addComponent(rigidBody);*/

			//go->setName("Triangle" + std::to_string(i));
		}

		std::shared_ptr<GameObject> go = std::make_unique<GameObject>(id_manager->generateID(), "Floor");
		scene->addObject(go);

		Vector3D position{ 0.0f, -20.0f, 0.0f };
		Vector3D scale{ 100.0f, 2.0f, 100.0f };
		Vector3D rotation{ 0.0f, 0.0f, 0.0f };

		//std::cout << "Componenta transform " << ' ';
		scene->assignComponent<Transform>(go->getID());
		//std::cout << "Componenta transform " << ' ';
		Transform* transform = scene->getComponent<Transform>(go->getID());
		transform->position = position;
		transform->scale = scale;
		transform->rotation = rotation;

		//std::cout << "Componenta mesh " << ' ';
		scene->assignComponent<Mesh>(go->getID(), MeshType::CUBE);
		//std::cout << "Componenta mesh " << ' ';

		//std::cout << "Componenta boxcollider " << ' ';
		scene->assignComponent<BoxCollider>(go->getID());
		//std::cout << "Componenta rigidbody " << ' ';
		scene->assignComponent<RigidBody>(go->getID(), false);

		/*std::shared_ptr<Component> transform = std::make_unique<Transform>(position, scale, rotation);
		go->addComponent(transform);

		std::shared_ptr<Component> collider = std::make_unique<BoxCollider>();
		go->addComponent(collider);

		std::shared_ptr<Component> mesh = std::make_shared<Mesh>(MeshType::CUBE);
		go->addComponent(mesh);

		std::shared_ptr<Component> rigidBody = std::make_unique<RigidBody>(false);
		go->addComponent(rigidBody);*/


		std::shared_ptr<GameObject> camera = std::make_unique<GameObject>(id_manager->generateID(), "Camera");
		scene->addObject(camera);
		//std::cout << "Componenta transform " << ' ';
		Transform* trans = scene->assignComponent<Transform>(camera->getID());
		trans->position = { -42.0f, -10.0f, -6.0f };
		//std::cout << "Componenta camera " << ' ';
		scene->assignComponent<Camera>(camera->getID());
		EventManager::getInstance().addListener(camera);

		//printWorkArea();
	}

	void Application::run()
	{
		this->start();

		float mouse_xpos = InputSystem::getMouseXPos();
		float mouse_ypos = InputSystem::getMouseYPos();

		while (!glfwWindowShouldClose(app_window.getGLFWWindow()))
		{
			double frame_time = 1.0 / 144.0;
			double start_time = glfwGetTime();

			glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			std::queue<std::shared_ptr<RenderCommand>> commands_queue{};

			camera_system->processCameras(scene);
			//physics_system->update(scene);

			for(const auto& go : scene->hierarchy)
			{
				//std::cout << "Vreau sa iau transform" << ' ';
				Transform* transform = scene->getComponent<Transform>(go->getID());
				//std::cout << "Vreau sa iau mesh" << ' ';
				Mesh* mesh = scene->getComponent<Mesh>(go->getID());
				//std::cout << "Vreau sa iau boxcollider" << ' ';
				BoxCollider* boxcollider = scene->getComponent<BoxCollider>(go->getID());

				//std::cout << go->getName() << '\n';

				if (transform != nullptr && mesh != nullptr && boxcollider != nullptr)
				{

					Vector3D minExtents = transform->position - transform->scale.scaled(0.5f);
					Vector3D maxExtents = transform->position + transform->scale.scaled(0.5f);

					Vector3D center = (minExtents + maxExtents).scaled(0.5f);
					boxcollider->center = center;
					boxcollider->rx = transform->scale.x / 2.0f;
					boxcollider->ry = transform->scale.y / 2.0f;
					boxcollider->rz = transform->scale.z / 2.0f;

					if (mesh->mesh_type == MeshType::CUBE)
						commands_queue.push(std::make_shared<RenderCommand>(mesh->shader_program, mesh->vertex_array, transform->position,
							transform->scale, transform->rotation, 36, false, GL_TRIANGLES));
				}
			}


			/*for (const auto& go : scene->hierarchy)
			{
				go->update();
			}*/

			//PhysicsSystem::checkIfObjectClicked(mouse_xpos, mouse_ypos, scene->hierarchy);

			//Renderer2D::draw();
			renderer3D->draw(commands_queue, scene);

			//for (char c : InputSystem::getAllHeldDown())
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

			/*if (InputSystem::isMouseButtonHoldDown('l') && mouse_xpos > 260 && mouse_xpos < 1560 && mouse_ypos > 100)
			{
				Event e;

				e.argCount = 2;
				e.type = MOUSE_MOVEMENT;
				EventArg<std::string> arg;
				arg.param = std::to_string(InputSystem::getMouseXPos() - mouse_xpos);

				EventArg<std::string> arg2;
				arg2.param = std::to_string(InputSystem::getMouseYPos() - mouse_ypos);

				e.args.emplace_back(arg);
				e.args.emplace_back(arg2);

				EventManager::getInstance().postEvent(e);
				EventManager::getInstance().pollEvent();
			}*/

			double end_time = glfwGetTime();

			Time::delta_time = end_time - start_time;
			if (Time::delta_time < frame_time)
				Time::delta_time = frame_time;
			//std::cout << 1.0f / Time::delta_time << " FPS" << '\n'; 

			editor_ui->update(1.0 / Time::delta_time, scene->hierarchy);

			glfwSwapBuffers(app_window.getGLFWWindow());
			glfwPollEvents();

			mouse_xpos = InputSystem::getMouseXPos();
			mouse_ypos = InputSystem::getMouseYPos();

			EventManager::getInstance().pollEvent();
		}
	}

}
