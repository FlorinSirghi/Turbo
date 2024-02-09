#ifndef ENGINE_GAMEPLAY_GAMEOBJECT_OBJECT_ORTHOGRAPHICCAMERA_H_
#define ENGINE_GAMEPLAY_GAMEOBJECT_OBJECT_ORTHOGRAPHICCAMERA_H_

#include "Engine/Core/Math/Vector/Vector3D.h"
#include "Engine/Gameplay/EventSystem/Event.h"
#include "Engine/Gameplay/GameObject/GameObjectModel/GameObject.h"
#include "Engine/Core/IDS/IDManager.h"
#include "Engine/SceneGraph/Scene/Scene.h"

namespace Turbo
{
	class OrthographicCamera : public GameObject
	{
	public:

		//Vector3D direction;
		//Vector3D up;

		//float pitch = 0.0f;
		//float yaw = 0.0f;

		OrthographicCamera(std::shared_ptr<IDManager> id_manager);

		void onEvent(Event event) override;
	};
}

#endif // ENGINE_GAMEPLAY_GAMEOBJECT_OBJECT_ORTHOGRAPHICCAMERA_H_
