#include "Renderer2D.h"

namespace Turbo
{

	void Renderer2D::createTriangle()
	{
		OpenGLApi* api = new OpenGLApi();

		IShaderProgram* shader_program = api->createShaderProgram("C:\\dev\\Turbo\\Turbo\\src\\Shaders\\shader.vertex", "C:\\dev\\Turbo\\Turbo\\src\\Shaders\\shader.fragment");

		float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f, 0.5f, 0.0f
		};
		
		IVertexArray* vertex_array = api->createVertexArray();

		IVertexBuffer* vertex_buffer = api->createVertexBuffer();
		vertex_buffer->addData(vertices, sizeof(vertices));

		vertex_array->addAttribute(0, 3);

		shader_program->use();
		vertex_array->use();
	}
}