#include <iostream>

#ifndef _VEC2_H_
#define _VEC2_H_

namespace thundersurge {

	namespace math {

		struct vec2 {
			float m_x, m_y;

			vec2();
			vec2(const float& x, const float& y);

			vec2& add(const vec2& other);
			vec2& sub(const vec2& other);
			vec2& mul(const vec2& other);
			vec2& div(const vec2& other);

			float length();
			vec2& normalize();

			friend vec2 operator+(vec2 left, const vec2& right);
			friend vec2 operator-(vec2 left, const vec2& right);
			friend vec2 operator*(vec2 left, const vec2& right);
			friend vec2 operator/(vec2 left, const vec2& right);

			bool operator==(const vec2& other);
			bool operator!=(const vec2& other);

			vec2& operator+=(const vec2& other);
			vec2& operator-=(const vec2& other);
			vec2& operator*=(const vec2& other);
			vec2& operator/=(const vec2& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
		};
	}
}

#endif