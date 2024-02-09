#ifndef SCENEGRAPH_CAMERA_H_
#define SCENEGRAPH_CAMERA_H_

namespace Turbo
{
	struct Camera
	{
	public:

		Vector3D direction{0.0f, -10.0f, 0.0f};
		Vector3D up{0.0f, 1.0f, 0.0f};

		float pitch = 50.0f;
		float yaw = 20.0f;
	};
}

#endif // SCENEGRAPH_CAMERA_H_