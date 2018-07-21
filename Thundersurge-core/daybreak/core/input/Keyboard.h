#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../../utils/Log.h"

#define MAX_KEYS 1024

#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#define UP 0
#define DOWN 1

namespace daybreak {

	namespace input {

		class Keyboard {
		private:
			static char m_keys[MAX_KEYS];
			static char m_prevKeys[MAX_KEYS];
		public:
			static void init();
			static bool isKeyPressed(unsigned int keycode);
			static bool isKeyReleased(unsigned int keycode);
			static bool isKeyDown(unsigned int keycode);

			static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		};
	}
}

#endif