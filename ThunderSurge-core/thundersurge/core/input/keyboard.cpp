#include "keyboard.h"

namespace thundersurge {

	namespace input {

		Keyboard::KEY_ACTION Keyboard::m_keys[MAX_KEYS];

		void Keyboard::init() {

			for (int i = 0; i < MAX_KEYS; i++) {
				m_keys[i] = KEY_ACTION::UNDEFINED;
			}
		}

		bool Keyboard::isKeyPressed(unsigned int keycode) {
			// TODO: Log this
			if (keycode >= MAX_KEYS) {
				return false;
			}
			return m_keys[keycode] == KEY_ACTION::PRESSED;
		}

		bool Keyboard::isKeyReleased(unsigned int keycode) {
			// TODO: Log this
			if (keycode >= MAX_KEYS) {
				return false;
			}
			return m_keys[keycode] == KEY_ACTION::RELEASED;
		}

		bool Keyboard::isKeyDown(unsigned int keycode) {
			// TODO: Log this
			if (keycode >= MAX_KEYS) {
				return false;
			}
			return m_keys[keycode] == KEY_ACTION::HELD;
		}

		void Keyboard::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			if (action == GLFW_PRESS) {
				m_keys[key] = KEY_ACTION::PRESSED;
			}
			else if (action == GLFW_RELEASE) {
				m_keys[key] = KEY_ACTION::RELEASED;
			}
			else if (action == GLFW_REPEAT) {
				m_keys[key] = KEY_ACTION::HELD;
			}
			else {
				m_keys[key] = KEY_ACTION::UNDEFINED;
			}
		}
	}
}