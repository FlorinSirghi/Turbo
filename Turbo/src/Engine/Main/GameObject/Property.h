#pragma once

#include <string>

namespace Turbo
{
	class Property
	{
	public:

		std::string name;
		std::string value;

		virtual void effect() = 0;
	};
}