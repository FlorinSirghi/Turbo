#pragma once

#include "Event.h"
#include "../../GameObject/GameObject.h"

#include <queue>

namespace Turbo
{
	class EventManager
	{
	public:

		static void postEvent(const Event& event);

		static void pollEvent();

		static void addListener(const GameObject& object);

	private:

		static std::queue<Event> events;

		static std::vector<GameObject> listeners;
	};
}