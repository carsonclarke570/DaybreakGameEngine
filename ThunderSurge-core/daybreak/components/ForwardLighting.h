#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "GameComponent.h"

namespace daybreak {
	
	namespace graphics {

		using namespace math;

		struct BaseLight {
			vec3 ambient;
			vec3 diffuse;
			vec3 specular;
		};

		struct Attenuation {
			float constant;
			float linear;
			float quadratic;
		};

		struct Light {

			Shader* shader;
			BaseLight light;

			virtual void update() = 0;
		};

		struct DirectionalLight : public Light {

			vec3 direction;

			DirectionalLight(const BaseLight& light, const vec3& direction) : Light() {
				this->shader = new Shader("daybreak/graphics/shaders/forward-lighting.vert", "daybreak/graphics/shaders/forward-directional.frag", NULL);
				this->light.ambient = light.ambient;
				this->light.diffuse = light.diffuse;
				this->light.specular = light.specular;
				this->direction = direction;
			}

			void update() { 
				shader->enable();
				shader->setUniform3f("light.direction", direction);
				shader->setUniform3f("light.light.ambient", light.ambient);
				shader->setUniform3f("light.light.diffuse", light.diffuse);
				shader->setUniform3f("light.light.specular", light.specular);
				shader->disable();
			}
		};

		struct SpotLight : public Light {
			vec3 position;
			vec3 direction;

			float cutOff;
			float outerCutOff;

			Attenuation attenuation;

			SpotLight(const BaseLight& light, const Attenuation& attenuation, const vec3& position, const vec3& direction, float cutOff, float outerCutOff) : Light() {
				shader = new Shader("daybreak/graphics/shaders/forward-lighting.vert", "daybreak/graphics/shaders/forward-spot.frag", NULL);
				this->light.ambient = light.ambient;
				this->light.diffuse = light.diffuse;
				this->light.specular = light.specular;
				this->direction = direction;
				this->position = position;
				this->cutOff = cutOff;
				this->outerCutOff = outerCutOff;
				this->attenuation.constant = attenuation.constant;
				this->attenuation.linear = attenuation.linear;
				this->attenuation.quadratic = attenuation.quadratic;
			}
		
			void update() {
				shader->enable();
				shader->setUniform3f("light.direction", direction);
				shader->setUniform3f("light.light.ambient", light.ambient);
				shader->setUniform3f("light.light.diffuse", light.diffuse);
				shader->setUniform3f("light.light.specular", light.specular);
				shader->setUniform3f("light.position", position);
				shader->setUniform1f("light.attenuation.constant", attenuation.constant);
				shader->setUniform1f("light.attenuation.linear", attenuation.linear);
				shader->setUniform1f("light.attenuation.quadratic", attenuation.quadratic);
				shader->setUniform1f("light.cutOff", cutOff);
				shader->setUniform1f("light.outerCutOff", outerCutOff);
				shader->disable();
			}
		};

		struct PointLight : public Light {
			vec3 position;

			Attenuation attenuation;

			PointLight(const BaseLight& light, const Attenuation& attenuation, const vec3& position) : Light() {
				shader = new Shader("daybreak/graphics/shaders/forward-lighting.vert", "daybreak/graphics/shaders/forward-point.frag", NULL);
				this->light.ambient = light.ambient;
				this->light.diffuse = light.diffuse;
				this->light.specular = light.specular;
				this->position = position;
				this->attenuation.constant = attenuation.constant;
				this->attenuation.linear = attenuation.linear;
				this->attenuation.quadratic = attenuation.quadratic;
			}

			void update() {
				shader->enable();
				shader->setUniform3f("light.light.ambient", light.ambient);
				shader->setUniform3f("light.light.diffuse", light.diffuse);
				shader->setUniform3f("light.light.specular", light.specular);
				shader->setUniform3f("light.position", position);
				shader->setUniform1f("light.attenuation.constant", attenuation.constant);
				shader->setUniform1f("light.attenuation.linear", attenuation.linear);
				shader->setUniform1f("light.attenuation.quadratic", attenuation.quadratic);
				shader->disable();
			}
		};
	}
}
#endif