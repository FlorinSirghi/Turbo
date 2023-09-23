#pragma once

#include "Application.h"

Turbo::Application* getApplication();

int main()
{
	Turbo::Application* app = getApplication();
	app->run();
	delete app;

	return 0;
}