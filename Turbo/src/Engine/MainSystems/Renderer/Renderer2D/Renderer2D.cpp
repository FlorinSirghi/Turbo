#include "Renderer2D.h"
#include "../../TransformSystem/TransformSystem.h"
#include "../../../../Project/Application.h"
#include "../../../CoreSystems/Time/Time.h"
#include "Engine/MainSystems/Renderer/RenderAPI/OpenGL/GLTexture.h"


namespace Turbo
{
	Matrix4 Renderer2D::tr = Matrix4::identity;

	Vector3D Renderer2D::camera_position = Vector3D::zero;

	std::queue<std::shared_ptr<RenderCommand>> Renderer2D::render_commands_queue{};

	void Renderer2D::draw()
	{
		std::shared_ptr<ITexture> texture = std::make_shared<GLTexture>("C:\\dev\\Turbo\\Turbo\\assets\\tex.png");

		while(!render_commands_queue.empty())
		{
			std::shared_ptr<RenderCommand> command = render_commands_queue.front();
			render_commands_queue.pop();

			command->shader_program->use();
			command->vertex_array->use();
			texture->use();

			tr = Matrix4::identity;

			Vector3D scaled_pos = -camera_position;
			scaled_pos.scale(Time::delta_time);
			scaled_pos.scale(5);

			tr.translate(scaled_pos);
			tr.translate(command->position);

			command->shader_program->setUniformMat4(tr.getTranspose(), "transformation");

			if (command->indexed)
				glDrawElements(command->mode, command->vertex_count, GL_UNSIGNED_INT, 0);
			else
				glDrawArrays(command->mode, 0, command->vertex_count);
		}
	}

}
