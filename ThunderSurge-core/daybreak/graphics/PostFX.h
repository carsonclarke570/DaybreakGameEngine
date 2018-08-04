#ifndef _POST_FX_H_
#define _POST_FX_H_

#include "buffers/FrameBuffer.h"

#include "../graphics/Shader.h"

namespace daybreak {

	namespace graphics {

		class PostFX {
		private:
			static FrameBuffer* m_framebuffer;
			static GLuint m_vao, m_tex;
			static Shader* m_postfx;
		public:
			static void init();
			static void bind();
			static void unbind();
			static void render();
			static void setPostFX(Shader* postfx);
		};
	}
}

#endif