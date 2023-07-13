#pragma once

#include <array>
#include <string>

namespace Turbo
{

	class InputManager
	{

	public:

		static bool isKeyHoldDown(char key);
		static void setKeyHoldDown(char key);
		static void releaseKey(char key);
		static std::string getAllHeldDown();

	private:
		static std::array<bool, 4> key_held_down;
	};

}

