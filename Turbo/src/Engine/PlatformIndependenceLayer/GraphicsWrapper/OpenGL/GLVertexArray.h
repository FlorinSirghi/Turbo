#ifndef GRAPHICS_WRAPPER_GLVERTEXARRAY_H_
#define GRAPHICS_WRAPPER_GLVERTEXARRAY_H_

#include "../Interfaces/IVertexArray.h"

namespace Turbo
{

	class GLVertexArray : public IVertexArray
	{
	public:

		GLVertexArray();

		virtual void use() override;

		virtual void addAttribute(uint32_t location, uint32_t size, uint32_t stride, uint32_t offset) override;

	};

}

#endif // GRAPHICS_WRAPPER_GLVERTEXARRAY_H_
