#include "../core/math/math.h"
#include "Texture.h"

#ifndef _MATERIAL_H_
#define _MATERIAL_H_

namespace daybreak {

	namespace graphics {

		using namespace math;

		class Material {
		private:
			Texture m_diffuse;
			Texture m_specular;
			float m_specPow;
		public:
			Material(const Texture& diffuse, const Texture& specular, float specPow)
				: m_diffuse(diffuse), m_specular(specular), m_specPow(specPow) {
			}

			Material(const Texture& diffuse, const Texture& specular)
				: m_diffuse(diffuse), m_specular(specular), m_specPow(32) {
			}

			Material(const Texture& diffuse) 
				: m_diffuse(diffuse), m_specular(Texture("daybreak/res/defaults/no_spec_map.jpg")), m_specPow(32) {
			}

			Material() 
				: m_diffuse(Texture("daybreak/res/defaults/no_diffuse_map.jpg")), m_specular(Texture("daybreak/res/defaults/no_spec_map.jpg")), m_specPow(32) {
			}

			void bind() {
				glActiveTexture(GL_TEXTURE0);
				m_diffuse.bind();
				glActiveTexture(GL_TEXTURE1);
				m_specular.bind();
			}

			void unbind() {
				glActiveTexture(GL_TEXTURE0);
				m_diffuse.unbind();
				m_specular.unbind();
			}

			inline float getSpecularPower() const { return m_specPow; }
		};
	}
}

#endif