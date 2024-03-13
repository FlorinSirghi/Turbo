#ifndef ENGINE_GAMEPLAY_SYSTEMS_CAMERA_SYSTEM_H
#define ENGINE_GAMEPLAY_SYSTEMS_CAMERA_SYSTEM_H
#include "Engine/SceneGraph/Scene/Scene.h"

namespace Turbo
{
	class CameraSystem
	{
	public:

		void processCameras(std::shared_ptr<Scene>);

		float getCameraSpeed() const { return this->speed; }
		void setCameraSpeed(float speed) { this->speed = speed; }

		float getCameraSensitivity() const { return this->sensitivity; }
		void setCameraSensitivity(float sensitivity) { this->sensitivity = sensitivity; }

	private:

		float speed = 1.0f;
		float sensitivity = 0.1f;
	};
}

#endif