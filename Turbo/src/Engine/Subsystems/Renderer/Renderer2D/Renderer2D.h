#pragma once

#include "../RenderAPI/OpenGL/OpenGLApi.h"
#include "../../../Main/Scene/Scene.h"

namespace Turbo
{

	class Renderer2D
	{
	public:

		void drawTriangle();

		static void draw(std::shared_ptr<Scene> scene);
	};

}