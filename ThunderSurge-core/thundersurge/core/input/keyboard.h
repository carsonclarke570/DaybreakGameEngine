#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace thundersurge {

	namespace input {

#define MAX_KEYS 1024

		class Keyboard {
		private:
			static enum KEY_ACTION {
				UNDEFINED,
				PRESSED,
				RELEASED,
				HELD
			};

			static KEY_ACTION m_keys[MAX_KEYS];
		public:
			static void init();
			static bool isKeyPressed(unsigned int keycode);
			static bool isKeyReleased(unsigned int keycode);
			static bool isKeyDown(unsigned int keycode);

			static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		};
	}
}