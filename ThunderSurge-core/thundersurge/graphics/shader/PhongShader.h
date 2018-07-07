#pragma once

#include "Shader.h"
#include "../../components/Light.h"
#include "../../core/math/math.h"
#include "../../core/Transform.h"

namespace thundersurge {

	namespace graphics {

		using namespace math;
		using namespace core;

		class PhongShader : public Shader {
		private:
			static vec3 m_ambience;
			static DirectionalLight m_directionalLight;
		public:
			PhongShader();

			void update(Transform& transform, const Material& material);

			void setUniformLight(const GLchar* name, const BaseLight& light);
			void setUniformLight(const GLchar* name, const DirectionalLight& light);

			inline void setAmbience(const vec3& ambience) { m_ambience = ambience; }
			inline void setDirectionalLight(const DirectionalLight& directionalLight) { m_directionalLight = directionalLight; }
		};
	}
}