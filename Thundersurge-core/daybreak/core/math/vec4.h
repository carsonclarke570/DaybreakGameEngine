#include <iostream>

#ifndef _VEC4_H_
#define _VEC4_H_

namespace daybreak {

	namespace math {

		struct vec4 {
			float m_x, m_y, m_z, m_w;

			vec4();
			vec4(const float& x, const float& y, const float& z, const float& w);

			vec4& add(const vec4& other);
			vec4& sub(const vec4& other);
			vec4& mul(const vec4& other);
			vec4& div(const vec4& other);

			float length();
			vec4& normalize();

			friend vec4 operator+(vec4 left, const vec4& right);
			friend vec4 operator-(vec4 left, const vec4& right);
			friend vec4 operator*(vec4 left, const vec4& right);
			friend vec4 operator/(vec4 left, const vec4& right);

			bool operator==(const vec4& other);
			bool operator!=(const vec4& other);

			vec4& operator+=(const vec4& other);
			vec4& operator-=(const vec4& other);
			vec4& operator*=(const vec4& other);
			vec4& operator/=(const vec4& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
		};
	}
}

#endif