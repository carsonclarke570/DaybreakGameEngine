#pragma once

#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace thundersurge {

	namespace input {

#define MAX_BUTTONS 32

		class Mouse {
		private:
			static bool m_buttons[MAX_BUTTONS];
			static double m_x, m_y;
		public:
			static void init();
			static bool isButtonPressed(unsigned int keycode);
			static void getMousePosition(double &x, double &y);

			static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		};
	}
}