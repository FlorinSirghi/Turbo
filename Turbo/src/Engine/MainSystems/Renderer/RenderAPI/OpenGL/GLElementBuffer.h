#pragma once

#include "Engine/MainSystems/Renderer/RenderAPI/Interfaces/IElementBuffer.h"
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
