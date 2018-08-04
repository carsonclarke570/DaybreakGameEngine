#include "FrameBuffer.h"

namespace daybreak {

	namespace graphics {

		using namespace core;

		FrameBuffer::FrameBuffer() {
			init();
		}

		void FrameBuffer::init() {
			// Create FrameBuffer

			glGenFramebuffers(1, &m_fbo);
			glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);

			// Create a Render Buffer for Depth and Stencil
			glGenRenderbuffers(1, &m_rbo);
			glBindRenderbuffer(GL_RENDERBUFFER, m_rbo);
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, Window::getWidth(), Window::getHeight()); 
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_rbo); 
			
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
		}

		FrameBuffer::~FrameBuffer() {
		
		}

		void FrameBuffer::bind() {
			if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
				Log::logErr("Framebuffer is not complete!");

			glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);
		}

		void FrameBuffer::unbind() {
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
		}

		void FrameBuffer::attachTexture(GLuint texture, GLuint index) {
			glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);
			glBindTexture(GL_TEXTURE_2D, texture);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Window::getWidth(), Window::getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glBindTexture(GL_TEXTURE_2D, texture);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + index, GL_TEXTURE_2D, texture, 0);
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
		}
	}
}