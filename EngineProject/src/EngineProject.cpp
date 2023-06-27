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
		while (true)
		{
			std::cout << "hatz\n";
		}
	}
};

Turbo::Application* getApplication()
{
	return new MyApplication();
}


