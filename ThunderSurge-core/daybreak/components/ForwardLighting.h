#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "GameComponent.h"

namespace daybreak {
	
	namespace graphics {

		using namespace math;

		struct Light : public GameComponent {

			vec3 diffuse;
			vec3 specular;
			Shader* shader;

			Light() {
				diffuse = vec3(0, 0, 0);
				specular = vec3(0, 0, 0);
			}

			Light(const vec3& color, float intensity) {
				diffuse = color;
				specular = vec3(intensity, intensity, intensity);
			}

			void update(float delta) { }
		};

		struct DirectionalLight : public Light {

			vec3 direction;

			DirectionalLight(const vec3& direction, const vec3& color, float intensity) : Light(color, intensity) {
				shader = new Shader("daybreak/graphics/shaders/forward-lighting.vert", "daybreak/graphics/shaders/forward-directional.frag");
				this->direction = direction;
			}

			void render(Shader* shader) { 
				shader->enable();
				shader->setUniform3f("light.direction", direction);
				shader->setUniform3f("light.diffuse", diffuse);
				shader->setUniform3f("light.specular", specular);
			}
		};


	}
}
#endif