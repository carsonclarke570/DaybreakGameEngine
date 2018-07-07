#define _USE_MATH_DEFINES

#include <math.h>

#ifndef _MATH_UTIL_H_
#define _MATH_UTIL_H_

namespace thundersurge {

	namespace math {

		inline float toRadians(float degrees) {
			return degrees * ((float)M_PI / 180.0f);
		}
	}
}

#endif