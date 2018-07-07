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
			static DirectionalLight m_directionalLight;
		public:
			PhongShader();

			void update(Transform& transform, Material& material);

			void setUniformLight(const GLchar* name, const BaseLight& light);
			void setUniformLight(const GLchar* name, const DirectionalLight& light);

			inline void setDirectionalLight(const DirectionalLight& directionalLight) { m_directionalLight = directionalLight; }
		};
	}
}