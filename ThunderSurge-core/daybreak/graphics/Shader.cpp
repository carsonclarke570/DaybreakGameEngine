#include "shader.h"

namespace daybreak {

	namespace graphics {

		Shader::Shader(const char* ver, const char* frag, const char* geom, const bool enableDaySL) : m_enableDaySL(enableDaySL) {
			m_shader = glCreateProgram();
			addVertexShader(ver);
			addFragmentShader(frag);
			if (geom)
				addGeometryShader(geom);

			glLinkProgram(m_shader);
			glValidateProgram(m_shader);
		}

		Shader::~Shader() {
			glDeleteProgram(m_shader);
		}

		void Shader::addVertexShader(const char* ver) {
			GLint result;
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			std::string verSrcStr = FileUtils::read_file(ver);
			const char* verSrc = verSrcStr.c_str();
			if (m_enableDaySL) {
				std::string header = FileUtils::read_file("daybreak/graphics/shaders/vertex-header.txt");
				std::string trailer = FileUtils::read_file("daybreak/graphics/shaders/vertex-trailer.txt");
				const char* src[3] = { header.c_str(), verSrc, trailer.c_str() };
				glShaderSource(vertex, 3, src, NULL);
			} else {
				glShaderSource(vertex, 1, &verSrc, NULL);
			}
			glCompileShader(vertex);

			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE) {
				GLint len;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &len);
				std::vector<char> error(len);
				glGetShaderInfoLog(vertex, len, &len, &error[0]);
				std::cout << &error[0] << std::endl;
				glDeleteShader(vertex);
				return;
			}
			glAttachShader(m_shader, vertex);
			glDeleteShader(vertex);
		}

		void Shader::addFragmentShader(const char* frg) {
			GLint result;
			GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);
			std::string fragSrcStr = FileUtils::read_file(frg);
			const char* fragSrc = fragSrcStr.c_str();
			if (m_enableDaySL) {
				std::string header = FileUtils::read_file("daybreak/graphics/shaders/fragment-header.txt");
				std::string trailer = FileUtils::read_file("daybreak/graphics/shaders/fragment-trailer.txt");
				const char* src[3] = { header.c_str(), fragSrc, trailer.c_str() };
				glShaderSource(frag, 3, src, NULL);
			}
			else {
				glShaderSource(frag, 1, &fragSrc, NULL);
			}
			glCompileShader(frag);

			glGetShaderiv(frag, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE) {
				GLint len;
				glGetShaderiv(frag, GL_INFO_LOG_LENGTH, &len);
				std::vector<char> error(len);
				glGetShaderInfoLog(frag, len, &len, &error[0]);
				// TODO: Log error
				std::cout << &error[0] << std::endl;
				glDeleteShader(frag);
				return;
			}
			glAttachShader(m_shader, frag);
			glDeleteShader(frag);
		}

		void Shader::addGeometryShader(const char* geom) {
			GLint result;
			GLuint geo = glCreateShader(GL_GEOMETRY_SHADER);
			std::string geoSrcStr = FileUtils::read_file(geom);
			const char* geoSrc = geoSrcStr.c_str();
			if (m_enableDaySL) {
				std::string header = FileUtils::read_file("daybreak/graphics/shaders/geometry-header.txt");
				std::string trailer = FileUtils::read_file("daybreak/graphics/shaders/geometry-trailer.txt");
				const char* src[3] = { header.c_str(), geoSrc, trailer.c_str() };
				glShaderSource(geo, 3, src, NULL);
			}
			else {
				glShaderSource(geo, 1, &geoSrc, NULL);
			}
			glCompileShader(geo);

			glGetShaderiv(geo, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE) {
				GLint len;
				glGetShaderiv(geo, GL_INFO_LOG_LENGTH, &len);
				std::vector<char> error(len);
				glGetShaderInfoLog(geo, len, &len, &error[0]);
				// TODO: Log error
				std::cout << &error[0] << std::endl;
				glDeleteShader(geo);
				return;
			}
			glAttachShader(m_shader, geo);
			glDeleteShader(geo);
		}


		void Shader::setUniform1f(const GLchar* name, float f) {
			glUniform1f(glGetUniformLocation(m_shader, name), f);
		}

		void Shader::setUniform1i(const GLchar* name, int i) {
			glUniform1i(glGetUniformLocation(m_shader, name), i);
		}

		void Shader::setUniform2f(const GLchar* name, const math::vec2& v) {
			glUniform2f(glGetUniformLocation(m_shader, name), v.m_x, v.m_y);
		}

		void Shader::setUniform3f(const GLchar* name, const math::vec3& v) {
			glUniform3f(glGetUniformLocation(m_shader, name), v.m_x, v.m_y, v.m_z);
		}

		void Shader::setUniform4f(const GLchar* name, const math::vec4& v) {
			glUniform4f(glGetUniformLocation(m_shader, name), v.m_x, v.m_y, v.m_z, v.m_w);
		}

		void Shader::setUniformMat4(const GLchar* name, const math::mat4& m) {
			glUniformMatrix4fv(glGetUniformLocation(m_shader, name), 1, GL_FALSE, m.elements);
		}

		void Shader::enable() const {
			glUseProgram(m_shader);
		}

		void Shader::disable() const {
			glUseProgram(0);
		}
	}
}