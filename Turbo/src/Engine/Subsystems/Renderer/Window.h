#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Turbo {

	class Window
	{
	public:

		Window(const std::string& ptitle, const int& pwidth, const int& pheight);

		void loop();

		std::string getTitle();
		int getWidth();
		int getHeight();

	private:

		GLFWwindow* window;
		std::string title;
		int width, height;
	};

}