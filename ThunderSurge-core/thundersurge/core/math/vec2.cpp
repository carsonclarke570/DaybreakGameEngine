#include "vec2.h"

namespace thundersurge {

	namespace math {

		vec2::vec2() {
			m_x = 0.0f;
			m_y = 0.0f;
		}

		vec2::vec2(const float& x, const float& y) {
			m_x = x;
			m_y = y;
		}

		vec2& vec2::add(const vec2& other) {
			m_x += other.m_x;
			m_y += other.m_y;
			return *this;
		}

		vec2& vec2::sub(const vec2& other) {
			m_x -= other.m_x;
			m_y -= other.m_y;
			return *this;
		}

		vec2& vec2::mul(const vec2& other) {
			m_x *= other.m_x;
			m_y *= other.m_y;
			return *this;
		}

		vec2& vec2::div(const vec2& other) {
			m_x /= other.m_x;
			m_y /= other.m_y;
			return *this;
		}

		float vec2::length() {
			return sqrt(m_x * m_x + m_y * m_y);
		}

		vec2& vec2::normalize() {
			float len = length();
			m_x /= len;
			m_y /= len;
			return *this;
		}

		vec2 operator+(vec2 left, const vec2& right) {
			return left.add(right);
		}

		vec2 operator-(vec2 left, const vec2& right) {
			return left.sub(right);
		}

		vec2 operator*(vec2 left, const vec2& right) {
			return left.mul(right);
		}

		vec2 operator/(vec2 left, const vec2& right) {
			return left.div(right);
		}

		bool vec2::operator==(const vec2& other) {
			return m_x == other.m_x && m_y == other.m_y;
		}

		bool vec2::operator!=(const vec2& other) {
			return !(*this == other);
		}

		vec2& vec2::operator+=(const vec2& other) {
			return add(other);
		}

		vec2& vec2::operator-=(const vec2& other) {
			return sub(other);
		}

		vec2& vec2::operator*=(const vec2& other) {
			return mul(other);
		}

		vec2& vec2::operator/=(const vec2& other) {
			return div(other);
		}

		std::ostream& operator<<(std::ostream& stream, const vec2& vector) {
			stream << "vec2: (" << vector.m_x << ", " << vector.m_y << ")";
			return stream;
		}
	}
}