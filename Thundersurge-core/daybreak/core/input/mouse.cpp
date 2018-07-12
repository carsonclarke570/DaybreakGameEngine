#include "mouse.h"

namespace daybreak {

	namespace input {

		Mouse::MOUSE_ACTION Mouse::m_buttons[MAX_BUTTONS];
		double Mouse::m_x, Mouse::m_y;

		void Mouse::init() {
			for (int i = 0; i < MAX_BUTTONS; i++) {
				m_buttons[i] = MOUSE_ACTION::UNDEFINED;
			}
		}

		bool Mouse::isButtonDown(unsigned int keycode) {
			// TODO: Log this
			if (keycode >= MAX_BUTTONS) {
				return false;
			}
			return m_buttons[keycode] == MOUSE_ACTION::HELD;
		}

		bool Mouse::isButtonPressed(unsigned int keycode) {
			// TODO: Log this
			if (keycode >= MAX_BUTTONS) {
				return false;
			}
			return m_buttons[keycode] == MOUSE_ACTION::PRESSED;
		}

		bool Mouse::isButtonReleased(unsigned int keycode) {
			// TODO: Log this
			if (keycode >= MAX_BUTTONS) {
				return false;
			}
			return m_buttons[keycode] == MOUSE_ACTION::RELEASED;
		}

		void Mouse::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
			if (action == GLFW_PRESS) {
				m_buttons[button] = MOUSE_ACTION::PRESSED;
			} 
			else if (action == GLFW_RELEASE) {
				m_buttons[button] = MOUSE_ACTION::RELEASED;
			}
			else if (action == GLFW_REPEAT) {
				m_buttons[button] = MOUSE_ACTION::HELD;
			}
			else {
				m_buttons[button] = MOUSE_ACTION::UNDEFINED;
			}
		}

		void Mouse::cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
			m_x = xpos;
			m_y = ypos;
		}

		void Mouse::getMousePosition(math::vec2& pos) {
			pos.m_x = m_x;
			pos.m_y = m_y;
		}

		void Mouse::setMousePosition(double x, double y) {
			using namespace daybreak::graphics;
			glfwSetCursorPos(Window::getWindow(), x, y);
		}

		void Mouse::hideCursor() {
			using namespace daybreak::graphics;
			glfwSetInputMode(Window::getWindow(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
		}

		void Mouse::showCursor() {
			using namespace daybreak::graphics;
			glfwSetInputMode(Window::getWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}
	}
}