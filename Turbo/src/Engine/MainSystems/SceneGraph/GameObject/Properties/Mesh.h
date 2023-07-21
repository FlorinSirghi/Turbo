#pragma once

#include "MeshType.h"
#include "Property.h"
#include "MeshManager.h"
#include "../../../Renderer/Renderer2D/Renderer2D.h"

#include <memory>

namespace Turbo
{
	class Mesh final : public Property 
	{
	public:

		std::shared_ptr<IShaderProgram> shader_program;

		std::shared_ptr<IVertexArray> vertex_array;

		MeshType mesh_type;

		Mesh(std::shared_ptr<GameObject> go, MeshType type) : Property(go)
		{
			name = MESH;
			mesh_type = type;
			MeshManager::getMesh(shader_program, vertex_array, type);
		}

		void effect() override
		{
			std::shared_ptr<Position> pos = std::dynamic_pointer_cast<Position>(game_object->getPropertyByName(POSITION));
			if (mesh_type == MeshType::TRIANGLE)
				Renderer2D::render_commands_queue.push(std::make_shared<RenderCommand>(shader_program, vertex_array, pos->pos, 3, false, GL_TRIANGLES));
			if (mesh_type == MeshType::RECTANGLE)
				Renderer2D::render_commands_queue.push(std::make_shared<RenderCommand>(shader_program, vertex_array, pos->pos, 6, true, GL_TRIANGLES));
			if (mesh_type == MeshType::LINE)
				Renderer2D::render_commands_queue.push(std::make_shared<RenderCommand>(shader_program, vertex_array, pos->pos, 2, false, GL_LINES));
		}

		virtual ~Mesh() = default;
	};
}