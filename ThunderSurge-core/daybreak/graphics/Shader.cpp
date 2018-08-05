#include "shader.h"

namespace daybreak {

	namespace graphics {

		Shader::Shader(const char* ver, const char* frag, const char* geom) : m_ver(ver), m_frag(frag), m_geo(geom) {
			m_shader = load();
		}

		Shader::~Shader() {
			glDeleteProgram(m_shader);
		}

		GLuint Shader::load() {
			GLuint program = glCreateProgram();

			GLint result;
			GLuint vertex, frag, geo;
			if (m_ver) {
				vertex = glCreateShader(GL_VERTEX_SHADER);
				std::string verSrcStr = FileUtils::read_file(m_ver);
				const char* verSrc = verSrcStr.c_str();
				glShaderSource(vertex, 1, &verSrc, NULL);
				glCompileShader(vertex);

				glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
				if (result == GL_FALSE) {
					GLint len;
					glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &len);
					std::vector<char> error(len);
					glGetShaderInfoLog(vertex, len, &len, &error[0]);
					std::cout << &error[0] << std::endl;
					glDeleteShader(vertex);
					return 0;
				}
				glAttachShader(program, vertex);
				glDeleteShader(vertex);
			}

			if (m_frag) {
				frag = glCreateShader(GL_FRAGMENT_SHADER);
				std::string fragSrcStr = FileUtils::read_file(m_frag);
				const char* fragSrc = fragSrcStr.c_str();
				glShaderSource(frag, 1, &fragSrc, NULL);
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
					return 0;
				}
				glAttachShader(program, frag);
				glDeleteShader(frag);
			}

			if (m_geo) {
				geo = glCreateShader(GL_GEOMETRY_SHADER);
				std::string geoSrcStr = FileUtils::read_file(m_geo);
				const char* geoSrc = geoSrcStr.c_str();
				glShaderSource(geo, 1, &geoSrc, NULL);
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
					return 0;
				}
				glAttachShader(program, geo);
				glDeleteShader(geo);
			}

			glLinkProgram(program);
			glValidateProgram(program);

			/*GLint maxUniformNameLen, noOfUniforms;
			glGetProgramiv(program, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxUniformNameLen);
			glGetProgramiv(program, GL_ACTIVE_UNIFORMS, &noOfUniforms);

			GLint read, size;
			GLenum type;

			std::vector<GLchar>unifN(maxUniformNameLen, 0);
			for (GLint i = 0; i < noOfUniforms; ++i) {
				glGetActiveUniform(program, i, maxUniformNameLen, &read, &size, &type, unifN.data());
				m_uniforms[std::string(unifN.data())] = glGetUniformLocation(program, unifN.data());
			} 

			// If you wan to see active uniforms
			for (auto& t : m_uniforms)
				std::cout << t.first << " ";

			std::cout << std::endl;
			*/
			return program;
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
			glUniformMatrix4fv(glGetUniformLocation(m_shader, name), 1, GL_FALSE, m.m_m);
		}

		void Shader::enable() const {
			glUseProgram(m_shader);
		}

		void Shader::disable() const {
			glUseProgram(0);
		}
	}
}