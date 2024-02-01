#include "GLElementBuffer.h"

#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/Interfaces/IElementBuffer.h"
#include "glad/glad.h"

namespace Turbo
{
	GLElementBuffer::GLElementBuffer()
	{
		glGenBuffers(1, &id);

		use();
	}

	void GLElementBuffer::addData(const void* data, const uint32_t& size)
	{
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	void GLElementBuffer::use()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	}

}
