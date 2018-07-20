#include "shader.h"

namespace daybreak {

	namespace graphics {

		Shader::Shader(const char* ver, const char* frag) : m_ver(ver), m_frag(frag) {
			m_shader = load();
		}

		Shader::~Shader() {
			glDeleteProgram(m_shader);
		}

		GLuint Shader::load() {
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);

			std::string verSrcStr = FileUtils::read_file(m_ver);
			std::string fragSrcStr = FileUtils::read_file(m_frag);
			const char* verSrc = verSrcStr.c_str();
			const char* fragSrc = fragSrcStr.c_str();

			glShaderSource(vertex, 1, &verSrc, NULL);
			glCompileShader(vertex);

			GLint result;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE) {
				GLint len;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &len);
				std::vector<char> error(len);
				glGetShaderInfoLog(vertex, len, &len, &error[0]);
				// TODO: Log error
				std::cout << &error[0] << std::endl;
				glDeleteShader(vertex);
				return 0;
			}

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

			glAttachShader(program, vertex);
			glAttachShader(program, frag);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(frag);

			GLint maxUniformNameLen, noOfUniforms;
			glGetProgramiv(program, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxUniformNameLen);
			glGetProgramiv(program, GL_ACTIVE_UNIFORMS, &noOfUniforms);

			GLint read, size;
			GLenum type;

			std::vector<GLchar>unifN(maxUniformNameLen, 0);
			for (GLint i = 0; i < noOfUniforms; ++i) {
				glGetActiveUniform(program, i, maxUniformNameLen, &read, &size, &type, unifN.data());
				m_uniforms[std::string(unifN.data())] = glGetUniformLocation(program, unifN.data());
			}

			return program;
		}


		void Shader::setUniform1f(const GLchar* name, float f) {
			glUniform1f(m_uniforms[name], f);
		}

		void Shader::setUniform1i(const GLchar* name, int i) {
			glUniform1i(m_uniforms[name], i);
		}

		void Shader::setUniform2f(const GLchar* name, const math::vec2& v) {
			glUniform2f(m_uniforms[name], v.m_x, v.m_y);
		}

		void Shader::setUniform3f(const GLchar* name, const math::vec3& v) {
			glUniform3f(m_uniforms[name], v.m_x, v.m_y, v.m_z);
		}

		void Shader::setUniform4f(const GLchar* name, const math::vec4& v) {
			glUniform4f(m_uniforms[name], v.m_x, v.m_y, v.m_z, v.m_w);
		}

		void Shader::setUniformMat4(const GLchar* name, const math::mat4& m) {
			glUniformMatrix4fv(m_uniforms[name], 1, GL_FALSE, m.m_m);
		}

		void Shader::enable() const {
			glUseProgram(m_shader);
		}

		void Shader::disable() const {
			glUseProgram(0);
		}
	}
}