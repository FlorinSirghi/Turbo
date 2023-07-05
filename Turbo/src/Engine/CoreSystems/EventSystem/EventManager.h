#pragma once

#include "Event.h"
#include "../../MainSystems/SceneGraph/GameObject/GameObject.h"

#include <memory>
#include <queue>

namespace Turbo
{
	class EventManager
	{
	public:

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