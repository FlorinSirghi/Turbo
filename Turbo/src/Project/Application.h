#pragma once

#include "../Engine/Main/Definitions.h"
// Application to be defined in project

namespace Turbo 
{
	class TURBO_API Application
	{
	public:
		void run();

	protected:

		virtual void start() = 0;
		virtual void update() = 0;
	};
}
