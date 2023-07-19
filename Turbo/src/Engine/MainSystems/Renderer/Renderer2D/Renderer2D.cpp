#include "Renderer2D.h"
#include "../../TransformSystem/TransformSystem.h"
#include "../../../../Project/Application.h"
#include "../../../CoreSystems/Time/Time.h"


namespace Turbo
{
	Matrix4 Renderer2D::tr = Matrix4::identity;

	Vector3D Renderer2D::camera_position = Vector3D::zero;

	void Renderer2D::draw(const std::string& game_object_name, std::shared_ptr<IShaderProgram> shader, std::shared_ptr<IVertexArray> vertex_array, Vector3D obj_pos)
	{
		shader->use();
		vertex_array->use();

		tr = Matrix4::identity;

		Vector3D scaled_pos = -camera_position;
		scaled_pos.scale(Time::delta_time);
		scaled_pos.scale(5);

		tr.translate(scaled_pos);
		tr.translate(obj_pos);

		shader->setUniformMat4(tr.getTranspose(), "transformation");

		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void Renderer2D::drawElements(const std::string& game_object_name, std::shared_ptr<IShaderProgram> shader, std::shared_ptr<IVertexArray> vertex_array, Vector3D obj_pos)
	{
		shader->use();
		vertex_array->use();

		tr = Matrix4::identity;

		Vector3D scaled_pos = -camera_position;
		scaled_pos.scale(Time::delta_time);
		scaled_pos.scale(5);

		tr.translate(scaled_pos);
		tr.translate(obj_pos);

		shader->setUniformMat4(tr.getTranspose(), "transformation");

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,0);
	}
}
