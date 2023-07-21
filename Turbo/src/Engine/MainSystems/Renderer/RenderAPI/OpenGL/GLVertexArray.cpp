#include "GLVertexArray.h"

namespace Turbo
{
	GLVertexArray::GLVertexArray()
	{
		glGenVertexArrays(1, &id);

		glBindVertexArray(id);
	}

	void GLVertexArray::addAttribute(uint32_t location, uint32_t size, uint32_t stride, uint32_t offset)
	{
		glVertexAttribPointer(location, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (const void*)(offset * sizeof(float)));

		glEnableVertexAttribArray(location);
	}

	void GLVertexArray::use()
	{
		glBindVertexArray(id);
	}
}