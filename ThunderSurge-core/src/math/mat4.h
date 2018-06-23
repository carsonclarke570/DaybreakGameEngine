#pragma once

#include "vec3.h"
#include "vec4.h"
#include "util.h"

namespace thundersurge {
	
	namespace math {

		struct mat4 {

			union {
				float m_m[16];
				struct {
					vec4 m_cols[4];
				};
			};

			mat4();
			mat4(float diag);

			static mat4 identity();

			static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
			static mat4 perspective(float fov, float aspect, float near, float far);

			static mat4 translation(const vec3& translation);
			static mat4 rotation(float angle, const vec3& axis);
			static mat4 scale(const vec3& scale);

			mat4& mul(const mat4& other);
			friend mat4 operator*(mat4 left, const mat4& right);
			mat4& operator*=(const mat4& other);
		};
	}
}