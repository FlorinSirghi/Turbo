#pragma once

#include "glad/glad.h"

#include <stdint.h>

namespace Turbo
{
	class IVertexArray
	{
	public:

		virtual void use() = 0;

		virtual void addAttribute(uint32_t location, uint32_t size) = 0;

		inline unsigned int getID() { return id; }

	protected:

		unsigned int id;
	};
}