#include "EditorUI.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "Engine/Core/IDs/IDManager.h"
#include "Engine/PlatformIndependenceLayer/Window/Window.h"
#include "Engine/SceneGraph/Scene/Scene.h"
#include "Engine/Gameplay/EditorActions/ObjectCreator.h"
#include "Engine/Physics/Components/Colliders/BoxCollider.h"
#include "Engine/SceneGraph/Components/Transform.h"

namespace Turbo
{
	EditorUI::EditorUI(std::shared_ptr<IDManager> id_manager, GLFWwindow* window, std::shared_ptr<Scene>& scene)
	{
		this->scene = scene;
		object_creator = std::make_shared<ObjectCreator>(id_manager);
		init(window);
		selected = -1;
	}

	void EditorUI::init(GLFWwindow* window)
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		(void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		//io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		//io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

		ImGui::StyleColorsDark();

		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 330");

		// Rendering scene view

		// Grid
	}

	void EditorUI::update(double FPS, std::shared_ptr<Scene>& s)
	{
		this->scene = s;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		static float f = 0.0f;
		static int counter = 0;

		//ImGui::ShowDemoWindow();

		//ImGuiDockNodeFlags flags = ImGuiDockNodeFlags_PassthruCentralNode;
		//ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), flags);

		ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize;
		flags |= ImGuiWindowFlags_NoCollapse;
		flags |= ImGuiWindowFlags_NoMove;

		bool p_open = true;

		ImGui::SetNextWindowSize({1300, 100});
		ImGui::SetNextWindowPos({ 260, 0 });
		ImGui::Begin("Stats", &p_open, flags);

		ImGui::Text("FPS: %f", FPS);               
		
		ImGui::End();


		ImGui::SetNextWindowSize({ 260, 1032 });
		ImGui::SetNextWindowPos({ 0, 0 });
		ImGui::Begin("Hierarchy", &p_open, flags);

		if (ImGui::BeginPopupContextWindow())
		{
			if (ImGui::Selectable("New Object"))
				createNewObject();
			
			ImGui::EndPopup();
		}

		static ImGuiTreeNodeFlags base_tree_node_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;

		for(int i = 0; i < this->scene->hierarchy.size(); i++)
		{
			if (this->scene->hierarchy[i]->parent_index == -1)
			{
				ImGuiTreeNodeFlags tree_node_flags = base_tree_node_flags;

				if (selected == i)
					tree_node_flags |= ImGuiTreeNodeFlags_Selected;

				//const bool is_node_open = ImGui::TreeNodeEx((void*)(intptr_t)i, tree_node_flags, this->scene->hierarchy[i]->getName().c_str());
				const bool is_node_open = ImGui::TreeNodeEx(reinterpret_cast<void*>(static_cast<intptr_t>(i)), tree_node_flags, this->scene->hierarchy[i]->getName().c_str());

				if (ImGui::IsItemClicked() && !ImGui::IsItemToggledOpen())
					selected = i;

				if (ImGui::BeginDragDropSource())
				{
					ImGui::SetDragDropPayload("_TREENODE", this->scene->hierarchy[i].get(), sizeof(GameObject));
					ImGui::Text("This is a drag and drop source");
					ImGui::EndDragDropSource();
				}
				if (ImGui::BeginDragDropTarget())
				{
					if (const auto obj = ImGui::AcceptDragDropPayload("_TREENODE"); obj != nullptr)
					{
						auto* child = static_cast<GameObject*>(obj->Data);

						this->scene->linkGameObjects(this->scene->hierarchy[i], child);
					}
					ImGui::EndDragDropTarget();
				}

				if (is_node_open)
				{
					for (const auto c_index : this->scene->hierarchy[i]->children_index)
					{
						ImGui::Text("%s", this->scene->hierarchy[c_index]->name.c_str());
						//ImGui::TreePop();
					}
					ImGui::TreePop();
				}
			}
		}

		ImGui::End();

		ImGui::SetNextWindowSize({ 360, 1032 });
		ImGui::SetNextWindowPos({ 1560, 0 });
		ImGui::Begin("Inspector", &p_open, flags);

		if (selected != -1)
		{
			auto* transform = this->scene->getComponent<Transform>(this->scene->hierarchy[selected]->getID());
			auto* box_collider = this->scene->getComponent<BoxCollider>(this->scene->hierarchy[selected]->getID());

			const Transform transform_copy = *transform;
			ImGui::Text("Transform\n");

			ImGui::Text("Position");
			ImGui::DragFloat("Xp", &transform->position.x, 0.1f, -1000.0f, 1000.0f,"%.2f");
			ImGui::DragFloat("Yp", &transform->position.y, 0.1f, -1000.0f, 1000.0f,"%.2f");
			ImGui::DragFloat("Zp", &transform->position.z, 0.1f, -1000.0f, 1000.0f,"%.2f");

			ImGui::Text("Rotation\n");
			ImGui::DragFloat("Xr", &transform->rotation.x, 0.1f, -1000.0f, 1000.0f, "%.2f");
			ImGui::DragFloat("Yr", &transform->rotation.y, 0.1f, -1000.0f, 1000.0f, "%.2f");
			ImGui::DragFloat("Zr", &transform->rotation.z, 0.1f, -1000.0f, 1000.0f, "%.2f");

			ImGui::Text("Scale\n");
			ImGui::DragFloat("Xs", &transform->scale.x, 0.1f, -1000.0f, 1000.0f, "%.2f");
			ImGui::DragFloat("Ys", &transform->scale.y, 0.1f, -1000.0f, 1000.0f, "%.2f");
			ImGui::DragFloat("Zs", &transform->scale.z, 0.1f, -1000.0f, 1000.0f, "%.2f");

			box_collider->originalRadius += (transform->scale - transform_copy.scale).scaled(0.5f);
			box_collider->radius		 += (transform->scale - transform_copy.scale).scaled(0.5f);

			for(const auto c_index : this->scene->hierarchy[selected]->children_index)
			{
				auto* c_transform = this->scene->getComponent<Transform>(this->scene->hierarchy[c_index]->getID());
				c_transform->localPosition += transform->position - transform_copy.position;
				c_transform->localRotation += transform->rotation - transform_copy.rotation;
				c_transform->scale	  += transform->scale    - transform_copy.scale;

				auto* c_bc = this->scene->getComponent<BoxCollider>(this->scene->hierarchy[c_index]->getID());
				c_bc->radius		 += (transform->scale - transform_copy.scale).scaled(0.5f);
				c_bc->originalRadius += (transform->scale - transform_copy.scale).scaled(0.5f);
			}
		}

		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void EditorUI::createNewObject()
	{
		object_creator->createCube(this->scene);
	}


}
