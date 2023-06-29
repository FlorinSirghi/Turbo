#pragma once

#include "glad/glad.h"

#include "../../../FileSystem/FileSystem.h"
#include "../Interfaces/IShaderProgram.h"

#include <string>
#include <vector>
#include <iostream>

namespace Turbo 
{
	class GLShaderProgram : public IShaderProgram
	{
	public:

		GLShaderProgram(const std::string vertexPath, const std::string& fragmentPath);

		unsigned int createShader(const std::string& path, GLenum shaderType) override;

		void use() override;
	};

}