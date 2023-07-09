#pragma once

#include "../RenderAPI/OpenGL/OpenGLApi.h"
#include "../../GameSystem.h"

namespace Turbo
{
	class Renderer2D : public GameSystem
	{
	public:

		static Vector3D camera_position;

		static Matrix4 tr;

		static void createTriangle();

		static void draw(const std::string& game_object_name);

		static IShaderProgram* shader_program;

		static IVertexArray* vertex_array;
	};

}