#pragma once

#include "MeshType.h"
#include "Property.h"
#include "PrimitiveManager3D.h"
#include "../../../Renderer/Renderer3D/Renderer3D.h"

#include <memory>

#include "MeshType.h"
#include "Position.h"
#include "Rotation.h"
#include "Scale.h"

namespace Turbo
{
	class Mesh final : public Property
	{
	public:

		std::shared_ptr<IShaderProgram> shader_program;

		std::shared_ptr<IVertexArray> vertex_array;

		std::shared_ptr<ITexture> texture;

		MeshType mesh_type; // primitive

		Mesh(std::shared_ptr<GameObject> go, MeshType type) : Property(go)
		{
			name = SPRITE;
			mesh_type = type;
			PrimitiveManager3D::getPrimitive(shader_program, vertex_array, type);
			texture = ResourceManager::getTexture("wood");
		}

		void effect() override
		{
			std::shared_ptr<Position> pos = std::dynamic_pointer_cast<Position>(game_object->getPropertyByName(POSITION));
			std::shared_ptr<Scale> scl = std::dynamic_pointer_cast<Scale>(game_object->getPropertyByName(SCALE));
			std::shared_ptr<Rotation> rot = std::dynamic_pointer_cast<Rotation>(game_object->getPropertyByName(ROTATION));
			if (mesh_type == MeshType::CUBE)
				Renderer3D::render_commands_queue.push(std::make_shared<RenderCommand>(shader_program, vertex_array, pos->pos, scl->scale, rot->rotation, 36, false, GL_TRIANGLES));
		}

		virtual ~Mesh() = default;
	};
}
