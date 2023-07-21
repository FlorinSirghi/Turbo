#pragma once

#include "MeshType.h"
#include "Engine/MainSystems/Renderer/RenderAPI/Interfaces/IShaderProgram.h"
#include "Engine/MainSystems/Renderer/RenderAPI/Interfaces/IVertexArray.h"
#include "Engine/MainSystems/Renderer/RenderAPI/OpenGL/OpenGLApi.h"

#include <memory>

namespace Turbo
{
	class MeshManager
	{
	public:

		static void getMesh(std::shared_ptr<IShaderProgram>& shader_program, std::shared_ptr<IVertexArray>& vertex_array ,MeshType type)
		{
			switch (type)
			{
			case MeshType::TRIANGLE:
				createBaseTriangle(shader_program, vertex_array);
				break;
			case MeshType::RECTANGLE:
				createBaseRectangle(shader_program, vertex_array);
				break;
			case MeshType::LINE:
				createBaseLine(shader_program, vertex_array);
				break;
			}
		}

	private:

		static void createBaseTriangle(std::shared_ptr<IShaderProgram>& shader_program, std::shared_ptr<IVertexArray>& vertex_array)
		{
			auto* api = new OpenGLApi();

			shader_program = api->createShaderProgram("C:\\dev\\Turbo\\Turbo\\src\\Engine\\MainSystems\\Renderer\\Shaders\\shader.vertex", "C:\\dev\\Turbo\\Turbo\\src\\Engine\\MainSystems\\Renderer\\Shaders\\shader.fragment");

			float vertices[] = {
				-0.1f, -0.1f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
				0.1f, -0.1f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
				0.0f, 0.1f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f
			}; // centered in the middle by default


			vertex_array = api->createVertexArray();

			std::shared_ptr<IVertexBuffer> vertex_buffer = api->createVertexBuffer();
			vertex_buffer->addData(vertices, sizeof(vertices));

			vertex_array->addAttribute(0, 3, 9, 0);
			vertex_array->addAttribute(1, 4, 9, 3);
			vertex_array->addAttribute(2, 2, 9, 7);

			shader_program->use();
			vertex_array->use();
		}

		static void createBaseRectangle(std::shared_ptr<IShaderProgram>& shader_program, std::shared_ptr<IVertexArray>& vertex_array)
		{
			auto* api = new OpenGLApi();

			shader_program = api->createShaderProgram("C:\\dev\\Turbo\\Turbo\\src\\Engine\\MainSystems\\Renderer\\Shaders\\shader.vertex", "C:\\dev\\Turbo\\Turbo\\src\\Engine\\MainSystems\\Renderer\\Shaders\\shader.fragment");

			float vertices[] = {
				0.1f, 0.1f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
				0.1f, -0.1f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
				-0.1f, -0.1f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
				- 0.1f, 0.1f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f
			}; // centered in the middle by default

			unsigned int indices[] = {
				0, 1, 3,
				1, 2, 3,
			};

			vertex_array = api->createVertexArray();

			std::shared_ptr<IVertexBuffer> vertex_buffer = api->createVertexBuffer();
			vertex_buffer->addData(vertices, sizeof(vertices));

			std::shared_ptr<IElementBuffer> element_buffer = api->createElementBuffer();
			element_buffer->addData(indices, sizeof(indices));

			vertex_array->addAttribute(0, 3, 9, 0);
			vertex_array->addAttribute(1, 4, 9, 3);
			vertex_array->addAttribute(2, 2, 9, 7);

			shader_program->use();
			vertex_array->use();
		}

		static void createBaseLine(std::shared_ptr<IShaderProgram>& shader_program, std::shared_ptr<IVertexArray>& vertex_array)
		{
			auto* api = new OpenGLApi();

			shader_program = api->createShaderProgram("C:\\dev\\Turbo\\Turbo\\src\\Engine\\MainSystems\\Renderer\\Shaders\\shader.vertex", "C:\\dev\\Turbo\\Turbo\\src\\Engine\\MainSystems\\Renderer\\Shaders\\shader.fragment");

			float vertices[] = {
				-0.1f, -0.1f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
				0.1f, -0.1f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f
			}; // centered in the middle by default

			vertex_array = api->createVertexArray();

			std::shared_ptr<IVertexBuffer> vertex_buffer = api->createVertexBuffer();
			vertex_buffer->addData(vertices, sizeof(vertices));

			vertex_array->addAttribute(0, 3, 9, 0);
			vertex_array->addAttribute(1, 4, 9, 3);
			vertex_array->addAttribute(2, 2, 9, 7);

			shader_program->use();
			vertex_array->use();
		}
	};
}
