#ifndef ENGINE_GAMEPLAY_SYSTEMS_CAMERA_SYSTEM_H
#define ENGINE_GAMEPLAY_SYSTEMS_CAMERA_SYSTEM_H
#include "Engine/SceneGraph/Scene/Scene.h"

namespace Turbo
{
	class CameraSystem
	{
	public:

		void processCameras(std::shared_ptr<Scene>);
	};
}

#endif