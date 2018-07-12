#ifndef _LIGHT_H_
#define _LIGHT_H_

namespace daybreak {
	
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
#endif