#include "Window.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Engine/Gameplay/EventSystem/Event.h"
#include "Engine/Gameplay/EventSystem/EventManager.h"
#include "Engine/HIDEngine/InputOutput/InputSystem.h"

namespace Turbo 
{
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);
	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void framebufferSizeCallback(GLFWwindow* window, int width, int height);

	Window::Window(std::string ptitle, const int& pwidth, const int& pheight) : title(std::move(ptitle)), width(pwidth), height(pheight) 
	{
		if (!glfwInit())
		{
			std::cout << "Could not initialize GLFW!\n";
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

		if (!window)
		{
			std::cout << "Could not create window!\n";
		}

		glfwMakeContextCurrent(window);
		glfwMaximizeWindow(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Could not initialize GLAD!\n";
		}

		glEnable(GL_DEPTH_TEST);
		//glEnable(GL_CULL_FACE);
		//glCullFace(GL_BACK);
		glfwSetKeyCallback(window, keyCallback);
		glfwSetCursorPosCallback(window, cursorPosCallback);
		glfwSetMouseButtonCallback(window, mouseButtonCallback);
		//glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glViewport(260, 0.0f, 1300, 900); // y-ul e pozitiv in jos
	}

	std::string Window::getTitle()
	{
		return title;
	}

	int Window::getHeight() const
	{
		return height;
	}

	int Window::getWidth() const
	{
		return width;
	}

	GLFWwindow* Window::getGLFWWindow()
	{
		return window;
	}

	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (action == GLFW_PRESS)
		{
			switch (key)
			{
			case GLFW_KEY_W:
				InputSystem::setKeyHoldDown('W');
				break;
			case GLFW_KEY_A:
				InputSystem::setKeyHoldDown('A');
				break;
			case GLFW_KEY_S:
				InputSystem::setKeyHoldDown('S');
				break;
			case GLFW_KEY_D:
				InputSystem::setKeyHoldDown('D');
				break;
			}
		}

		if (action == GLFW_RELEASE)
		{
			switch (key)
			{
			case GLFW_KEY_W:
				InputSystem::releaseKey('W');
				break;
			case GLFW_KEY_A:
				InputSystem::releaseKey('A');
				break;
			case GLFW_KEY_S:
				InputSystem::releaseKey('S');
				break;
			case GLFW_KEY_D:
				InputSystem::releaseKey('D');
				break;
			}
		}
	}

	static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
	{
		InputSystem::setMousePositions(xpos, ypos);
	}

	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
		{
			InputSystem::setMouseButtonHoldDown('l');
		}
		if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
		{
			InputSystem::setMouseButtonHoldDown('r');
		}

		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
		{
			InputSystem::releaseMouseButton('l');
		}
		if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
		{
			InputSystem::releaseMouseButton('r');
		}
	}

}
