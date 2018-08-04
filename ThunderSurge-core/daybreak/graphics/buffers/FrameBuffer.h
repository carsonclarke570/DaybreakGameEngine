#ifndef _FRAME_BUFFER_H_
#define _FRAME_BUFFER_H_

#include <GL/glew.h>
#include "../../core/Window.h"

namespace daybreak {

	namespace graphics {
		
		class FrameBuffer {
		private:
			GLuint m_fbo, m_rbo;

			void init();
		public:
			FrameBuffer();
			~FrameBuffer();
			
			void bind();
			void unbind();
			void attachTexture(GLuint texture, GLuint index);
		};
	}
}

#endif
