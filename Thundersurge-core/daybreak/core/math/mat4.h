#include "vec3.h"
#include "vec4.h"
#include "util.h"

#include <cstring>

#ifndef _MAT4_H_
#define _MAT4_H_

namespace daybreak {
	
	namespace math {

		struct Quaternion;

		struct mat4 {

			union {
				float elements[16];
				vec4 rows[4];
			};

			mat4();
			mat4(float diag);
			mat4(float* elements);
			mat4(const vec4& row0, const vec4& row1, const vec4& row2, const vec4& row3);

			static mat4 identity();

			mat4& mul(const mat4& other);
			friend mat4 operator*(mat4 left, const mat4& right);
			mat4& operator*=(const mat4& other);

			vec3 mul(const vec3& other) const;
			friend vec3 operator*(const mat4& left, const vec3& right);

			//vec4 mul(const vec4& other) const;
			//friend vec4 operator*(const mat4& left, const vec4& right);

			vec4 getColumn(int index) const;
			void setColumn(int index, const vec4& column);
			//inline vec3 getPosition() const { return vec3(getColumn(3)); }
			//inline void setPosition(const vec3& position) { setColumn(3, vec4(position, 1.0f)); }

			static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
			static mat4 perspective(float fov, float aspect, float near, float far);
			static mat4 lookAt(const vec3& camera, const vec3& object, const vec3& up);

			static mat4 translation(const vec3& translation);
			static mat4 rotation(float angle, const vec3& axis);
			static mat4 rotation(const Quaternion& quat);
			static mat4 scale(const vec3& scale);

			static mat4 transpose(const mat4& matrix);
		};
	}
}

#endif