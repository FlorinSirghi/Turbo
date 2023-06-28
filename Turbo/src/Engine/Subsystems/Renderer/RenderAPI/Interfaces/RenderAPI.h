#pragma once

#include "ShaderProgramAPI.h"

#include <string>

namespace Turbo 
{

	class RenderAPI
	{
	public:
		virtual void createVertexBuffer() = 0;

		virtual ShaderProgramAPI* createShaderProgram(const std::string& vertexPath, const std::string& fragmentPath) = 0;

	private:
	};

}