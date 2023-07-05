#include "OpenGLApi.h"

namespace Turbo 
{
	IShaderProgram* OpenGLApi::createShaderProgram(const std::string& vertexPath, const std::string& fragmentPath)
	{
		GLShaderProgram* program = new GLShaderProgram(vertexPath, fragmentPath);

		return program;
	}

	IVertexBuffer* OpenGLApi::createVertexBuffer()
	{
		GLVertexBuffer* buffer = new GLVertexBuffer();

		return buffer;
	}

	IVertexArray* OpenGLApi::createVertexArray()
	{
		GLVertexArray* buffer = new GLVertexArray();

		return buffer;
	}
}