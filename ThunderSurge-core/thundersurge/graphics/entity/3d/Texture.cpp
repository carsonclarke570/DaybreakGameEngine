#include "Texture.h"

namespace thundersurge {

	namespace graphics {

		Texture::Texture(const std::string& filename) {
			m_id = load(filename);
		}

		Texture::~Texture() {

		}

		GLuint Texture::load(const std::string& filename) {
			BYTE* pixels = loadImage(filename.c_str(), &m_width, &m_height);

			GLuint result;
			glGenTextures(1, &result);
			glBindTexture(GL_TEXTURE_2D, result);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_BGR, GL_UNSIGNED_BYTE, pixels);
			glBindTexture(GL_TEXTURE_2D, 0);

			return result;
		}

		void Texture::bind() const {
			glBindTexture(GL_TEXTURE_2D, m_id);
		}

		void Texture::unbind() const {
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}
}