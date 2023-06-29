#pragma once

#include "glad/glad.h"

#include <string>
#include <vector>

#include "ShaderType.h"

namespace Turbo
{
	class IShaderProgram
	{
	public:

		virtual unsigned int createShader(const std::string& path, const ShaderType& type) = 0;

		virtual void use() = 0;

		inline unsigned int getID() { return id; }

	protected:

		unsigned int id;
	};

}