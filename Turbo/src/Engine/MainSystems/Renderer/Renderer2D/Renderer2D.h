#pragma once

#include "../RenderAPI/OpenGL/OpenGLApi.h"
#include "../../GameSystem.h"

namespace Turbo
{

	class Renderer2D : public GameSystem
	{
	public:

		static void createTriangle();

		static void draw();
	};

}