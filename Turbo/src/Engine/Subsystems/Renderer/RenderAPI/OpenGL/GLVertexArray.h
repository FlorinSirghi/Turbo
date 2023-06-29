#pragma once

#include "../Interfaces/IVertexArray.h"

namespace Turbo
{

	class GLVertexArray : public IVertexArray
	{
	public:

		GLVertexArray();

		virtual void use() override;

		virtual void addAttribute(uint32_t location, uint32_t size) override;

	};

}