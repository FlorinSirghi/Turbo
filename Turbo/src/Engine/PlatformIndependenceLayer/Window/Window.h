#ifndef ENGINE_PLATFORMINDEPENDENCELAYER_WINDOW_WINDOW_H_
#define ENGINE_PLATFORMINDEPENDENCELAYER_WINDOW_WINDOW_H_

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Engine/Gameplay/EventSystem/EventManager.h"

namespace Turbo {

	class Window
	{
	public:

		Window(std::string ptitle, const int& pwidth, const int& pheight);

		std::string getTitle();
		int getWidth() const;
		int getHeight() const;
		GLFWwindow* getGLFWWindow();

	private:

		GLFWwindow* window;
		std::string title;
		int width, height;
	};

}

#endif // ENGINE_PLATFORMINDEPENDENCELAYER_WINDOW_WINDOW_H_
