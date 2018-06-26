#include "SimpleRenderer2D.h"

namespace thundersurge {

	namespace graphics {

		void SimpleRenderer2D::submit(const Renderable2D* renderable) {
			m_renderQueue.push_back((StaticSprite*)renderable);
		}

		void SimpleRenderer2D::flush() {
			while (!m_renderQueue.empty()) {
				const StaticSprite* sprite = m_renderQueue.front();
				sprite->getVAO()->bind();
				sprite->getIBO()->bind();

				sprite->getShader().setUniformMat4("ml_mat", math::mat4::translation(sprite->getPosition()));
				glDrawElements(GL_TRIANGLES, sprite->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr);

				sprite->getIBO()->unbind();
				sprite->getVAO()->unbind();

				m_renderQueue.pop_front();
			}
		}
	}
}