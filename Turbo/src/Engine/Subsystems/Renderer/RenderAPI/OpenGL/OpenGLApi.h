#pragma once

#include "../Interfaces/IRender.h"
#include "glad/glad.h"
#include "GLShaderProgram.h"
#include "GLVertexBuffer.h"
#include "GLVertexArray.h"

namespace Turbo {

	class OpenGLApi : public IRender
	{
		IVertexBuffer* createVertexBuffer() override;

		IShaderProgram* createShaderProgram(const std::string& vertexPath, const std::string& fragmentPath) override;

		IVertexArray* createVertexArray() override;
	};
}

