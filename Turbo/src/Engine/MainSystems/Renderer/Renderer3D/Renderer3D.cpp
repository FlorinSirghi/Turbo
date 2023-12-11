#include "Renderer3D.h"
#include "../../TransformSystem/TransformSystem.h"
#include "../../../../Project/Application.h"
#include "../../../CoreSystems/Time/Time.h"
#include "Engine/CoreSystems/Math/Trigonometry.h"
#include "Engine/MainSystems/Renderer/RenderAPI/OpenGL/GLTexture.h"
#include "Engine/CoreSystems/Math/Matrix/Matrix4.h"


namespace Turbo
{
	Matrix4 Renderer3D::tr = Matrix4::identity;

	Vector3D Renderer3D::camera_position = Vector3D::zero;
	Vector3D Renderer3D::camera_up = Vector3D::zero;
	Vector3D Renderer3D::camera_direction = Vector3D::zero;

	std::queue<std::shared_ptr<RenderCommand>> Renderer3D::render_commands_queue{};

	void Renderer3D::draw()
	{
		while (!render_commands_queue.empty())
		{
			std::shared_ptr<RenderCommand> command = render_commands_queue.front();
			render_commands_queue.pop();

			command->shader_program->use();
			command->vertex_array->use();
			if (command->texture != nullptr)
			{
				command->texture->use();
			}

			float right = 5;
			float left = -5;
			float top = 5;
			float bottom = -5;
			float near = 0.1f;
			float far = 100.0f;


			Matrix4 model = Matrix4::identity;
			Matrix4 view = Matrix4::identity;
			Matrix4 projection = Matrix4::perspectiveProjectionMatrix(90, 4.0f / 3.0f, far, near);
			//Matrix4 projection = Matrix4::perspectiveProjectionMatrix(right, left, top, bottom, far, near);

			Matrix4 translation = Matrix4::translationMatrix(command->position);
			Matrix4 rotation = Matrix4::rotationMatrix(command->rotation);
			Matrix4 scale = Matrix4::scaleMatrix(command->scale);

			model = translation * rotation * scale;

			view = Matrix4::lookAtMatrix(camera_position, camera_position + camera_direction, camera_up);

			command->shader_program->setUniformMat4(model.getTranspose(), "model");
			command->shader_program->setUniformMat4(view.getTranspose(), "view");
			command->shader_program->setUniformMat4(projection.getTranspose(), "projection");

			if (command->indexed)
				glDrawElements(command->mode, command->vertex_count, GL_UNSIGNED_INT, 0);
			else
				glDrawArrays(command->mode, 0, command->vertex_count);
		}
	}

}
