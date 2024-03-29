#ifndef ENGINE_HIDENGINE_INPUTOUTPUT_INPUTMANAGER_H_
#define ENGINE_HIDENGINE_INPUTOUTPUT_INPUTMANAGER_H_

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

		static float getMouseXOffset() { return mouse_x_offset; }
		static float getMouseYOffset() { return mouse_y_offset; }

	private:
		static std::array<bool, 4> key_held_down;
		static std::array<bool, 2> mouse_held_down;

		static bool	first_move;

		static float mouse_xpos, mouse_ypos;
		static float mouse_x_offset, mouse_y_offset;
	};

}

#endif // ENGINE_HIDENGINE_INPUTOUTPUT_INPUTMANAGER_H_

