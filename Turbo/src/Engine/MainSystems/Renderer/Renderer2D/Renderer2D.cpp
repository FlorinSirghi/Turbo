#include "Renderer2D.h"
#include "../../TransformSystem/TransformSystem.h"
#include "../../../../Project/Application.h"
#include "../../../CoreSystems/Time/Time.h"
#include "Engine/CoreSystems/Math/Trigonometry.h"
#include "Engine/MainSystems/Renderer/RenderAPI/OpenGL/GLTexture.h"


namespace Turbo
{
	Matrix4 Renderer2D::tr = Matrix4::identity;

	Vector3D Renderer2D::camera_position = Vector3D::zero;

	std::queue<std::shared_ptr<RenderCommand>> Renderer2D::render_commands_queue{};

	void Renderer2D::draw()
	{
		while(!render_commands_queue.empty())
		{
			std::shared_ptr<RenderCommand> command = render_commands_queue.front();
			render_commands_queue.pop();

			command->shader_program->use();
			command->vertex_array->use();
			if (command->texture != nullptr)
			{
				command->texture->use();
			}

			Vector3D scaled_pos = -camera_position; // Negating the position is essentially like inversing the view matrix
			scaled_pos.scale(Time::delta_time);
			//scaled_pos.scale(5);

			Matrix4 model = Matrix4::identity;
			Matrix4 view = Matrix4::identity;

			Matrix4 translation = Matrix4::translationMatrix(command->position);
			//translation.translation(command->position);

			Matrix4 rotation = Matrix4::rotationAroundYMatrix(Trigonometry::fromDegreesToRadians(45));

			Matrix4 scale = Matrix4::scaleMatrix(command->scale);
			//scale.scale(command->scale);

			model = translation * rotation * scale;

			view.translate(scaled_pos);

			Matrix4 MVP = view * model;

			command->shader_program->setUniformMat4(MVP.getTranspose(), "transformation"); // transpose because I work in row major, OpenGL works in column major

			if (command->indexed)
				glDrawElements(command->mode, command->vertex_count, GL_UNSIGNED_INT, 0);
			else
				glDrawArrays(command->mode, 0, command->vertex_count);
		}
	}

}
