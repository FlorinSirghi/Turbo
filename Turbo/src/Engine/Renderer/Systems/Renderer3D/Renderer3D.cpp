#include "Renderer3D.h"

#include "Engine/Core/Math/Matrix/Matrix4.h"
#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/OpenGL/GLElementBuffer.h"

#include <queue>

#include "Engine/Core/Math/Matrix/Matrix4.h"
#include "Engine/Core/Math/Vector/Vector3D.h"
#include "Engine/Renderer/Components/Camera.h"
#include "Engine/SceneGraph/Components/Transform.h"

namespace Turbo
{
	void Renderer3D::draw(std::queue<std::shared_ptr<RenderCommand>> commands_queue, std::shared_ptr<Scene> scene)
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

		//std::cout << camera_transform->position.x << ' ' << camera_transform->position.y << ' ' << camera_transform->position.z << '\n';

		/*Vector3D pos{ 0.0f, 0.0f, -3.0f };
		Vector3D dir{ 0.0f, 0.0f, 1.0f };
		Vector3D up{ 0.0f, 1.0f, 0.0f };*/

		while (!commands_queue.empty())
		{
			//std::cout << "rendering\n";
			std::shared_ptr<RenderCommand> command = commands_queue.front();
			commands_queue.pop();

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

			view = Matrix4::lookAtMatrix(camera_transform->position, camera_transform->position + camera_component->direction, camera_component->up);
			//view = Matrix4::lookAtMatrix(pos, pos + dir, up);

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
