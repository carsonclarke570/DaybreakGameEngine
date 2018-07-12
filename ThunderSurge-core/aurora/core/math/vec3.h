#include <iostream>
#include "util.h"

#ifndef _VEC3_H_
#define _VEC3_H_

namespace aurora {

	namespace math {

		struct vec3 {
			float m_x, m_y, m_z;

			vec3();
			vec3(const float& x, const float& y, const float& z);

			vec3& add(const vec3& other);
			vec3& sub(const vec3& other);
			vec3& mul(const vec3& other);
			vec3& div(const vec3& other);

			float dot(const vec3& other) const;
			vec3 cross(const vec3& other) const;

			float length() const;
			vec3 normalize() const;

			friend vec3 operator+(vec3 left, const vec3& right);
			friend vec3 operator-(vec3 left, const vec3& right);
			friend vec3 operator*(vec3 left, const vec3& right);
			friend vec3 operator/(vec3 left, const vec3& right);

			friend vec3 operator+(vec3 left, const float& right);
			friend vec3 operator-(vec3 left, const float& right);
			friend vec3 operator*(vec3 left, const float& right);
			friend vec3 operator/(vec3 left, const float& right);

			bool operator==(const vec3& other);
			bool operator!=(const vec3& other);

			vec3& operator+=(const vec3& other);
			vec3& operator-=(const vec3& other);
			vec3& operator*=(const vec3& other);
			vec3& operator/=(const vec3& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
		};
	}
}

#endif