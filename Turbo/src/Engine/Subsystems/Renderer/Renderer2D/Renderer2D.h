#pragma once

#include "../RenderAPI/OpenGL/OpenGLApi.h"
#include "../../../Main/Scene/Scene.h"
#include "../../GameSystem.h"

namespace Turbo
{

	class Renderer2D : public GameSystem
	{
	public:

		static void drawTriangle();

		static void draw();
	};

}