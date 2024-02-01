#include "GLVertexBuffer.h"

#include "glad/glad.h"

#include "../Interfaces/IVertexBuffer.h"

namespace Turbo
{
	GLVertexBuffer::GLVertexBuffer()
	{
		glGenBuffers(1, &id);

		use();
	}

	void GLVertexBuffer::addData(const void* data, const uint32_t& size)
	{
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	void GLVertexBuffer::use()
	{
		glBindBuffer(GL_ARRAY_BUFFER, id);
	}

}