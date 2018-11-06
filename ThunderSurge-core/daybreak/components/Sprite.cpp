#include "Sprite.h"

namespace daybreak {

	namespace components {
		
		Sprite::Sprite(Texture* texture, Shader* shader) {
			m_texture = texture;
			m_shader = shader;
			m_renderer = new SpriteRenderer();
		}
		
		Sprite::~Sprite() {
			delete m_renderer;
		}
		
		void Sprite::update(float delta) {}
		
		void Sprite::render(Shader* shader) {
			m_renderer->render(m_texture, m_shader, getTransform());
		}
		
		void Sprite::setTexture(Texture* texture) {
			m_texture = texture;
		}
	}
}