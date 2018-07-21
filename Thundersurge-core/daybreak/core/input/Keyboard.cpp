#include "keyboard.h"

namespace daybreak {

	namespace input {

		char Keyboard::m_keys[MAX_KEYS];
		char Keyboard::m_prevKeys[MAX_KEYS];

		void Keyboard::init() {

			for (int i = 0; i < MAX_KEYS; i++) {
				m_keys[i] = UP;
				m_prevKeys[i] = UP;
			}
		}

		bool Keyboard::isKeyPressed(unsigned int keycode) {
			if (keycode >= MAX_KEYS) {
				return false;
			}
			return m_keys[keycode] == DOWN && m_prevKeys[keycode] == UP;
		}

		bool Keyboard::isKeyReleased(unsigned int keycode) {
			if (keycode >= MAX_KEYS) {
				return false;
			}
			return m_keys[keycode] == UP && m_prevKeys[keycode] != DOWN;
		}

		bool Keyboard::isKeyDown(unsigned int keycode) {
			
			if (keycode >= MAX_KEYS) {
				return false;
			}
			return m_keys[keycode] == DOWN;
		}

		void Keyboard::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			m_prevKeys[key] = m_keys[key];
			if (action == GLFW_PRESS) {
				const char* key_name = glfwGetKeyName(key, 0);
				char message[sizeof(key_name) + 12];
				sprintf(message, "Pressed: %s", key_name);
				Log::log(message);
				m_keys[key] = DOWN;
			}
			else if (action == GLFW_RELEASE) {
				m_keys[key] = UP;
			}
		}
	}
}