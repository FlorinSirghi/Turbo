#pragma once

#include "glad/glad.h"

#include "../../../../CoreSystems/FileSystem/FileSystem.h"
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

		unsigned int createShader(const std::string& path, const ShaderType& type) override;

		void setUniformMat4(const Matrix4& mat4, const std::string& uniform_name) override;
		void setUniformVec4(const Vector4D& vec4, const std::string& uniform_name) override;

		void use() override;

		GLenum turboShaderToGLShader(const ShaderType& type);
	};

}