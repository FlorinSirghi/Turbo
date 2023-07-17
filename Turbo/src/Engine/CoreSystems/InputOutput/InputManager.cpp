#include "InputManager.h"

namespace Turbo
{
	std::array<bool, 4> InputManager::key_held_down = {false, false, false, false};

	bool InputManager::isKeyHoldDown(char key)
	{
		if (key == 'W')
			return key_held_down[0];
		if (key == 'A')
			return key_held_down[1];
		if (key == 'S')
			return key_held_down[2];
		if (key == 'D')
			return key_held_down[3];
	}
	
	void InputManager::setKeyHoldDown(char key)
	{
		if (key == 'W')
			key_held_down[0] = true;
		if (key == 'A')
			key_held_down[1] = true;
		if (key == 'S')
			key_held_down[2] = true;
		if (key == 'D')
			key_held_down[3] = true;
	}

	void InputManager::releaseKey(char key)
	{
		if (key == 'W')
			key_held_down[0] = false;
		if (key == 'A')
			key_held_down[1] = false;
		if (key == 'S')
			key_held_down[2] = false;
		if (key == 'D')
			key_held_down[3] = false;
	}

	std::string InputManager::getAllHeldDown()
	{
		std::string res = "";
		if (key_held_down[0] == true)
			res += "W";
		if (key_held_down[1] == true)
			res += "A";
		if (key_held_down[2] == true)
			res += "S";
		if (key_held_down[3] == true)
			res += "D";

		return res;
	}

}