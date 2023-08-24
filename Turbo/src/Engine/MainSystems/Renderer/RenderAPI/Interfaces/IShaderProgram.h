#pragma once

#include "glad/glad.h"

#include "ShaderType.h"
#include "../../../../CoreSystems/Math/Matrix/Matrix4.h"
#include "../../../../CoreSystems/Math/Vector/Vector4D.h"

#include <string>
#include <vector>


namespace Turbo
{
	class IShaderProgram
	{
	public:

		virtual unsigned int createShader(const std::string& path, const ShaderType& type) = 0;

		virtual void setUniformMat4(const Matrix4& mat4, const std::string& uniform_name) = 0;
		virtual void setUniformVec4(const Vector4D& vec4, const std::string& uniform_name) = 0;

		virtual void use() = 0;

		unsigned int getID() { return id; }

	protected:

		unsigned int id;
	};

}