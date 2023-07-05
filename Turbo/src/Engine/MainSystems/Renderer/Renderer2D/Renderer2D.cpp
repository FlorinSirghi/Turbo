#include "Renderer2D.h"

namespace Turbo
{

	void Renderer2D::createTriangle()
	{
		auto* api = new OpenGLApi();

		IShaderProgram* shader_program = api->createShaderProgram("C:\\dev\\Turbo\\Turbo\\src\\Engine\\MainSystems\\Renderer\\Shaders\\shader.vertex", "C:\\dev\\Turbo\\Turbo\\src\\Engine\\MainSystems\\Renderer\\Shaders\\shader.fragment");

		float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f, 0.5f, 0.0f
		};

		Matrix4 tr = Matrix4::identity;
		Vector3D trans = Vector3D(1, 0, 0);
		tr.translate(trans);

		shader_program->setUniformMat4(tr.getTranspose(), "transformation");
		
		IVertexArray* vertex_array = api->createVertexArray();

		IVertexBuffer* vertex_buffer = api->createVertexBuffer();
		vertex_buffer->addData(vertices, sizeof(vertices));

		vertex_array->addAttribute(0, 3);

		shader_program->use();
		vertex_array->use();
	}

	void Renderer2D::draw()
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
}