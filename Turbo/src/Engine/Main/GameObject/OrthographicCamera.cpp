#include "OrthographicCamera.h"
#include <iostream>

namespace Turbo
{

	void OrthographicCamera::onEvent(Event event)
	{
		std::cout << event.event_type << '\n';
	}

	void OrthographicCamera::update()
	{

	}
}