#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "../graphics/Forward.h"
#include "GameComponent.h"

namespace daybreak {
	
	namespace graphics {

		using namespace math;

		struct BaseLight : public GameComponent {
			vec3 diffuse;
			vec3 specular;
			Shader* shader;

			BaseLight() {
				diffuse = vec3(0, 0, 0);
				specular = vec3(0, 0, 0);
			}

			BaseLight(const vec3& color, float intensity) {
				diffuse = color;
				specular = vec3(intensity, intensity, intensity);
			}

			void render(Shader* shader) { }
		};

		struct DirectionalLight : public BaseLight {

			DirectionalLight(const vec3& direction, const vec3& color, float intensity) : BaseLight(color, intensity) {
				shader = new AmbientShader();//new DirectionalShader(direction, color, intensity);
			}

			void update(float delta) {
				
			}
		};
	}
}
#endif