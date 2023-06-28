#pragma once

#include "glad/glad.h"

#include "../../../FileSystem/FileSystem.h"
#include "../Interfaces/ShaderProgramAPI.h"

#include <string>
#include <vector>
#include <iostream>

namespace Turbo 
{
	class GLShaderProgram : public ShaderProgramAPI
	{
	public:

		GLShaderProgram(const std::string vertexPath, const std::string& fragmentPath);

		unsigned int createShader(const std::string& path, GLenum shaderType) override;

		void use() override;
	};

}