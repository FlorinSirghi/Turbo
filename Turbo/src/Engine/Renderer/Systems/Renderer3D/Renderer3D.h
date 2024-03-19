#ifndef RENDERER_RENDERER3D_H_
#define RENDERER_RENDERER3D_H_

#include <memory>
#include <queue>

#include "Engine/Core/Math/Matrix/Matrix4.h"
#include "Engine/Core/Math/Vector/Vector3D.h"
#include "Engine/Gameplay/GameObject/Objects/OrthographicCamera.h"
#include "Engine/Renderer/RenderCommand.h"

namespace Turbo
{
	class Renderer3D
	{

	public:

		void addToQueue(const std::shared_ptr<RenderCommand>& render_command);
		void assembleQueue(std::shared_ptr<Scene> scene);

		void draw(std::shared_ptr<Scene>);

	private:

		std::queue<std::shared_ptr<RenderCommand>> render_commands_queue;
	};

}

#endif // RENDERER_RENDERER3D_H_
