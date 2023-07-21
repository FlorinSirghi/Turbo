#pragma once

#include "../RenderAPI/OpenGL/OpenGLApi.h"
#include "../../GameSystem.h"
#include "../RenderCommand.h"

#include <queue>

namespace Turbo
{
	class Renderer2D : public GameSystem
	{
	public:

		static Vector3D camera_position;

		static Matrix4 tr;

		static std::queue<std::shared_ptr<RenderCommand>> render_commands_queue;

		static void draw();
	};

}
