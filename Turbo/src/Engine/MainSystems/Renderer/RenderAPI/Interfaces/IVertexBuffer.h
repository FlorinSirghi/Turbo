#pragma once

#include <stdint.h>

namespace Turbo
{

	class IVertexBuffer
	{
	public:

		virtual void use() = 0;

		virtual void addData(const void* data, const uint32_t& size) = 0;

		unsigned int getID() { return id; }

	protected:

		unsigned int id;
	};

}