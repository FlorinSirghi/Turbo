#pragma once

#include "RenderAPI/Interfaces/IShaderProgram.h"
#include "RenderAPI/Interfaces/IVertexArray.h"

#include <memory>
#include <stdint.h>

namespace Turbo
{
	class RenderCommand
	{
	public:

		RenderCommand(std::shared_ptr<IShaderProgram> sp, std::shared_ptr<IVertexArray> va, std::shared_ptr<ITexture> tex, const Vector3D& pos, const uint32_t& vc, const bool& i, const int& m) :
						shader_program(std::move(sp)), vertex_array(std::move(va)), texture(std::move(tex)), position(pos), vertex_count(vc), indexed(i), mode(m){
		}

		std::shared_ptr<IShaderProgram> shader_program;
		std::shared_ptr<IVertexArray> vertex_array;
		std::shared_ptr<ITexture> texture;
		int mode;
		Vector3D position;
		uint32_t vertex_count;
		bool indexed;
	};
}
