#ifndef ENGINE_SCENEGRAPH_COMPONENTS_PROPERTIES_TRANSFORM_H_
#define ENGINE_SCENEGRAPH_COMPONENTS_PROPERTIES_TRANSFORM_H_

#include "Engine/Gameplay/GameObject/GameObjectModel/Component.h"

namespace Turbo
{
	class Transform : public Component
	{
	public:

		Vector3D position;
		Vector3D scale;
		Vector3D rotation;

		Transform(const Vector3D& position = {0.0f, 0.0f, 0.0f}, 
		          const Vector3D& scale = {1.0f, 1.0f, 1.0f}, const Vector3D& rotation = {0.0f, 0.0f, 0.0f})
				  : position(position), scale(scale), rotation(rotation)
		{
			name = TRANSFORM;
		}

		void update() override
		{
			
		}
	};
}

#endif // ENGINE_SCENEGRAPH_COMPONENTS_PROPERTIES_TRANSFORM_H_