#include "Renderer2D.h"
#include "../../TransformSystem/TransformSystem.h"
#include "../../../../Project/Application.h"
#include "../../../CoreSystems/Time/Time.h"

namespace Turbo
{
	Matrix4 Renderer2D::tr = Matrix4::identity;

	IShaderProgram* Renderer2D::shader_program;

	IVertexArray* Renderer2D::vertex_array;

	Vector3D Renderer2D::camera_position = Vector3D::zero;

	void Renderer2D::createTriangle()
	{
		auto* api = new OpenGLApi();

		shader_program = api->createShaderProgram("C:\\dev\\Turbo\\Turbo\\src\\Engine\\MainSystems\\Renderer\\Shaders\\shader.vertex", "C:\\dev\\Turbo\\Turbo\\src\\Engine\\MainSystems\\Renderer\\Shaders\\shader.fragment");

		float vertices[] = {
			-0.1f, -0.1f, 0.0f,
			0.1f, -0.1f, 0.0f,
			0.0f, 0.1f, 0.0f
		}; // centered in the middle by default

		vertex_array = api->createVertexArray();

		IVertexBuffer* vertex_buffer = api->createVertexBuffer();
		vertex_buffer->addData(vertices, sizeof(vertices));

		vertex_array->addAttribute(0, 3);

		shader_program->use();
		vertex_array->use();
	}

	void Renderer2D::draw(const std::string& game_object_name)
	{
		tr = Matrix4::identity;

		Vector3D scaled_pos = -camera_position;
		scaled_pos.scale(Time::delta_time);
		scaled_pos.scale(5);

		tr.translate(scaled_pos);

		shader_program->setUniformMat4(tr.getTranspose(), "transformation");

		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
}