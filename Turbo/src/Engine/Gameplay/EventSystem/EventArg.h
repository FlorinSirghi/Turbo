#ifndef ENGINE_GAMEPLAY_EVENTSYSTEM_EVENTARG_H_
#define ENGINE_GAMEPLAY_EVENTSYSTEM_EVENTARG_H_

#include <string>

namespace Turbo 
{
	template<class T = std::string>
	class EventArg
	{
	public:

		T param;
	};
}

#endif // ENGINE_GAMEPLAY_EVENTSYSTEM_EVENTARG_H_


