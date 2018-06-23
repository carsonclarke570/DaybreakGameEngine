#include "mouse.h"

namespace thundersurge {

	namespace input {

		bool Mouse::m_buttons[MAX_BUTTONS];
		double Mouse::m_x, Mouse::m_y;

		void Mouse::init() {
			for (int i = 0; i < MAX_BUTTONS; i++) {
				m_buttons[i] = false;
			}
		}

		bool Mouse::isButtonPressed(unsigned int keycode) {
			// TODO: Log this
			if (keycode >= MAX_BUTTONS) {
				return false;
			}
			return m_buttons[keycode];
		}

		void Mouse::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
			m_buttons[button] = action != GLFW_RELEASE;
		}

		void Mouse::cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
			m_x = xpos;
			m_y = ypos;
		}

		void Mouse::getMousePosition(double &x, double &y) {
			x = m_x;
			y = m_y;
		}
	}
}