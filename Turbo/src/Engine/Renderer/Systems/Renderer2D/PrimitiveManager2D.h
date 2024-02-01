#ifndef SCENEGRAPH_PRIMITIVEMANAGER2D_H_
#define SCENEGRAPH_PRIMITIVEMANAGER2D_H_

#include "SpriteType.h"

#include <memory>

#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/OpenGL/OpenGLApi.h"
#include "Engine/ResourceManager/ResourceManager.h"

namespace Turbo
{
	class PrimitiveManager2D
	{
	public:

		static void getPrimitive(std::shared_ptr<IShaderProgram>& shader_program, std::shared_ptr<IVertexArray>& vertex_array ,SpriteType type)
		{
			switch (type)
			{
			case SpriteType::TRIANGLE:
				createBaseTriangle(shader_program, vertex_array);
				break;
			case SpriteType::RECTANGLE:
				createBaseRectangle(shader_program, vertex_array);
				break;
			case SpriteType::LINE:
				createBaseLine(shader_program, vertex_array);
				break;
			}
		}

	private:

		static void createBaseTriangle(std::shared_ptr<IShaderProgram>& shader_program, std::shared_ptr<IVertexArray>& vertex_array)
		{
			auto* api = new OpenGLApi();

			shader_program = ResourceManager::getShaderProgram("primitive_shader");

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

			shader_program = ResourceManager::getShaderProgram("primitive_shader");

			float vertices[] = {
				-0.1f, 0.1f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
				0.1f, 0.1f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
				-0.1f, -0.1f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
				0.1f, -0.1f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f
			}; // centered in the middle by default

			unsigned int indices[] = {
				0, 1, 2,
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

			shader_program = ResourceManager::getShaderProgram("primitive_shader");

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

#endif // SCENEGRAPH_PRIMITIVEMANAGER2D_H_