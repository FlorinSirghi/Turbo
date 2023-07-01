#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../EventSystem/EventManager.h";

#include <iostream>

namespace Turbo {

	class Window
	{
	public:

		Window(std::string ptitle, const int& pwidth, const int& pheight);

		void loop();

		std::string getTitle();
		int getWidth() const;
		int getHeight() const;

	private:

		GLFWwindow* window;
		std::string title;
		int width, height;
	};

}