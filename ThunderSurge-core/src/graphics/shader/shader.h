#pragma once

#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <map>

#include "../../math/math.h"
#include "../../utils/fileutils.h"

namespace thundersurge {

	namespace graphics {

		class Shader {
		private:
			GLuint m_shader;
			std::map<const GLchar*, GLint> m_uniforms;
			const char* m_ver;
			const char* m_frag;

			GLuint load();
			GLint getUniformLocation(const GLchar* name);
		public:
			Shader(const char* ver, const char* frag);
			~Shader();


			void setUniform1f(const GLchar* name, float f);
			void setUniform1i(const GLchar* name, int i);
			void setUniform2f(const GLchar* name, const math::vec2& v);
			void setUniform3f(const GLchar* name, const math::vec3& v);
			void setUniform4f(const GLchar* name, const math::vec4& v);
			void setUniformMat4(const GLchar* name, const math::mat4& m);

			void enable() const;
			void disable() const;
		};
	}
}