#include "Project/Turbo.h"
#include <iostream>

class MyApplication : public Turbo::Application
{
public:

	void start()
	{
		
	}

	void update()
	{

	}
};

Turbo::Application* getApplication()
{
	return new MyApplication();
}


