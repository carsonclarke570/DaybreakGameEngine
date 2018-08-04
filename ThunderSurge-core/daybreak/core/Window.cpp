#include "window.h"

namespace daybreak {

	namespace core {

		void GLAPIENTRY
			MessageCallback(GLenum source,
				GLenum type,
				GLuint id,
				GLenum severity,
				GLsizei length,
				const GLchar* message,
				const void* userParam);

		const char* Window::m_title = "Daybreak";
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
			Log::log("Initializing window...");
			if (!glfwInit()) {
				Log::logErr("Failed to initialize GLFW");
				return false;
			}
			Log::logOk("Initialized GLFW");

			m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
			if (!m_window) {
				Log::logErr("Failed to create GLFW window");
				return false;
			}
			Log::logOk("Created GLFW window");

			glfwMakeContextCurrent(m_window);
			glfwSetWindowSizeCallback(m_window, window_resize);
			glfwSetKeyCallback(m_window, Keyboard::key_callback);
			glfwSetMouseButtonCallback(m_window, Mouse::mouse_button_callback);
			glfwSetCursorPosCallback(m_window, Mouse::cursor_position_callback);
			glfwSwapInterval(0.0);

			if (glewInit() != GLEW_OK) {
				Log::logErr("Failed to initialize GLEW!");
				return false;
			}
			Log::logOk("Initialized GLEW");
			std::string message = "OpenGL " + std::string((char*)glGetString(GL_VERSION));
			Log::log(message.c_str());

			glFrontFace(GL_CCW);
			glCullFace(GL_BACK);
			glEnable(GL_CULL_FACE);
			glEnable(GL_DEPTH_TEST);

			glEnable(GL_TEXTURE_2D);
			glEnable(GL_FRAMEBUFFER_SRGB);

			// During init, enable debug output
			glEnable(GL_DEBUG_OUTPUT);
			glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
			glDebugMessageCallback(MessageCallback, 0);

			return true;
		}



		void APIENTRY MessageCallback(GLenum source,
			
			GLenum type,
			GLuint id,
			GLenum severity,
			GLsizei length,
			const GLchar* message,
			const void* userParam) {

			Log::logErr("OpenGL Error");
			std::cout << "message: " << message << std::endl;
			std::cout << "type: ";
			switch (type) {
			case GL_DEBUG_TYPE_ERROR:
				std::cout << "ERROR";
				break;
			case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
				std::cout << "DEPRECATED_BEHAVIOR";
				break;
			case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
				std::cout << "UNDEFINED_BEHAVIOR";
				break;
			case GL_DEBUG_TYPE_PORTABILITY:
				std::cout << "PORTABILITY";
				break;
			case GL_DEBUG_TYPE_PERFORMANCE:
				std::cout << "PERFORMANCE";
				break;
			case GL_DEBUG_TYPE_OTHER:
				std::cout << "OTHER";
				break;
			}
			std::cout << std::endl;

			std::cout << "id: " << id << std::endl;
			std::cout << "severity: ";
			switch (severity) {
			case GL_DEBUG_SEVERITY_LOW:
				std::cout << "LOW";
				break;
			case GL_DEBUG_SEVERITY_MEDIUM:
				std::cout << "MEDIUM";
				break;
			case GL_DEBUG_SEVERITY_HIGH:
				std::cout << "HIGH";
				break;
			}
			std::cout << std::endl;
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

			glfwSwapBuffers(m_window);
			glfwPollEvents();
		}

		void window_resize(GLFWwindow *window, int width, int height) {
			glViewport(0, 0, width, height);
			Window::m_width = width;
			Window::m_height = height;
		}
	}
}