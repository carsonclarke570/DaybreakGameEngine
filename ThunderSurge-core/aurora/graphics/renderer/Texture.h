#include <FreeImage.h>
#include <GL/glew.h>
#include <string>

#include "../../utils/ImageLoader.h"

#ifndef _TEXTURE_H_
#define _TEXTURE_H_

namespace aurora {

	namespace graphics {

		class Texture {
		private:
			GLuint m_id;
			GLsizei m_width, m_height;

			GLuint load(const std::string& filename);
		public:
			Texture(const std::string& filename);
			~Texture();

			void bind() const;
			void unbind() const;

			inline const unsigned int getWidth() const { return m_width; }
			inline const unsigned int getHeight() const { return m_height; }
		};
	}
}

#endif