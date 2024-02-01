#ifndef GRAPHICS_WRAPPER_OPENGLAPI_H_
#define GRAPHICS_WRAPPER_OPENGLAPI_H_

#include "../Interfaces/IRender.h"
#include "glad/glad.h"
#include "GLShaderProgram.h"
#include "GLVertexBuffer.h"
#include "GLVertexArray.h"
#include "GLElementBuffer.h"

namespace Turbo {

	class OpenGLApi : public IRender
	{
	public:
		std::shared_ptr<IVertexBuffer> createVertexBuffer() override;

		std::shared_ptr<IShaderProgram> createShaderProgram(const std::string& vertexPath, const std::string& fragmentPath) override;

		std::shared_ptr<IVertexArray> createVertexArray() override;

		std::shared_ptr<IElementBuffer> createElementBuffer() override;

		std::shared_ptr<ITexture> createTexture(const std::string& path) override;
	};
}

#endif // GRAPHICS_WRAPPER_OPENGLAPI_H_
