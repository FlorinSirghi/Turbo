#include "OrtographicCamera.h"
#include <iostream>

namespace Turbo
{

	void OrtographicCamera::onEvent(Event event)
	{
		std::cout << event.event_type << '\n';
	}

	void OrtographicCamera::update()
	{

	}
}