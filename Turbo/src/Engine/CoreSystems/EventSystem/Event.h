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

		std::string type;

		uint32_t argCount;
		std::vector<EventArg<>> args;
	};

}