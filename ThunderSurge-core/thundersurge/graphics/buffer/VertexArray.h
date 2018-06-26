#pragma once

#include <vector>
#include <GL/glew.h>

#include "buffer.h"

namespace thundersurge {

	namespace graphics {
	
		class VertexArray {
		private:
			GLuint m_arrayID;
			std::vector<Buffer*> m_buffers;
		public:
			VertexArray();
			~VertexArray();

			void addBuffer(Buffer* buffer, GLuint index);
			void bind() const;
			void unbind() const;
			void render(unsigned int count) const;
		};
	}
}