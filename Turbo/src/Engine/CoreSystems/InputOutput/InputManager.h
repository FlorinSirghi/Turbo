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

		static bool isMouseButtonHoldDown(char button);
		static void setMouseButtonHoldDown(char button);
		static void releaseMouseButton(char button);

		static void setMousePositions(float mxp, float myp);
		static float getMouseXPos() { return mouse_xpos; }
		static float getMouseYPos() { return mouse_ypos; }

	private:
		static std::array<bool, 4> key_held_down;
		static std::array<bool, 2> mouse_held_down;

		static float mouse_xpos, mouse_ypos;
	};

}

