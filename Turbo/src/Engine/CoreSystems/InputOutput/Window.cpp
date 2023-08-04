#include "Window.h"
#include "../EventSystem/Event.h"
#include "InputManager.h"

namespace Turbo 
{
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);
	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

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

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Could not initialize GLAD!\n";
		}

		glfwSetKeyCallback(window, keyCallback);
		glfwSetCursorPosCallback(window, cursorPosCallback);
		glfwSetMouseButtonCallback(window, mouseButtonCallback);
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
				InputManager::setKeyHoldDown('W');
				break;
			case GLFW_KEY_A:
				InputManager::setKeyHoldDown('A');
				break;
			case GLFW_KEY_S:
				InputManager::setKeyHoldDown('S');
				break;
			case GLFW_KEY_D:
				InputManager::setKeyHoldDown('D');
				break;
			}
		}

		if (action == GLFW_RELEASE)
		{
			switch (key)
			{
			case GLFW_KEY_W:
				InputManager::releaseKey('W');
				break;
			case GLFW_KEY_A:
				InputManager::releaseKey('A');
				break;
			case GLFW_KEY_S:
				InputManager::releaseKey('S');
				break;
			case GLFW_KEY_D:
				InputManager::releaseKey('D');
				break;
			}
		}
	}

	static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
	{
		InputManager::setMousePositions(xpos, ypos);
	}

	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
		{
			InputManager::setMouseButtonHoldDown('l');
		}
		if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
		{
			InputManager::setMouseButtonHoldDown('r');
		}

		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
		{
			InputManager::releaseMouseButton('l');
		}
		if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
		{
			InputManager::releaseMouseButton('r');
		}
	}
}
