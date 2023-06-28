#pragma once

#include "glad/glad.h"

#include <string>
#include <vector>

namespace Turbo
{
	class ShaderProgramAPI
	{
	public:

		virtual unsigned int createShader(const std::string& path, GLenum shaderType) = 0;

		virtual void use() = 0;

		inline unsigned int getID() { return id; }

	protected:

		unsigned int id;
	};

}