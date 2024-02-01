#ifndef GRAPHICS_WRAPPER_GLELEMENTBUFFER_H_
#define GRAPHICS_WRAPPER_GLELEMENTBUFFER_H_

#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/Interfaces/IElementBuffer.h"
#include "glad/glad.h"

namespace Turbo
{
	class GLElementBuffer : public IElementBuffer
	{
	public:

		GLElementBuffer();

		void use() override;

		void addData(const void* data, const uint32_t& size) override;
	};
}

#endif // GRAPHICS_WRAPPER_GLELEMENTBUFFER_H_

