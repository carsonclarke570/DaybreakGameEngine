#pragma once


#include "../../core/math/math.h"
#include "Texture.h"

namespace thundersurge {

	namespace graphics {

		using namespace math;

		class Material {
		private:
			Texture m_texture;
			vec3 m_color;
			float m_specInt, m_specPow;
		public:
			Material(const Texture& texture, const vec3& color, const float& specInt, const float& specPow)
				: m_texture(texture), m_color(color), m_specInt(specInt), m_specPow(specPow) {
			}

			Material(const Texture& texture, const vec3& color) 
				: m_texture(texture), m_color(color), m_specInt(2), m_specPow(32) {
			}

			Material(const Texture& texture) 
				: m_texture(texture), m_color(vec3(1, 1, 1)), m_specInt(2), m_specPow(32) {
			}

			inline Texture getTexture() const { return m_texture; }
			inline vec3 getColor() const { return m_color; }
			inline float getSpecularIntensity() const { return m_specInt; }
			inline float getSpecularPower() const { return m_specPow; }
		};
	}
}