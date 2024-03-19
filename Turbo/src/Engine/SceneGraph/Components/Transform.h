#ifndef ENGINE_SCENEGRAPH_COMPONENTS_PROPERTIES_TRANSFORM_H_
#define ENGINE_SCENEGRAPH_COMPONENTS_PROPERTIES_TRANSFORM_H_

#include "Engine/Core/Math/Vector/Vector3D.h"

namespace Turbo
{
	struct Transform
	{
		Vector3D position;
		Vector3D scale;
		Vector3D rotation;
		Vector3D localPosition;
		Vector3D localRotation;

		Transform(const Vector3D& pos = {0.0f, 0.0f, 0.0f}, 
		          const Vector3D& scl = {1.0f, 1.0f, 1.0f},
				  const Vector3D& rot = {0.0f, 0.0f, 0.0f},
				  const Vector3D& local_pos = {0.0f, 0.0f, 0.0f},
				  const Vector3D& local_rot = {0.0f, 0.0f, 0.0f})
				  : position(pos), scale(scl), rotation(rot), localPosition(local_pos), localRotation(local_rot)
		{
		}
	};
}

#endif // ENGINE_SCENEGRAPH_COMPONENTS_PROPERTIES_TRANSFORM_H_