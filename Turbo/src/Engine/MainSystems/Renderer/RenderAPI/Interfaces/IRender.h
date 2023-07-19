#pragma once

#include <memory>

#include "IShaderProgram.h"
#include "IVertexBuffer.h"
#include "IVertexArray.h"

#include <string>

#include "IElementBuffer.h"

namespace Turbo 
{

	class IRender
	{
	public:
		virtual std::shared_ptr<IShaderProgram> createShaderProgram(const std::string& vertexPath, const std::string& fragmentPath) = 0;

		virtual std::shared_ptr<IVertexBuffer> createVertexBuffer() = 0;

		virtual std::shared_ptr<IVertexArray> createVertexArray() = 0;

		virtual std::shared_ptr<IElementBuffer> createElementBuffer() = 0;

	};

}
