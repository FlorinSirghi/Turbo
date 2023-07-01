#pragma once

#include "EventArg.h"

#include <string>
#include <stdint.h>
#include <vector>

namespace Turbo
{
	class Event
	{
	public:

		std::string event_type;

		uint32_t argCount;
		std::vector<EventArg<>> eventArgs;
	};

}