#include "Renderer3D.h"

#include <queue>

#include "Engine/Core/Math/Matrix/Matrix4.h"
#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/OpenGL/GLElementBuffer.h"

#include "Engine/Core/Math/Matrix/Matrix4.h"
#include "Engine/Core/Math/Vector/Vector3D.h"
#include "Engine/Renderer/Components/Camera.h"
#include "Engine/Renderer/Components/Mesh.h"
#include "Engine/SceneGraph/Components/Transform.h"

namespace Turbo
{
	void Renderer3D::addToQueue(const std::shared_ptr<RenderCommand>& render_command)
	{
		render_commands_queue.push(render_command);
	}

	void Renderer3D::assembleQueue(std::shared_ptr<Scene> scene)
	{
		int meshID = getID<Mesh>();

		for (const auto& go : scene->hierarchy)
		{
			if (go->componentMask[meshID])
			{
				Transform* transform = scene->getComponent<Transform>(go->getID());
				Mesh* mesh = scene->getComponent<Mesh>(go->getID());

				if (go->parent_index != -1)
				{
					RenderCommand::Builder b(mesh->shader_program, mesh->vertex_array, *transform, 36, false, GL_TRIANGLES);

					std::shared_ptr<RenderCommand> command = b.Build();

					render_commands_queue.push(command);
				}
				else
				{
					std::shared_ptr<RenderCommand> command = std::make_shared<RenderCommand>(mesh->shader_program, mesh->vertex_array, transform->position,
						transform->scale, transform->rotation, transform->localPosition, transform->localRotation,
						36, false, false, GL_TRIANGLES);

					render_commands_queue.push(command);
				}
			}
		}
	}

	void Renderer3D::draw(std::shared_ptr<Scene> scene)
	{
		Transform* camera_transform = nullptr;
		Camera* camera_component = nullptr;

		for(auto go : scene->hierarchy)
		{
			camera_component = scene->getComponent<Camera>(go->getID());

			if(camera_component)
			{
				camera_transform = scene->getComponent<Transform>(go->getID());
				break;
			}
		}

		assembleQueue(scene);

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

			int index = command->parent_index;
			if (index != -1)
			{
				Matrix4 childTranslation = Matrix4::translationMatrix(command->position);

				Matrix4 childRotation = Matrix4::rotationMatrix(command->local_rotation);

				Transform* transform = scene->getComponent<Transform>(scene->hierarchy[index]->getID());

				Matrix4 fromChildToParent = Matrix4::translationMatrix(transform->position);

				Vector3D negative = { -transform->position.x, -transform->position.y, -transform->position.z };

				Matrix4 fromParentToChild = Matrix4::translationMatrix(negative);

				model = fromChildToParent * childRotation * fromParentToChild * model;

				// Ce trebuie sa fie aici :

				// In prealabil : matrixHierarchy = fromChildToParent * childRotation * fromParentToChild * matrixHierarchy;
				// model = command->transform->matrixHierarchy * model
			}

			view = Matrix4::lookAtMatrix(camera_transform->position, camera_transform->position + camera_component->direction, camera_component->up);
			//view = Matrix4::lookAtMatrix(pos, pos + dir, up);

			command->shader_program->setUniformMat4(model.getTranspose(), "model");
			command->shader_program->setUniformMat4(view.getTranspose(), "view");
			command->shader_program->setUniformMat4(projection.getTranspose(), "projection");

			if(command->wireframe)
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			else
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

			if (command->indexed)
				glDrawElements(command->mode, command->vertex_count, GL_UNSIGNED_INT, 0);
			else
				glDrawArrays(command->mode, 0, command->vertex_count);

		}
	}
}
