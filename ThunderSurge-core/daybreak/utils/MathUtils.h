#define _USE_MATH_DEFINES

#ifndef _MATH_UTIL_H_
#define _MATH_UTIL_H_

#include <math.h>

namespace daybreak {

	inline float toRadians(float degrees) {
		return degrees * ((float)M_PI / 180.0f);
	}	
}

#endif