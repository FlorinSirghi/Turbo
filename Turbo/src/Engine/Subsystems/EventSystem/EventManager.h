#pragma once

#include "Event.h"
#include "../../Main/GameObject/GameObject.h"

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

		void addListener(std::unique_ptr<GameObject> object);


	private:

		std::queue<Event> events;

		std::vector<std::unique_ptr<GameObject>> listeners;
	};
}