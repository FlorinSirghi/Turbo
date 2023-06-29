#pragma once

#include "IShaderProgram.h"
#include "IVertexBuffer.h"
#include "IVertexArray.h"

#include <string>

namespace Turbo 
{

	class IRender
	{
	public:
		virtual IVertexBuffer* createVertexBuffer() = 0;

		virtual IShaderProgram* createShaderProgram(const std::string& vertexPath, const std::string& fragmentPath) = 0;

		virtual IVertexArray* createVertexArray() = 0;

	};

}