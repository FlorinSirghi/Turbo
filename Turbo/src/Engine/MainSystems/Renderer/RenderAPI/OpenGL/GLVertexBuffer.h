#pragma once

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