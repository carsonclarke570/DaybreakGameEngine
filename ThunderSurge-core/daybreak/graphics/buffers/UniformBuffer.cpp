#include "UniformBuffer.h"

namespace daybreak {

	namespace graphics {

		UniformBuffer::UniformBuffer(unsigned int size, unsigned int bindingPort) {
			glGenBuffers(1, &m_ubo);

			glBindBuffer(GL_UNIFORM_BUFFER, m_ubo);
			glBufferData(GL_UNIFORM_BUFFER, size, NULL, GL_DYNAMIC_DRAW);
			glBindBuffer(GL_UNIFORM_BUFFER, m_ubo);

			glBindBufferRange(GL_UNIFORM_BUFFER, bindingPort, m_ubo, 0, size);
		}

		UniformBuffer::~UniformBuffer() {
			glDeleteBuffers(1, &m_ubo);
		}

		void UniformBuffer::setData(unsigned int offset, const mat4& data) {
			// TO-DO Error checking
			glBindBuffer(GL_UNIFORM_BUFFER, m_ubo);
			glBufferSubData(GL_UNIFORM_BUFFER, offset, sizeof(mat4), &data.m_m[0]);
			glBindBuffer(GL_UNIFORM_BUFFER, m_ubo);
		}

		void UniformBuffer::setData(unsigned int offset, const vec3& data) {
			// TO-DO Error checking
			float buf[3];
			buf[0] = data.m_x;
			buf[1] = data.m_y;
			buf[2] = data.m_z;
			glBindBuffer(GL_UNIFORM_BUFFER, m_ubo);
			glBufferSubData(GL_UNIFORM_BUFFER, offset, sizeof(vec3), &buf[0]);
			glBindBuffer(GL_UNIFORM_BUFFER, m_ubo);
		}
	}
}