#pragma once

#include <GL/glew.h>

namespace thundersurge {

	namespace graphics {

		class IndexBuffer {
		private:
			GLuint m_bufferID;
			GLuint m_count;
		public:
			IndexBuffer(GLushort* data, GLsizei count);
			IndexBuffer(GLuint* data, GLsizei count);
			~IndexBuffer();

			void bind() const;
			void unbind() const;

			inline GLuint getCount() const { return m_count; }
			inline GLuint getBuffer() const { return m_bufferID; }
		};
	}
}

