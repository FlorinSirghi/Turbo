#include "EventManager.h"

namespace Turbo
{
	void EventManager::postEvent(const Event& event)
	{
		events.push(event);
	}

	void EventManager::pollEvent()
	{
		if (!events.empty())
		{
			Event e = events.front();
			events.pop();

			for (const auto& obj : listeners)
				obj->onEvent(e);
		}
	}

	void EventManager::addListener(std::unique_ptr<GameObject> object)
	{
		listeners.emplace_back(std::move(object));
	}
}