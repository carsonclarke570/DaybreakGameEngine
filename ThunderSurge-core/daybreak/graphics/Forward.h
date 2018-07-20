#ifndef _FORWARD_H_
#define _FORWARD_H_

#include "Shader.h"

namespace daybreak {

	namespace graphics {

		class Ambient : public Shader {
		private:
			vec3 m_ambience;
		public:
			Ambient() : Shader("daybreak/graphics/shaders/forward-ambient.vert", "daybreak/graphics/shaders/forward-ambient.frag"){
				m_ambience = vec3(0.1f, 0.1f, 0.1f);
			}

			void update(Transform* transform, Material& material) {
				material.bind();

				//setUniformMat4("projection", transform->getProjectedTransform());
				setUniformMat4("model", transform->getTransform());

				setUniform1i("material.diffuse", 0);
				setUniform3f("ambience", m_ambience);

				//setUniform3f("viewPos", Transform::getCamera()->getPosition());
			}

			void setAmbience(const vec3& ambience) { m_ambience = ambience; }
		};
	}
}

#endif
