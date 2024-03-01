#ifndef SCENEGRAPH_PRIMITIVEMANAGER3D_H_
#define SCENEGRAPH_PRIMITIVEMANAGER3D_H_

#include <memory>

#include "MeshType.h"
#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/OpenGL/OpenGLApi.h"
#include "Engine/ResourceManager/ResourceManager.h"

namespace Turbo
{
	class PrimitiveManager3D
	{
	public:

		static void getPrimitive(std::shared_ptr<IShaderProgram>& shader_program, std::shared_ptr<IVertexArray>& vertex_array, MeshType type, const Vector4D color)
		{
			switch (type)
			{
			case MeshType::CUBE:
				createBaseCube(shader_program, vertex_array, color);
				break;
			}
		}

	private:

		static void createBaseCube(std::shared_ptr<IShaderProgram>& shader_program, std::shared_ptr<IVertexArray>& vertex_array, const Vector4D color)
		{
			auto* api = new OpenGLApi();

			shader_program = ResourceManager::getShaderProgram("primitive_shader");

			float vertices[] = {
				// Back face
			   -0.5f, -0.5f, -0.5f,  color.x, color.y, color.z, color.w, 0.0f, 0.0f, // Bottom-left
				0.5f,  0.5f, -0.5f,  color.x, color.y, color.z, color.w, 1.0f, 1.0f, // top-right
				0.5f, -0.5f, -0.5f,  color.x, color.y, color.z, color.w, 1.0f, 0.0f, // bottom-right         
				0.5f,  0.5f, -0.5f,  color.x, color.y, color.z, color.w, 1.0f, 1.0f, // top-right
			   -0.5f, -0.5f, -0.5f,  color.x, color.y, color.z, color.w, 0.0f, 0.0f, // bottom-left
			   -0.5f,  0.5f, -0.5f,  color.x, color.y, color.z, color.w, 0.0f, 1.0f, // top-left
			   // Front face
			   -0.5f, -0.5f,  0.5f,  color.x, color.y, color.z, color.w, 0.0f, 0.0f, // bottom-left
				0.5f, -0.5f,  0.5f,  color.x, color.y, color.z, color.w, 1.0f, 0.0f, // bottom-right
				0.5f,  0.5f,  0.5f,  color.x, color.y, color.z, color.w, 1.0f, 1.0f, // top-right
				0.5f,  0.5f,  0.5f,  color.x, color.y, color.z, color.w, 1.0f, 1.0f, // top-right
			   -0.5f,  0.5f,  0.5f,  color.x, color.y, color.z, color.w, 0.0f, 1.0f, // top-left
			   -0.5f, -0.5f,  0.5f,  color.x, color.y, color.z, color.w, 0.0f, 0.0f, // bottom-left
			   // Left face
			   -0.5f,  0.5f,  0.5f,  color.x, color.y, color.z, color.w, 1.0f, 1.0f, // top-right
			   -0.5f,  0.5f, -0.5f,  color.x, color.y, color.z, color.w, 0.0f, 1.0f, // top-left
			   -0.5f, -0.5f, -0.5f,  color.x, color.y, color.z, color.w, 0.0f, 0.0f, // bottom-left
			   -0.5f, -0.5f, -0.5f,  color.x, color.y, color.z, color.w, 0.0f, 0.0f, // bottom-left
			   -0.5f, -0.5f,  0.5f,  color.x, color.y, color.z, color.w, 1.0f, 0.0f, // bottom-right
			   -0.5f,  0.5f,  0.5f,  color.x, color.y, color.z, color.w, 1.0f, 1.0f, // top-right
			   // Right face
				0.5f,  0.5f,  0.5f,  color.x, color.y, color.z, color.w, 0.0f, 1.0f, // top-left
				0.5f, -0.5f, -0.5f,  color.x, color.y, color.z, color.w, 1.0f, 0.0f, // bottom-right
				0.5f,  0.5f, -0.5f,  color.x, color.y, color.z, color.w, 1.0f, 1.0f, // top-right         
				0.5f, -0.5f, -0.5f,  color.x, color.y, color.z, color.w, 1.0f, 0.0f, // bottom-right
				0.5f,  0.5f,  0.5f,  color.x, color.y, color.z, color.w, 0.0f, 1.0f, // top-left
				0.5f, -0.5f,  0.5f,  color.x, color.y, color.z, color.w, 0.0f, 0.0f, // bottom-left     
				// Bottom face
				-0.5f, -0.5f, -0.5f,  color.x, color.y, color.z, color.w, 1.0f, 1.0f, // top-right
				 0.5f, -0.5f, -0.5f,  color.x, color.y, color.z, color.w, 0.0f, 1.0f, // top-left
				 0.5f, -0.5f,  0.5f,  color.x, color.y, color.z, color.w, 0.0f, 0.0f, // bottom-left
				 0.5f, -0.5f,  0.5f,  color.x, color.y, color.z, color.w, 0.0f, 0.0f, // bottom-left
				-0.5f, -0.5f,  0.5f,  color.x, color.y, color.z, color.w, 1.0f, 0.0f, // bottom-right
				-0.5f, -0.5f, -0.5f,  color.x, color.y, color.z, color.w, 1.0f, 1.0f, // top-right
				// Top face
				-0.5f,  0.5f, -0.5f,  color.x, color.y, color.z, color.w, 0.0f, 1.0f, // top-left
				 0.5f,  0.5f,  0.5f,  color.x, color.y, color.z, color.w, 1.0f, 0.0f, // bottom-right
				 0.5f,  0.5f, -0.5f,  color.x, color.y, color.z, color.w, 1.0f, 1.0f, // top-right     
				 0.5f,  0.5f,  0.5f,  color.x, color.y, color.z, color.w, 1.0f, 0.0f, // bottom-right
				-0.5f,  0.5f, -0.5f,  color.x, color.y, color.z, color.w, 0.0f, 1.0f, // top-left
				-0.5f,  0.5f,  0.5f,  color.x, color.y, color.z, color.w, 0.0f, 0.0f  // bottom-left        
			};

			vertex_array = api->createVertexArray();

			auto vertex_buffer{ api->createVertexBuffer() };
			vertex_buffer->addData(vertices, sizeof(vertices));

			//std::shared_ptr<IElementBuffer> element_buffer = api->createElementBuffer();
			//element_buffer->addData(indices, sizeof(indices));

			vertex_array->addAttribute(0, 3, 9, 0);
			vertex_array->addAttribute(1, 4, 9, 3);
			vertex_array->addAttribute(2, 2, 9, 7);

			shader_program->use();
			vertex_array->use();
		}
	};
}

#endif // SCENEGRAPH_PRIMITIVEMANAGER3D_H_