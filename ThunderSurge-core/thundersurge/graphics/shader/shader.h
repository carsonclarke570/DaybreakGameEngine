#pragma once

#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <map>

#include "../../core/math/math.h"
#include "../../utils/fileutils.h"
#include "../renderer/Material.h"

namespace thundersurge {

	using namespace math;

	namespace graphics {

		class Shader {
		private:
			GLuint m_shader;
			std::map<const GLchar*, GLuint> m_uniforms;
			const char* m_ver;
			const char* m_frag;

			GLuint load();
			GLint getUniformLocation(const GLchar* name);
		public:
			Shader(const char* ver, const char* frag);
			~Shader();

			virtual void update(const mat4& world, const mat4& projection, const Material& material) = 0;

			void setUniform1f(const GLchar* name, float f);
			void setUniform1i(const GLchar* name, int i);
			void setUniform2f(const GLchar* name, const vec2& v);
			void setUniform3f(const GLchar* name, const vec3& v);
			void setUniform4f(const GLchar* name, const vec4& v);
			void setUniformMat4(const GLchar* name, const mat4& m);

			void enable() const;
			void disable() const;
		};
	}
}