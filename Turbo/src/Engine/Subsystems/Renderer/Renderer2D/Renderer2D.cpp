#include "Renderer2D.h"

namespace Turbo
{

	void Renderer2D::createTriangle()
	{
		IShaderProgram* shader_program = new GLShaderProgram("C:\\dev\\Turbo\\Turbo\\src\\Shaders\\shader.vertex", "C:\\dev\\Turbo\\Turbo\\src\\Shaders\\shader.fragment");

		float vertices[] = {
-0.5f, -0.5f, 0.0f,
0.5f, -0.5f, 0.0f,
0.0f, 0.5f, 0.0f
		};
		
		IVertexArray* vertex_array = new GLVertexArray();

		IVertexBuffer* vertex_buffer = new GLVertexBuffer();
		vertex_buffer->addData(vertices, sizeof(vertices));

		vertex_array->addAttribute(0, 3);

		shader_program->use();
		vertex_array->use();
	}
}