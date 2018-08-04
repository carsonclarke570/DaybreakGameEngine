#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <unordered_map>

#include "../core/math/math.h"
#include "../core/Transform.h"

#include "../utils/fileutils.h"

#include "Material.h"

#ifndef _SHADER_H_
#define _SHADER_H_

namespace daybreak {

	using namespace math;
	using namespace core;

	namespace graphics {

		class Shader {
		private:
			GLuint m_shader;
			std::unordered_map<std::string, GLint> m_uniforms;
			const char* m_ver;
			const char* m_frag;
			const char* m_geo;

			GLuint load();
		public:
			Shader(const char* ver, const char* frag, const char* geom);
			~Shader();

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

#endif