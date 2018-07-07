#pragma once

#include "../core/math/math.h"

namespace thundersurge {
	
	namespace graphics {

		using namespace math;

		struct BaseLight {
			vec3 ambient;
			vec3 diffuse;
			vec3 specular;

			BaseLight() {
				ambient = vec3(0, 0, 0);
				diffuse = vec3(0, 0, 0);
				specular = vec3(0, 0, 0);
			}
		};

		struct DirectionalLight  {
			BaseLight base;
			vec3 direction;

			DirectionalLight() {
				base = BaseLight();
				direction = vec3(0, 0, 0);
			}
		};
	}
}