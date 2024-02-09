#ifndef SCENEGRAPH_SPRITE_H_
#define SCENEGRAPH_SPRITE_H_

#include <memory>

#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/Interfaces/IShaderProgram.h"
#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/Interfaces/ITexture.h"
#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/Interfaces/IVertexArray.h"
#include "Engine/Renderer/Systems/Renderer2D/PrimitiveManager2D.h"
#include "Engine/Renderer/Systems/Renderer2D/Renderer2D.h"
#include "Engine/Renderer/Systems/Renderer2D/SpriteType.h"
#include "Engine/SceneGraph/Components/Transform.h"

namespace Turbo
{
	struct Sprite
	{
	public:

		std::shared_ptr<IShaderProgram> shader_program;

		std::shared_ptr<IVertexArray> vertex_array;

		std::shared_ptr<ITexture> texture;

		SpriteType mesh_type; // primitive

		Sprite(SpriteType type)
		{
			mesh_type = type;
			PrimitiveManager2D::getPrimitive(shader_program, vertex_array, type);
			texture = ResourceManager::getTexture("wood");
		}
	};
}

#endif // SCENEGRAPH_SPRITE_H_