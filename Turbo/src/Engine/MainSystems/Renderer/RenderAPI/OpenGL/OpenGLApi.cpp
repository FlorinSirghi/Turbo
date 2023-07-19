#include "OpenGLApi.h"

namespace Turbo 
{
	std::shared_ptr<IShaderProgram> OpenGLApi::createShaderProgram(const std::string& vertexPath, const std::string& fragmentPath)
	{
		auto program = std::make_shared<GLShaderProgram>(vertexPath, fragmentPath);

		return program;
	}

	std::shared_ptr<IVertexBuffer> OpenGLApi::createVertexBuffer()
	{
		auto buffer = std::make_shared<GLVertexBuffer>();

		return buffer;
	}

	std::shared_ptr<IVertexArray> OpenGLApi::createVertexArray()
	{
		auto buffer = std::make_shared<GLVertexArray>();

		return buffer;
	}

	std::shared_ptr<IElementBuffer> OpenGLApi::createElementBuffer()
	{
		auto buffer = std::make_shared<GLElementBuffer>();

		return buffer;
	}

}