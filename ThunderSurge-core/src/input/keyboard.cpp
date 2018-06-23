#include "keyboard.h"

namespace thundersurge {

	namespace input {

		bool Keyboard::m_keys[MAX_KEYS];

		void Keyboard::init() {

			for (int i = 0; i < MAX_KEYS; i++) {
				m_keys[i] = false;
			}
		}

		bool Keyboard::isKeyPressed(unsigned int keycode) {
			// TODO: Log this
			if (keycode >= MAX_KEYS) {
				return false;
			}
			return m_keys[keycode];
		}

		void Keyboard::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			m_keys[key] = action != GLFW_RELEASE;
		}
	}
}