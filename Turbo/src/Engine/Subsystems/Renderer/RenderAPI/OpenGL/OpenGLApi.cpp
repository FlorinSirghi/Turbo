#include "OpenGLApi.h"

namespace Turbo 
{
	ShaderProgramAPI* OpenGLApi::createShaderProgram(const std::string& vertexPath, const std::string& fragmentPath)
	{
		GLShaderProgram* program = new GLShaderProgram(vertexPath, fragmentPath);

		return program;
	}
}