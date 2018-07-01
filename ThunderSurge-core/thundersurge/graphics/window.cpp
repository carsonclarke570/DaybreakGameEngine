#include "window.h"

namespace thundersurge {

	namespace graphics {

		const char* Window::m_title = "ThunderSurge Game";
		int Window::m_width = 960;
		int Window::m_height = 540;
		GLFWwindow* Window::m_window = NULL;

		void window_resize(GLFWwindow *window, int width, int height);

		void Window::create(const char *title, int width, int height) {
			m_title = title;
			m_width = width;
			m_height = height;

			if (!init()) {
				glfwTerminate();
			}
		}

		void Window::dispose() {
			glfwTerminate();
		}

		bool Window::init() {
			if (!glfwInit()) {
				std::cout << "Failed to initialize GLFW!" << std::endl;
				return false;
			}

			m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
			if (!m_window) {
				std::cout << "Failed to create GLFW window" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_window);
			glfwSetWindowSizeCallback(m_window, window_resize);
			glfwSetKeyCallback(m_window, Keyboard::key_callback);
			glfwSetMouseButtonCallback(m_window, Mouse::mouse_button_callback);
			glfwSetCursorPosCallback(m_window, Mouse::cursor_position_callback);
			glfwSwapInterval(0.0);

			if (glewInit() != GLEW_OK) {
				std::cout << "Failed to initialize GLEW!" << std::endl;
				return false;
			}
			std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

			glFrontFace(GL_CCW);
			glCullFace(GL_BACK);
			glEnable(GL_CULL_FACE);
			glEnable(GL_DEPTH_TEST);

			glEnable(GL_TEXTURE_2D);
			glEnable(GL_FRAMEBUFFER_SRGB);


			return true;
		}

		bool Window::closed() {
			return (glfwWindowShouldClose(m_window) == 1);
		}

		void Window::clear() {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update() {
			GLenum error = glGetError();
			if (error != GL_NO_ERROR) {
				std::cout << "OpenGL Error: " << error << std::endl;
			}

			glfwPollEvents();
			glfwSwapBuffers(m_window);
		}

		void window_resize(GLFWwindow *window, int width, int height) {
			glViewport(0, 0, width, height);
			Window::m_width = width;
			Window::m_height = height;
		}
	}
}