#ifndef GRAPHICS_WRAPPER_GLVERTEXBUFFER_H_
#define GRAPHICS_WRAPPER_GLVERTEXBUFFER_H_

#include "glad/glad.h"

#include "../Interfaces/IVertexBuffer.h"

namespace Turbo
{
	class GLVertexBuffer : public IVertexBuffer
	{
	public:

		GLVertexBuffer();

		void addData(const void* data, const uint32_t& size) override;

		void use() override;
	};

}

#endif // GRAPHICS_WRAPPER_GLVERTEXBUFFER_H_