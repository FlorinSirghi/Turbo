#pragma once

#include "../RenderAPI/OpenGL/OpenGLApi.h"
#include "../../GameSystem.h"

#include <queue>

namespace Turbo
{
	class Renderer2D : public GameSystem
	{
	public:

		static Vector3D camera_position;

		static Matrix4 tr;

		static void draw(const std::string& game_object_name, std::shared_ptr<IShaderProgram> shader, std::shared_ptr<IVertexArray> vertex_array, Vector3D obj_pos);
		static void drawElements(const std::string& game_object_name, std::shared_ptr<IShaderProgram> shader, std::shared_ptr<IVertexArray> vertex_array, Vector3D obj_pos);
	};

}
