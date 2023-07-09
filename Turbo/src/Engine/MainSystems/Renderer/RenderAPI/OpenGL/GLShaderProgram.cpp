#include "GLShaderProgram.h"

namespace Turbo 
{

	GLShaderProgram::GLShaderProgram(const std::string vertexPath, const std::string& fragmentPath)
	{
		unsigned int vertex_shader = createShader(vertexPath, VERTEX);
		unsigned int fragment_shader = createShader(fragmentPath, FRAGMENT);

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

		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);

		use();
	}

	unsigned int GLShaderProgram::createShader(const std::string& path, const ShaderType& type)
	{
		
		GLenum glShaderType = turboShaderToGLShader(type);

		unsigned int shader_id = glCreateShader(glShaderType);

		std::string shader_str = FileSystem::readFileAsString(path);

		char* shader_source = new char[shader_str.size() + 1];

		strcpy_s(shader_source, shader_str.size() + 1, shader_str.c_str());

		glShaderSource(shader_id, 1, &(shader_source), NULL);
		glCompileShader(shader_id);

		delete[] shader_source;

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

	void GLShaderProgram::setUniformMat4(const Matrix4& mat4, const std::string& uniform_name)
	{
		int uniform_location = glGetUniformLocation(id, uniform_name.c_str());

		auto* mat_data = new float[16];

		mat4.getPointer(mat_data);

		glUniformMatrix4fv(uniform_location, 1, GL_FALSE, mat_data);
	}

	void GLShaderProgram::setUniformVec4(const Vector4D& vec4, const std::string& uniform_name)
	{
		int uniform_location = glGetUniformLocation(id, uniform_name.c_str());

		auto* vec_data = new float[4];

		vec4.getPointer(vec_data);

		glUniformMatrix4fv(uniform_location, 1, GL_FALSE, vec_data);
	}

	void GLShaderProgram::use()
	{
		glUseProgram(id);
	}

	GLenum GLShaderProgram::turboShaderToGLShader(const ShaderType& type)
	{
		switch (type)
		{
		case VERTEX:
			return GL_VERTEX_SHADER;
		case FRAGMENT:
			return GL_FRAGMENT_SHADER;
		}
	}
}