#include "Window.h"
#include "../EventSystem/Event.h"
#include "InputManager.h"

namespace Turbo 
{
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

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

		glfwSetKeyCallback(window, key_callback);
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

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (action == GLFW_PRESS)
		{
			/*Event e;

			e.argCount = 1;
			e.type = KEY_PRESS;
			EventArg<std::string> arg;*/
			switch (key)
			{
			case GLFW_KEY_W:
				InputManager::setKeyHoldDown('W');
				//arg.param = "W";
				break;
			case GLFW_KEY_A:
				InputManager::setKeyHoldDown('A');
				//arg.param = "A";
				break;
			case GLFW_KEY_S:
				InputManager::setKeyHoldDown('S');
				//arg.param = "S";
				break;
			case GLFW_KEY_D:
				InputManager::setKeyHoldDown('D');
				//arg.param = "D";
				break;
			}
			//e.args.emplace_back(arg);

			//EventManager::getInstance().postEvent(e);
		}

		if (action == GLFW_RELEASE)
		{
			/*Event e;

			e.argCount = 1;
			e.type = KEY_PRESS;
			EventArg<std::string> arg;*/
			switch (key)
			{
			case GLFW_KEY_W:
				InputManager::releaseKey('W');
				//arg.param = "W";
				break;
			case GLFW_KEY_A:
				InputManager::releaseKey('A');
				//arg.param = "A";
				break;
			case GLFW_KEY_S:
				InputManager::releaseKey('S');
				//arg.param = "S";
				break;
			case GLFW_KEY_D:
				InputManager::releaseKey('D');
				//arg.param = "D";
				break;
			}
			//e.args.emplace_back(arg);

			//EventManager::getInstance().postEvent(e);
		}
	}
}
