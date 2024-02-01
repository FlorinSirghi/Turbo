#ifndef SCENEGRAPH_SPRITE_H_
#define SCENEGRAPH_SPRITE_H_

#include <memory>

#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/Interfaces/IShaderProgram.h"
#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/Interfaces/ITexture.h"
#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/Interfaces/IVertexArray.h"
#include "Engine/Renderer/Systems/Renderer2D/PrimitiveManager2D.h"
#include "Engine/Renderer/Systems/Renderer2D/Renderer2D.h"
#include "Engine/Renderer/Systems/Renderer2D/SpriteType.h"
#include "Engine/SceneGraph/Components/Transform.h"

namespace Turbo
{
	class Sprite final : public Component
	{
	public:

		std::shared_ptr<IShaderProgram> shader_program;

		std::shared_ptr<IVertexArray> vertex_array;

		std::shared_ptr<ITexture> texture;

		SpriteType mesh_type; // primitive

		Sprite(SpriteType type) : Component()
		{
			name = SPRITE;
			mesh_type = type;
			PrimitiveManager2D::getPrimitive(shader_program, vertex_array, type);
			texture = ResourceManager::getTexture("wood");
		}

		void update() override
		{
			/*std::shared_ptr<Transform> transform = std::dynamic_pointer_cast<Transform>(game_object->getComponentByName(TRANSFORM));

			if (mesh_type == SpriteType::TRIANGLE)
				Renderer2D::render_commands_queue.push(std::make_shared<RenderCommand>(shader_program, vertex_array, transform->position, transform->scale, 3, false, GL_TRIANGLES));
			if (mesh_type == SpriteType::RECTANGLE)
				Renderer2D::render_commands_queue.push(std::make_shared<RenderCommand>(shader_program, vertex_array, transform->position, transform->scale, 6, true, GL_TRIANGLES));
			if (mesh_type == SpriteType::LINE)
				Renderer2D::render_commands_queue.push(std::make_shared<RenderCommand>(shader_program, vertex_array, transform->position, transform->scale, 2, false, GL_LINES));*/
		}

		virtual ~Sprite() = default;
	};
}

#endif // SCENEGRAPH_SPRITE_H_