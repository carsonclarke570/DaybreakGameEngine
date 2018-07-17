#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <map>

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
			std::map<const GLchar*, GLuint> m_uniforms;
			const char* m_ver;
			const char* m_frag;

			GLuint load();
			GLint getUniformLocation(const GLchar* name);
		public:
			Shader(const char* ver, const char* frag);
			~Shader();

			virtual void update(Transform* transform, Material& material) = 0;

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