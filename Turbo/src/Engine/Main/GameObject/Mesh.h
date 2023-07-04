#pragma once

#include "Property.h"
#include <memory>
#include "../../Subsystems/Renderer/Renderer2D/Renderer2D.h"

namespace Turbo
{
	class Mesh : public Property
	{
	public:
		Mesh()
		{
			name = "Mesh";
			value = "Triangle";
			Renderer2D::drawTriangle();
		}

		void effect() override
		{
			Renderer2D::draw();
		}
	};
}