#include "SpriteRenderer.h"

namespace daybreak {

	namespace graphics {

		SpriteRenderer::SpriteRenderer() {
			init();
		}
	
		SpriteRenderer::~SpriteRenderer() {
			glDeleteVertexArrays(1, &m_vao);
		}
	
		void SpriteRenderer::render(Texture* texture, Shader* shader, Transform* transform) {
			shader->enable();

			// Design a method of making this more generic
			mat4 model = transform->getTransform();
			shader->setUniformMat4("model", model);

			glActiveTexture(GL_TEXTURE0);
			
			texture->bind();
			glBindVertexArray(m_vao);
			glDrawArrays(GL_TRIANGLES, 0, 6);
			glBindVertexArray(0);
			texture->unbind();

			shader->disable();
		}

		void SpriteRenderer::init() {
			GLuint vbo;
			GLfloat vertices[] = {
				0.0f, 1.0f, 0.0f, 1.0f,
				1.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f,

				0.0f, 1.0f, 0.0f, 1.0f,
				1.0f, 1.0f, 1.0f, 1.0f,
				1.0f, 0.0f, 1.0f, 0.0f
			};

			glGenVertexArrays(1, &m_vao);
			glGenBuffers(1, &vbo);

			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glBindVertexArray(m_vao);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
		}
	}
}