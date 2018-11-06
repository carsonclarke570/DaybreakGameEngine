#ifndef _UNIFORM_BUFFER_H_
#define _UNIFORM_BUFFER_H_

#include <GL/glew.h>

#include "../../core/Math.h"

namespace daybreak {

	namespace graphics {

		using namespace core;

		class UniformBuffer {
		private:
			GLuint m_ubo;
		public:
			UniformBuffer(unsigned int size, unsigned int bindingPort);
			~UniformBuffer();

			void setData(unsigned int offset, const mat4& data);
			void setData(unsigned int offset, const vec3& data);
		};
	}
}

#endif 

