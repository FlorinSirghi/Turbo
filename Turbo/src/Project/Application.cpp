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
		id_manager	   = std::make_shared<IDManager>();
		renderer3D	   = std::make_shared<Renderer3D>();
		editor_ui	   = std::make_shared<EditorUI>(id_manager, app_window.getGLFWWindow());
		physics_system = std::make_shared<PhysicsSystem>();
		camera_system  = std::make_shared<CameraSystem>();
		debug_system   = std::make_shared<DebugSystem>(renderer3D);

		scene = std::make_unique<Scene>();

		// De facut pe data urmatoare : coliziuni, sa pot sa lipesc obiecte, editor, materiale

		for (int i = 0; i < 10; i++)
		{
			std::shared_ptr<GameObject> go = std::make_unique<GameObject>(id_manager->generateID(), "Cube" + std::to_string(i));
			scene->addObject(go);

			Vector3D position{ float(rand() % 20 * (rand() % 2 == 1 ? 1 : -1)),
				               float(rand() % 20 * (rand() % 2 == 1 ? 1 : -1)),
				               float(rand() % 20 * (rand() % 2 == 1 ? 1 : -1)) };
			Vector3D scale{ float(rand() % 10 + 1),
							float(rand() % 10 + 1),
							float(rand() % 10 + 1) };

			Vector3D rotation{ 45.0f, .0f, .0f };
	/*		Vector3D position{0.0f, 0.0f, 0.0f};
			Vector3D scale{ 1.0f, 1.0f, 1.0f };*/


			//Vector3D rotation{ 0.0f, 0.0f, 0.0f };

			Transform* transform = scene->assignComponent<Transform>(go->getID());
			transform->position = position;
			transform->scale = scale;
			transform->rotation = rotation;

			scene->assignComponent<Mesh>(go->getID(), MeshType::CUBE);
			auto bc = scene->assignComponent<BoxCollider>(go->getID());
			/*bc->center = position;
			bc->originalCenter = position;*/
			bc->radius = { scale.x / 2.0f, scale.y / 2.0f, scale.z / 2.0f };
			bc->originalRadius = bc->radius;
			scene->assignComponent<RigidBody>(go->getID());
		}

		std::shared_ptr<GameObject> go = std::make_unique<GameObject>(id_manager->generateID(), "Floor");
		scene->addObject(go);

		Vector3D position{ 0.0f, -20.0f, 0.0f };
		Vector3D scale{ 100.0f, 2.0f, 100.0f };
		Vector3D rotation{ 0.0f, 0.0f, 0.0f };

		scene->assignComponent<Transform>(go->getID());
		Transform* transform = scene->getComponent<Transform>(go->getID());
		transform->position = position;
		transform->scale = scale;
		transform->rotation = rotation;

		scene->assignComponent<Mesh>(go->getID(), MeshType::CUBE);
		auto bc = scene->assignComponent<BoxCollider>(go->getID());
		/*bc->center = position;
		bc->originalCenter = position;*/
		bc->radius = { scale.x / 2.0f, scale.y / 2.0f, scale.z / 2.0f };
		bc->originalRadius = bc->radius;
		scene->assignComponent<RigidBody>(go->getID(), false);

		auto camera = std::make_shared<GameObject>(id_manager->generateID(), "Camera");
		scene->addObject(camera);
		Transform* trans = scene->assignComponent<Transform>(camera->getID());
		trans->position = { -42.0f, 0.0f, -6.0f };
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

			debug_system->viewColliders(scene);

			camera_system->processCameras(scene);
			physics_system->update(scene);

			//for(const auto& go : scene->hierarchy)
			//{
			//	Transform* transform = scene->getComponent<Transform>(go->getID());
			//	Mesh* mesh = scene->getComponent<Mesh>(go->getID());
			//	BoxCollider* boxcollider = scene->getComponent<BoxCollider>(go->getID());

			//	if (transform != nullptr && mesh != nullptr && boxcollider != nullptr)
			//	{
			//		if (mesh->mesh_type == MeshType::CUBE)
			//			commands_queue.push(std::make_shared<RenderCommand>(mesh->shader_program, mesh->vertex_array, transform->position,
			//				transform->scale, transform->rotation, 36, false, GL_TRIANGLES));

			//		/*commands_queue.push(std::make_shared<RenderCommand>(boxcollider->visualRepresentation->shader_program, 
			//			boxcollider->visualRepresentation->vertex_array, transform->position,
			//			transform->scale, transform->rotation, 36, false, GL_TRIANGLES));*/
			//	}
			//}

			renderer3D->draw(scene);

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
