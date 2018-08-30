#include "vec3.h"
#include "util.h"

#include <cstring>

#ifndef _MAT4_H_
#define _MAT4_H_

namespace daybreak {
	
	namespace math {

		struct mat4 {

			float m_m[16];

			mat4();
			mat4(float diag);

			static mat4 identity();

			static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
			static mat4 perspective(float fov, float aspect, float near, float far);

			static mat4 translation(const vec3& translation);
			static mat4 rotation(float angle, const vec3& axis);
			static mat4 rotation(const vec3& forward, const vec3& up, const vec3& right);
			static mat4 scale(const vec3& scale);
			static mat4 camera(const vec3& forward, const vec3& up);

			mat4& mul(const mat4& other);
			vec3 mul(const vec3& other);

			friend mat4 operator*(mat4 left, const mat4& right);
			friend vec3 operator*(mat4 left, const vec3& right);

			mat4& operator*=(const mat4& other);
			vec3 operator*=(const vec3& other);
		};
	}
}

#endif