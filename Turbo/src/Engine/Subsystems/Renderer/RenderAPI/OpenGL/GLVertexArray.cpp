#include "GLVertexArray.h"

namespace Turbo
{
	GLVertexArray::GLVertexArray()
	{
		glGenVertexArrays(1, &id);

		glBindVertexArray(id);
	}

	void GLVertexArray::addAttribute(uint32_t location, uint32_t size)
	{
		glVertexAttribPointer(location, size, GL_FLOAT, GL_FALSE, size * sizeof(float), (const void*)0);

		glEnableVertexAttribArray(location);
	}

	void GLVertexArray::use()
	{
		glBindVertexArray(id);
	}
}