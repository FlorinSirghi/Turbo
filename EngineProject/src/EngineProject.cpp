#include "Project/Turbo.h"
#include <iostream>

class MyApplication : public Turbo::Application
{
public:

	void start() override
	{
		
	}

	void update() override
	{

	}
};

Turbo::Application* getApplication()
{
	return new MyApplication();
}


