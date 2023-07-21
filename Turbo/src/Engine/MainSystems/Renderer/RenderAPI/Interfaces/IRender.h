#pragma once

#include <memory>

#include "IShaderProgram.h"
#include "IVertexBuffer.h"
#include "IVertexArray.h"
#include "IElementBuffer.h"
#include "ITexture.h"

#include <string>

namespace Turbo 
{

	class IRender
	{
	public:
		virtual std::shared_ptr<IShaderProgram> createShaderProgram(const std::string& vertexPath, const std::string& fragmentPath) = 0;

		virtual std::shared_ptr<IVertexBuffer> createVertexBuffer() = 0;

		virtual std::shared_ptr<IVertexArray> createVertexArray() = 0;

		virtual std::shared_ptr<IElementBuffer> createElementBuffer() = 0;

		virtual std::shared_ptr<ITexture> createTexture(const std::string& path) = 0;
	};

}
