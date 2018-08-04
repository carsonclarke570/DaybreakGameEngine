#include "PostFX.h"

namespace daybreak {

	namespace graphics {

		FrameBuffer* PostFX::m_framebuffer = NULL;
		Shader* PostFX::m_postfx = NULL;
		GLuint PostFX::m_vao;
		GLuint PostFX::m_tex;

		void PostFX::init() {
			float quadVertices[] = { 
				-1.0f,  1.0f,  0.0f, 1.0f,
				-1.0f, -1.0f,  0.0f, 0.0f,
				1.0f, -1.0f,  1.0f, 0.0f,

				-1.0f,  1.0f,  0.0f, 1.0f,
				1.0f, -1.0f,  1.0f, 0.0f,
				1.0f,  1.0f,  1.0f, 1.0f
			};

			GLuint vbo;
			glGenVertexArrays(1, &m_vao);
			glGenBuffers(1, &vbo);
			glBindVertexArray(m_vao);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));

			m_framebuffer = new FrameBuffer();
			m_framebuffer->bind();
			glGenTextures(1, &m_tex);
			m_framebuffer->attachTexture(m_tex, 0);
		}
			
		void PostFX::bind() {
			if (m_postfx) {
				m_framebuffer->bind();
				glEnable(GL_DEPTH_TEST);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			}
		}
			
		void PostFX::unbind() {
			if (m_postfx) {
				m_framebuffer->unbind();
				glDisable(GL_DEPTH_TEST);
				glClear(GL_COLOR_BUFFER_BIT);
			}
		}

		void PostFX::render() {
			if (m_postfx) {
				m_postfx->enable();
				glBindVertexArray(m_vao);
				glBindTexture(GL_TEXTURE_2D, m_tex);
				glDrawArrays(GL_TRIANGLES, 0, 6);
			}
		}
			
		void PostFX::setPostFX(Shader* postfx) {
			m_postfx = postfx;
		}
	}
}