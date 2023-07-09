#pragma once

#include "Property.h"
#include <memory>
#include "../../../Renderer/Renderer2D/Renderer2D.h"

namespace Turbo
{
	class Mesh final : public Property 
	{
	public:
		Mesh(const std::string& game_object_name)
		{
			name = MESH;
			object_name = game_object_name;
			Renderer2D::createTriangle();
		}

		void effect(std::shared_ptr<GameObject> go) override
		{
			Renderer2D::draw(object_name);
		}

		virtual ~Mesh() = default;
	};
}