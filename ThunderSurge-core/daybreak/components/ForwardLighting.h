#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "GameComponent.h"

namespace daybreak {
	
	namespace graphics {

		using namespace math;

		struct Light {

			vec3 diffuse;
			vec3 specular;
			Shader* shader;

			Light(const vec3& color, float intensity) {
				diffuse = color;
				specular = vec3(intensity, intensity, intensity);
			}

			virtual void update() = 0;
		};

		struct DirectionalLight : public Light {

			vec3 direction;

			DirectionalLight(const vec3& direction, const vec3& color, float intensity) : Light(color, intensity) {
				shader = new Shader("daybreak/graphics/shaders/forward-lighting.vert", "daybreak/graphics/shaders/forward-directional.frag");
				this->direction = direction;
			}

			void update() { 
				shader->enable();
				shader->setUniform3f("light.direction", direction);
				shader->setUniform3f("light.diffuse", diffuse);
				shader->setUniform3f("light.specular", specular);
				shader->disable();
			}
		};

		struct SpotLight : public Light {
			vec3 position;
			vec3 direction;

			float cutOff;
			float outerCutOff;

			float constant;
			float linear;
			float quadratic;

			SpotLight(const vec3& position, const vec3& direction, const vec3& color, float intensity, float cutOff, float outerCutOff, float constant, float linear, float quadratic) : Light(color, intensity) {
				shader = new Shader("daybreak/graphics/shaders/forward-lighting.vert", "daybreak/graphics/shaders/forward-spot.frag");
				this->position = position;
				this->direction = direction;
				this->cutOff = cutOff;
				this->outerCutOff = outerCutOff;
				this->constant = constant;
				this->linear = linear;
				this->quadratic = quadratic;
			}

			SpotLight(const vec3& position, const vec3& direction, const vec3& color, float intensity) : SpotLight(position, direction, color, intensity, cos(toRadians(12.5f)), cos(toRadians(15.0f)), 1.0f, 0.09f, 0.032f) { }
		
			void update() {
				shader->enable();
				shader->setUniform3f("light.direction", direction);
				shader->setUniform3f("light.diffuse", diffuse);
				shader->setUniform3f("light.specular", specular);
				shader->setUniform3f("light.position", position);
				shader->setUniform1f("light.constant", constant);
				shader->setUniform1f("light.linear", linear);
				shader->setUniform1f("light.quadratic", quadratic);
				shader->setUniform1f("light.cutOff", cutOff);
				shader->setUniform1f("light.outerCutOff", outerCutOff);
				shader->disable();
			}
		};
	}
}
#endif