#include "Window.h"

namespace Turbo {

	Window::Window(const std::string& ptitle, const int& pwidth, const int& pheight) : title(ptitle), width(pwidth), height(pheight) 
	{
		if (!glfwInit())
		{
			std::cout << "Could not initialize GLFW!\n";
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(width, height, "MyApplication", NULL, NULL);
		if (!window)
		{
			std::cout << "Could not create window!\n";
		}

		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Could not initialize GLAD!\n";
		}
	}

	void Window::loop()
	{
		while (!glfwWindowShouldClose(window))
		{

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

	std::string Window::getTitle()
	{
		return title;
	}

	int Window::getHeight()
	{
		return height;
	}

	int Window::getWidth()
	{
		return width;
	}
}
