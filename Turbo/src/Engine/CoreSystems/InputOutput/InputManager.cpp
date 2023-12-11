#include "InputManager.h"

namespace Turbo
{
	std::array<bool, 4> InputManager::key_held_down = { false, false, false, false };
	std::array<bool, 2> InputManager::mouse_held_down = { false, false };
	float InputManager::mouse_xpos = 0.0f;
	float InputManager::mouse_ypos = 0.0f;
	float InputManager::mouse_x_offset = 0.0f;
	float InputManager::mouse_y_offset = 0.0f;
	bool InputManager::first_move = true;

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


	bool InputManager::isMouseButtonHoldDown(char button)
	{
		if (button == 'l')
			return mouse_held_down[0];
		if (button == 'r')
			return mouse_held_down[1];
	}

	void InputManager::setMouseButtonHoldDown(char button)
	{
		if (button == 'l')
			mouse_held_down[0] = true;
		if (button == 'r')
			mouse_held_down[1] = true;
	}

	void InputManager::releaseMouseButton(char button)
	{
		if (button == 'l')
			mouse_held_down[0] = false;
		if (button == 'r')
			mouse_held_down[1] = false;
	}

	void InputManager::setMousePositions(float mxp, float myp)
	{
		if(first_move)
		{
			mouse_x_offset = mxp;
			mouse_y_offset = myp;

			first_move = false;
		}
		else
		{
			mouse_x_offset = mxp - mouse_xpos;
			mouse_y_offset = mouse_ypos - myp;
		}

		mouse_xpos = mxp;
		mouse_ypos = myp;
	}

}
