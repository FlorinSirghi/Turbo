#include "InputSystem.h"

#include <array>
#include <string>

namespace Turbo
{
	std::array<bool, 4> InputSystem::key_held_down = { false, false, false, false };
	std::array<bool, 2> InputSystem::mouse_held_down = { false, false };
	float InputSystem::mouse_xpos = 0.0f;
	float InputSystem::mouse_ypos = 0.0f;
	float InputSystem::mouse_x_offset = 0.0f;
	float InputSystem::mouse_y_offset = 0.0f;
	bool InputSystem::first_move = true;

	Vector2D InputSystem::last_mouse_left_click_positions = Vector2D::zero;
	Vector2D InputSystem::last_mouse_right_click_positions = Vector2D::zero;

	bool InputSystem::isKeyHoldDown(char key)
	{
		if (key == 'W')
		{
			return key_held_down[0];
		}
		if (key == 'A')
		{
			return key_held_down[1];
		}
		if (key == 'S')
		{
			return key_held_down[2];
		}
		if (key == 'D')
		{
			return key_held_down[3];
		}
	}
	
	void InputSystem::setKeyHoldDown(char key)
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

	void InputSystem::releaseKey(char key)
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

	std::string InputSystem::getAllHeldDown()
	{
		std::string res = "";
		if (key_held_down[0] == true)
		{
			res += "W";
		}
		if (key_held_down[1] == true)
		{
			res += "A";
		}
		if (key_held_down[2] == true)
		{
			res += "S";
		}
		if (key_held_down[3] == true)
		{
			res += "D";
		}

		return res;
	}


	bool InputSystem::isMouseButtonHoldDown(char button)
	{
		if (button == 'l')
		{
			return mouse_held_down[0];
		}
		if (button == 'r')
		{
			return mouse_held_down[1];
		}
	}

	void InputSystem::setMouseButtonHoldDown(char button)
	{
		if (button == 'l')
		{
			last_mouse_left_click_positions.x = mouse_xpos;
			last_mouse_left_click_positions.y = mouse_ypos;
			mouse_held_down[0] = true;
		}
		if (button == 'r')
		{
			last_mouse_right_click_positions.x = mouse_xpos;
			last_mouse_right_click_positions.y = mouse_ypos;
			mouse_held_down[1] = true;
		}
	}

	void InputSystem::releaseMouseButton(char button)
	{
		if (button == 'l')
		{
			mouse_held_down[0] = false;
		}
		if (button == 'r')
		{
			mouse_held_down[1] = false;
		}
	}

	void InputSystem::setMousePositions(float mxp, float myp)
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

	Vector2D InputSystem::getLastMouseLeftClickPositions()
	{
		return last_mouse_left_click_positions;
	}

	Vector2D InputSystem::getLastMouseRightClickPositions()
	{
		return last_mouse_right_click_positions;
	}

}
