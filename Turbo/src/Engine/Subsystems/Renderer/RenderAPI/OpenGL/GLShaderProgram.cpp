#include "GLShaderProgram.h"

namespace Turbo 
{

	GLShaderProgram::GLShaderProgram(const std::string vertexPath, const std::string& fragmentPath)
	{
		unsigned int vertex_shader = createShader(vertexPath, GL_VERTEX_SHADER);
		unsigned int fragment_shader = createShader(fragmentPath, GL_FRAGMENT_SHADER);

		id = glCreateProgram();

		glAttachShader(id, vertex_shader);
		glAttachShader(id, fragment_shader);

		glLinkProgram(id);

		int linking_succeded;
		char info_log[512];
		glGetProgramiv(id, GL_LINK_STATUS, &linking_succeded);

		if (!linking_succeded)
		{
			glGetProgramInfoLog(id, 512, NULL, info_log);

			std::cout << "Shader program linking failed : " << info_log << '\n';
		}
	}

	unsigned int GLShaderProgram::createShader(const std::string& path, GLenum shaderType)
	{
		// TO FIX

		unsigned int shader_id = glCreateShader(shaderType);

		char* shader_source = new char[200];

		strcpy_s(shader_source, 200, FileSystem::readFileAsString(path).c_str());

		for (int i = 0; shader_source[i] != NULL; i++)
			std::cout << shader_source[i];

		glShaderSource(shader_id, 1, &(shader_source), NULL);
		glCompileShader(shader_id);

		int compilation_succeded;
		char info_log[512];
		glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compilation_succeded);

		if (!compilation_succeded)
		{
			glGetShaderInfoLog(shader_id, 512, NULL, info_log);

			std::cout << "Shader compilation failed : " << info_log << '\n';
		}

		return shader_id;
	}

	void GLShaderProgram::use()
	{
		glUseProgram(id);
	}
}