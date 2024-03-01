#ifndef SCENEGRAPH_MESH_H_
#define SCENEGRAPH_MESH_H_

#include <memory>

#include "Engine/Renderer/Systems/Renderer3D/MeshType.h"
#include "Engine/Renderer/Systems/Renderer3D/PrimitiveManager3D.h"
#include "Engine/ResourceManager/ResourceManager.h"

namespace Turbo
{
	struct Mesh
	{
		std::shared_ptr<IShaderProgram> shader_program;
		std::shared_ptr<IVertexArray> vertex_array;
		std::shared_ptr<ITexture> texture;

		MeshType mesh_type; // primitive

		explicit Mesh(const MeshType type, Vector4D color = {0.0f, 0.0f, 0.0f, 1.0f})
		{
			mesh_type = type;
			PrimitiveManager3D::getPrimitive(shader_program, vertex_array, type, color);
			texture = ResourceManager::getTexture("wood");
		}
	};
}

#endif // SCENEGRAPH_MESH_H_