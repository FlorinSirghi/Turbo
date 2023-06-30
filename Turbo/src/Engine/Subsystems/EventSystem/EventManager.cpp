#include "EventManager.h"

namespace Turbo
{
	void EventManager::postEvent(const Event& event)
	{
		events.push_back(event);
	}

	void EventManager::pollEvent()
	{
		events.pop();
	}

	void EventManager::addListener(const GameObject& object)
	{
		listeners.emplace_back(object);
	}
}