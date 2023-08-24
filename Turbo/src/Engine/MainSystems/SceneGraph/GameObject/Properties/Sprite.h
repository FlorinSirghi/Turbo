#pragma once

#include "SpriteType.h"
#include "Property.h"
#include "PrimitiveManager2D.h"
#include "../../../Renderer/Renderer2D/Renderer2D.h"

#include <memory>

namespace Turbo
{
	class Sprite final : public Property 
	{
	public:

		std::shared_ptr<IShaderProgram> shader_program;

		std::shared_ptr<IVertexArray> vertex_array;

		std::shared_ptr<ITexture> texture;

		SpriteType mesh_type; // primitive

		Sprite(std::shared_ptr<GameObject> go, SpriteType type) : Property(go)
		{
			name = SPRITE;
			mesh_type = type;
			PrimitiveManager2D::getPrimitive(shader_program, vertex_array, type);
			texture = ResourceManager::getTexture("wood");
		}

		void effect() override
		{
			std::shared_ptr<Position> pos = std::dynamic_pointer_cast<Position>(game_object->getPropertyByName(POSITION));
			if (mesh_type == SpriteType::TRIANGLE)
				Renderer2D::render_commands_queue.push(std::make_shared<RenderCommand>(shader_program, vertex_array, texture, pos->pos, 3, false, GL_TRIANGLES));
			if (mesh_type == SpriteType::RECTANGLE)
				Renderer2D::render_commands_queue.push(std::make_shared<RenderCommand>(shader_program, vertex_array, texture, pos->pos, 6, true, GL_TRIANGLES));
			if (mesh_type == SpriteType::LINE)
				Renderer2D::render_commands_queue.push(std::make_shared<RenderCommand>(shader_program, vertex_array, texture, pos->pos, 2, false, GL_LINES));
		}

		virtual ~Sprite() = default;
	};
}