#pragma once

#include "MeshType.h"
#include "Engine/MainSystems/Renderer/RenderAPI/Interfaces/IShaderProgram.h"
#include "Engine/MainSystems/Renderer/RenderAPI/Interfaces/IVertexArray.h"
#include "Engine/MainSystems/Renderer/RenderAPI/OpenGL/OpenGLApi.h"

#include <memory>

#include "Engine/CoreSystems/ResourceManager/ResourceManager.h"

namespace Turbo
{
	class PrimitiveManager3D
	{
	public:

		static void getPrimitive(std::shared_ptr<IShaderProgram>& shader_program, std::shared_ptr<IVertexArray>& vertex_array, MeshType type)
		{
			switch (type)
			{
			case MeshType::CUBE:
				createBaseCube(shader_program, vertex_array);
				break;
			}
		}

	private:

		static void createBaseCube(std::shared_ptr<IShaderProgram>& shader_program, std::shared_ptr<IVertexArray>& vertex_array)
		{
			auto* api = new OpenGLApi();

			shader_program = ResourceManager::getShaderProgram("primitive_shader");

			float vertices[] = {
				// Back face
			   -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, // Bottom-left
				0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top-right
				0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom-right         
				0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top-right
			   -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, // bottom-left
			   -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, // top-left
			   // Front face
			   -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, // bottom-left
				0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom-right
				0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top-right
				0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top-right
			   -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, // top-left
			   -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, // bottom-left
			   // Left face
			   -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, // top-right
			   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, // top-left
			   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom-left
			   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom-left
			   -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, // bottom-right
			   -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, // top-right
			   // Right face
				0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, // top-left
				0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, // bottom-right
				0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, // top-right         
				0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, // bottom-right
				0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, // top-left
				0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, // bottom-left     
				// Bottom face
				-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, // top-right
				 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, // top-left
				 0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom-left
				 0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom-left
				-0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, // bottom-right
				-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, // top-right
				// Top face
				-0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, // top-left
				 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, // bottom-right
				 0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, // top-right     
				 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, // bottom-right
				-0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, // top-left
				-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f  // bottom-left        
			};

			vertex_array = api->createVertexArray();

			std::shared_ptr<IVertexBuffer> vertex_buffer = api->createVertexBuffer();
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
