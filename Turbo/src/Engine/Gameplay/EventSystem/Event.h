#ifndef ENGINE_GAMEPLAY_EVENTSYSTEM_EVENT_H_
#define ENGINE_GAMEPLAY_EVENTSYSTEM_EVENT_H_

#include "EventArg.h"

#include <string>
#include <stdint.h>
#include <vector>

namespace Turbo
{
	// Event Types

	constexpr std::string_view KEY_PRESS = "KEY_PRESS_";
	constexpr std::string_view MOUSE_CLICK = "MOUSE_CLICK_";
	constexpr std::string_view MOUSE_MOVEMENT = "MOUSE_MOVEMENT_";

	class Event
	{
	public:

		std::string type;

		uint32_t argCount;
		std::vector<EventArg<>> args;
	};

}

#endif// ENGINE_GAMEPLAY_EVENTSYSTEM_EVENT_H_