#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../core/input/input.h"
#include "../utils/Log.h"

#ifndef _WINDOW_H_
#define _WINDOW_H_

namespace thundersurge {
	
	namespace graphics {
		
		using namespace input;

		class Window {
		private:
			const static char *m_title;
			static int m_width, m_height;
			static GLFWwindow *m_window;

			static bool init();

			friend void window_resize(GLFWwindow* window, int width, int height);
		public:
			static void create(const char *title, int width, int height);
			static void dispose();
			static void clear();
			static bool closed();
			static void update();

			static inline int getWidth() { return m_width; }
			static inline int getHeight() { return m_height; }
			static inline GLFWwindow* getWindow() { return m_window; }
		};
	}
}

#endif