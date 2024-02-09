#ifndef SCENEGRAPH_MESH_H_
#define SCENEGRAPH_MESH_H_

#include <memory>

#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/OpenGL/GLTexture.h"
#include "Engine/Renderer/Systems/Renderer3D/MeshType.h"
#include "Engine/Renderer/Systems/Renderer3D/PrimitiveManager3D.h"
#include "Engine/Renderer/Systems/Renderer3D/Renderer3D.h"
#include "Engine/ResourceManager/ResourceManager.h"
#include "Engine/SceneGraph/Components/Transform.h"

namespace Turbo
{
	struct Mesh
	{
	public:

		std::shared_ptr<IShaderProgram> shader_program;

		std::shared_ptr<IVertexArray> vertex_array;

		std::shared_ptr<ITexture> texture;

		MeshType mesh_type; // primitive


		Mesh(MeshType type)
		{
			mesh_type = type;
			PrimitiveManager3D::getPrimitive(shader_program, vertex_array, type);
			texture = ResourceManager::getTexture("wood");
		}

		/*void setType(MeshType type)
		{
			mesh_type = type;
			PrimitiveManager3D::getPrimitive(shader_program, vertex_array, type);
			texture = ResourceManager::getTexture("wood");
		}

		Mesh()
		{}*/
	};
}

#endif // SCENEGRAPH_MESH_H_