#pragma once

#include "Shader.h"

namespace thundersurge {

	namespace graphics {

		class BasicShader : public Shader {
		public:
			BasicShader() 
				: Shader("thundersurge/graphics/shader/shaders/basic.vert", "thundersurge/graphics/shader/shaders/basic.frag") {
			}

			void update(const mat4& world, const mat4& projection, const Material& material) {
				material.getTexture().bind();
				setUniformMat4("transform", projection);
				setUniform3f("color", material.getColor());
			}
		};
	}
}