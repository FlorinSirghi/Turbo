#ifndef ENGINE_GAMEPLAY_EVENTSYSTEM_EVENTMANAGER_H_
#define ENGINE_GAMEPLAY_EVENTSYSTEM_EVENTMANAGER_H_

#include <memory>
#include <queue>

#include "Event.h"
#include "Engine/Gameplay/GameObject/GameObjectModel/GameObject.h"

namespace Turbo
{
	class EventManager
	{
	public:

		// Nu e ok singleton

		static EventManager& getInstance()
		{
			static EventManager* instance = new EventManager();
			return *instance;
		}

		void postEvent(const Event& event);

		void pollEvent();

		void addListener(std::shared_ptr<GameObject> object);


	private:

		std::queue<Event> events;

		std::vector<std::shared_ptr<GameObject>> listeners;
	};
}

#endif // ENGINE_GAMEPLAY_EVENTSYSTEM_EVENTMANAGER_H_