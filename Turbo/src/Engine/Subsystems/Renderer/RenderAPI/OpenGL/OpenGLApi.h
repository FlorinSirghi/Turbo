#pragma once

#include "../Interfaces/RenderAPI.h"
#include "glad/glad.h"
#include "GLShaderProgram.h"

namespace Turbo {

	class OpenGLApi : public RenderAPI
	{
		void createVertexBuffer() override;

		ShaderProgramAPI* createShaderProgram(const std::string& vertexPath, const std::string& fragmentPath) override;
	};
}

