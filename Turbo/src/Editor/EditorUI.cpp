#include "EditorUI.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace Turbo
{
	EditorUI::EditorUI(std::shared_ptr<IDManager> id_manager, GLFWwindow* window)
	{
		init(window);
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

	void EditorUI::update(double FPS, std::vector<std::shared_ptr<GameObject>> hierarchy)
	{
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

		int selected = -1;
		for(int i = 0; i < hierarchy.size(); i++)
		{
			if (ImGui::Selectable(hierarchy[i]->getName().c_str(), selected == i))
				selected = i;
		}

		ImGui::End();

		ImGui::SetNextWindowSize({ 360, 1032 });
		ImGui::SetNextWindowPos({ 1560, 0 });
		ImGui::Begin("Inspector", &p_open, flags);

		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void EditorUI::createNewObject()
	{
		
	}


}