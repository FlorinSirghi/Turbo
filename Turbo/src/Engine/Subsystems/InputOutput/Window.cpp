#include "Window.h"
#include "../../GameObject/OrtographicCamera.h"

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

		EventManager::getInstance().addListener(std::make_unique<OrtographicCamera>());
	}

	void Window::loop()
	{
		while (!glfwWindowShouldClose(window))
		{
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glDrawArrays(GL_TRIANGLES, 0, 3);

			EventManager::getInstance().pollEvent();


			glfwSwapBuffers(window);
			glfwPollEvents();
		}
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

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (action == GLFW_PRESS)
		{
			Event e;

			e.argCount = 1;
			e.event_type = "KEY_PRESSED";
			EventArg<std::string> arg;
			arg.param = "W";

			EventManager::getInstance().postEvent(e);
		}
	}
}
