#pragma once

#include "Property.h"
#include <memory>
#include "../../../Renderer/Renderer2D/Renderer2D.h"

namespace Turbo
{
	constexpr std::string_view MESH_TRIANGLE = "MeshTriangle";
	constexpr std::string_view MESH_SQUARE = "MeshSquare";

	class Mesh final : public Property 
	{
	public:

		std::shared_ptr<IShaderProgram> shader_program;

		std::shared_ptr<IVertexArray> vertex_array;

		std::string_view mesh_type;

		Mesh(std::shared_ptr<GameObject> go, std::string_view mesh) : Property(go)
		{
			name = MESH;
			mesh_type = mesh;

			if(mesh == MESH_TRIANGLE)
			{
				auto* api = new OpenGLApi();

				shader_program = api->createShaderProgram("C:\\dev\\Turbo\\Turbo\\src\\Engine\\MainSystems\\Renderer\\Shaders\\shader.vertex", "C:\\dev\\Turbo\\Turbo\\src\\Engine\\MainSystems\\Renderer\\Shaders\\shader.fragment");

				float vertices[] = {
					-0.1f, -0.1f, 0.0f,
					0.1f, -0.1f, 0.0f,
					0.0f, 0.1f, 0.0f
				}; // centered in the middle by default


				vertex_array = api->createVertexArray();

				std::shared_ptr<IVertexBuffer> vertex_buffer = api->createVertexBuffer();
				vertex_buffer->addData(vertices, sizeof(vertices));

				vertex_array->addAttribute(0, 3);

				shader_program->use();
				vertex_array->use();
			}

			if(mesh == MESH_SQUARE)
			{
				auto* api = new OpenGLApi();

				shader_program = api->createShaderProgram("C:\\dev\\Turbo\\Turbo\\src\\Engine\\MainSystems\\Renderer\\Shaders\\shader.vertex", "C:\\dev\\Turbo\\Turbo\\src\\Engine\\MainSystems\\Renderer\\Shaders\\shader.fragment");

				float vertices[] = {
					0.1f, 0.1f, 0.0f,
					0.1f, -0.1f, 0.0f,
					-0.1f, -0.1f, 0.0f,
					-0.1f, 0.1f, 0.0f

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

				vertex_array->addAttribute(0, 3);

				shader_program->use();
				vertex_array->use();
			}
		}

		void effect() override
		{
			std::shared_ptr<Position> pos = std::dynamic_pointer_cast<Position>(game_object->getPropertyByName(POSITION));
			if(mesh_type == MESH_TRIANGLE)
				Renderer2D::draw(game_object->getName(), shader_program, vertex_array, pos->pos);
			if (mesh_type == MESH_SQUARE)
				Renderer2D::drawElements(game_object->getName(), shader_program, vertex_array, pos->pos);
		}

		virtual ~Mesh() = default;
	};
}