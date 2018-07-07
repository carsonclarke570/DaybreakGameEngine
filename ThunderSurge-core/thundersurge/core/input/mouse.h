#include "../../graphics/window.h"
#include "../math/math.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define MAX_BUTTONS 32

#ifndef _MOUSE_H_
#define _MOUSE_H_

namespace thundersurge {

	namespace input {

		class Mouse {
		private:
			static enum class MOUSE_ACTION {
				UNDEFINED,
				PRESSED,
				RELEASED,
				HELD
			};

			static MOUSE_ACTION m_buttons[MAX_BUTTONS];
			static double m_x, m_y;
		public:
			static void init();
			static bool isButtonPressed(unsigned int keycode);
			static bool isButtonReleased(unsigned int keycode);
			static bool isButtonDown(unsigned int keycode);

			static void getMousePosition(math::vec2& pos);
			static void setMousePosition(double x, double y);

			static void hideCursor();
			static void showCursor();

			static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		};
	}
}

#endif