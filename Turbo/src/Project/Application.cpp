#include "Application.h"


namespace Turbo 
{
	void Application::run()
	{
		this->start();

		while (true)
			this->update();
	}
}