#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "../graphics/Forward.h"
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

			void render(Shader* shader) { }
			void update(float delta) { }
		};

		struct DirectionalLight : public Light {

			vec3 direction;

			DirectionalLight(const vec3& direction, const vec3& color, float intensity) : Light(color, intensity) {
				shader = new DirectionalShader(direction, color, intensity);
			}

			void setDirection(const vec3& direction) {
				((DirectionalShader*)shader)->setDiection(direction);
			}
		};


	}
}
#endif