#include "OrthographicCamera.h"
#include <iostream>

namespace Turbo
{

	OrthographicCamera::OrthographicCamera()
	{
			
	}

	void OrthographicCamera::onEvent(Event event)
	{
		std::cout << event.type << event.args[0].param << ' '  << '\n';
	}

	void OrthographicCamera::update()
	{
		
	}
}