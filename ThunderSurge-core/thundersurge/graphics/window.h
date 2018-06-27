#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../core/input/input.h"

namespace thundersurge {
	
	namespace graphics {
		
		using namespace input;

		class Window {
		private:
			const char *m_title;
			int m_width, m_height;
			GLFWwindow *m_window;

			bool init();

			friend void window_resize(GLFWwindow* window, int width, int height);
		public:
			Window(const char *title, int width, int height);
			~Window();
			void clear() const;
			bool closed() const;
			void update();

			inline int getWidth() const { return m_width; }
			inline int getHeight() const { return m_height; }
		};
	}
}