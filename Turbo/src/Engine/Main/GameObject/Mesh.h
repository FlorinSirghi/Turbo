#pragma once

#include "Property.h"
#include <memory>
#include "../../Subsystems/Renderer/Renderer2D/Renderer2D.h"

namespace Turbo
{
	class Mesh final : public Property 
	{
	public:
		Mesh()
		{
			name = "Mesh";
			value = "Triangle";
			Renderer2D::drawTriangle();
		}

		virtual ~Mesh() = default;

		void effect() override
		{
			Renderer2D::draw();
		}


	};
}