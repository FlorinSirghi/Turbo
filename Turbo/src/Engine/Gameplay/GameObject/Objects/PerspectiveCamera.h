#ifndef ENGINE_GAMEPLAY_GAMEOBJECT_OBJECT_PERSPECTIVECAMERA_H_
#define ENGINE_GAMEPLAY_GAMEOBJECT_OBJECT_PERSPECTIVECAMERA_H_


#include "Engine/Gameplay/EventSystem/Event.h"
#include "Engine/Gameplay/GameObject/GameObjectModel/GameObject.h"
#include "Engine/Core/IDS/IDManager.h"

namespace Turbo
{
	class PerspectiveCamera : public GameObject
	{
	public:

		PerspectiveCamera(IDManager id_manager);

		void onEvent(Event event) override;
	};
}

#endif // ENGINE_GAMEPLAY_GAMEOBJECT_OBJECT_PERSPECTIVECAMERA_H_
