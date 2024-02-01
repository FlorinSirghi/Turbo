#ifndef RENDERER_RENDERER2D_H_
#define RENDERER_RENDERER2D_H_

#include <memory>
#include <queue>

#include "Engine/Core/Math/Matrix/Matrix4.h"
#include "Engine/Core/Math/Vector/Vector3D.h"
#include "Engine/Renderer/RenderCommand.h"

namespace Turbo
{
	class Renderer2D
	{
	public:

		static Vector3D camera_position;

		static Matrix4 tr;

		static std::queue<std::shared_ptr<RenderCommand>> render_commands_queue;

		static void draw();
	};

}

#endif // RENDERER_RENDERER2D_H_
