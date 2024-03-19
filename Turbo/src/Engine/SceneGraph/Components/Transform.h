#ifndef ENGINE_SCENEGRAPH_COMPONENTS_PROPERTIES_TRANSFORM_H_
#define ENGINE_SCENEGRAPH_COMPONENTS_PROPERTIES_TRANSFORM_H_

#include "Engine/Core/Math/Vector/Vector3D.h"

namespace Turbo
{
	struct Transform
	{
		// Global position
		Vector3D position;
		// Global scale
		Vector3D scale;
		// Global rotation
		Vector3D rotation;

		// The position of the object relative to its parent
		Vector3D local_position;
		// The scale of the object relative to its parent
		Vector3D local_scale;
		// The rotation of the object relative to its parent
		Vector3D local_rotation;
		// Matrix to store the translations required to update the children relative to its parent(s)
		Matrix4 matrixHierarchy{Matrix4::identity};

		Transform(const Vector3D& pos = {0.0f, 0.0f, 0.0f}, 
		          const Vector3D& scl = {1.0f, 1.0f, 1.0f},
				  const Vector3D& rot = {0.0f, 0.0f, 0.0f},
				  const Vector3D& local_pos = {0.0f, 0.0f, 0.0f},
				  const Vector3D& local_scl = {1.0f, 1.0f, 1.0f},
				  const Vector3D& local_rot = {0.0f, 0.0f, 0.0f})
				  : position(pos), scale(scl), rotation(rot),
					local_position(local_pos), local_scale(local_scl), local_rotation(local_rot)
		{
		}
	};
}

#endif // ENGINE_SCENEGRAPH_COMPONENTS_PROPERTIES_TRANSFORM_H_