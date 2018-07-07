#pragma once


#include "../../core/math/math.h"
#include "Texture.h"

namespace thundersurge {

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
				: m_diffuse(diffuse), m_specular(Texture("thundersurge/res/defaults/no_spec_map.jpg")), m_specPow(32) {
			}

			inline Texture getDiffuseTexture() const { return m_diffuse; }
			inline Texture getSpeculartexture() const { return m_specular; }
			inline float getSpecularPower() const { return m_specPow; }
		};
	}
}