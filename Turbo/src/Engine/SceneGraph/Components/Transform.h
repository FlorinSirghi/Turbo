#ifndef ENGINE_SCENEGRAPH_COMPONENTS_PROPERTIES_TRANSFORM_H_
#define ENGINE_SCENEGRAPH_COMPONENTS_PROPERTIES_TRANSFORM_H_

#include "Engine/Core/Math/Vector/Vector3D.h"

namespace Turbo
{
	struct Transform
	{
	public:

		Vector3D position;
		Vector3D scale;
		Vector3D rotation;

		Transform(const Vector3D& position = {0.0f, 0.0f, 0.0f}, 
		          const Vector3D& scale = {1.0f, 1.0f, 1.0f}, const Vector3D& rotation = {0.0f, 0.0f, 0.0f})
				  : position(position), scale(scale), rotation(rotation)
		{
		}
	};
}

#endif // ENGINE_SCENEGRAPH_COMPONENTS_PROPERTIES_TRANSFORM_H_