#pragma once

#include "../../core/math/math.h"

namespace thundersurge {
	
	namespace graphics {

		using namespace math;

		struct BaseLight {
			vec3 color;
			float intensity;
		};

		struct DirectionalLight {
			BaseLight base;
			vec3 direction;
		};
	}
}