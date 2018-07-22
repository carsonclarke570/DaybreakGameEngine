#ifndef _FORWARD_H_
#define _FORWARD_H_

#include "Shader.h"

namespace daybreak {

	namespace graphics {

		class AmbientShader : public Shader {
		private:
			vec3 m_ambience;
		public:
			AmbientShader() : Shader("daybreak/graphics/shaders/forward-lighting.vert", "daybreak/graphics/shaders/forward-ambient.frag"){
				m_ambience = vec3(0.05f, 0.05f, 0.05f);
			}

			void update(Transform* transform, Material* material) {
				material->bind();
				enable();
				setUniformMat4("model", transform->getTransform());
				setUniform1i("material.diffuse", 0);
				setUniform3f("ambience", m_ambience);
			}

			void setAmbience(const vec3& ambience) { m_ambience = ambience; }
		};

		class DirectionalShader : public Shader {
		private:
			vec3 m_direction;
			vec3 m_color;
			float m_intensity;
		public:
			DirectionalShader(const vec3& direction, const vec3& color, float intensity) : Shader("daybreak/graphics/shaders/forward-lighting.vert", "daybreak/graphics/shaders/forward-directional.frag") {
				m_color = color;
				m_intensity = intensity;
				m_direction = direction;
			}

			void update(Transform* transform, Material* material) {
				material->bind();
				enable();
				setUniformMat4("model", transform->getTransform());
				setUniform1i("material.diffuse", 0);
				setUniform1i("material.specular", 1);
				setUniform1f("material.specPow", material->getSpecularPower());
				setUniform3f("light.direction", m_direction);
				setUniform3f("light.diffuse", m_color);
				setUniform3f("light.specular", vec3(m_intensity, m_intensity, m_intensity));
			}

			void setDiection(const vec3& direction) { m_direction = direction; }
		};
	}
}

#endif
