#pragma once

#include "EventArg.h"

#include <string>
#include <stdint.h>
#include <vector>

namespace Turbo
{
	// Event Types

	constexpr std::string_view KEY_PRESS = "KEY_PRESS_";
	constexpr std::string_view MOUSE_CLICK = "MOUSE_CLICK_";

	class Event
	{
	public:

		std::string type;

		uint32_t argCount;
		std::vector<EventArg<>> args;
	};

}