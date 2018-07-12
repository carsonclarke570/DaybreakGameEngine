#include "vec4.h"

namespace daybreak {

	namespace math {

		vec4::vec4() {
			m_x = 0.0f;
			m_y = 0.0f;
			m_z = 0.0f;
			m_w = 0.0f;
		}

		vec4::vec4(const float& x, const float& y, const float& z, const float& w) {
			m_x = x;
			m_y = y;
			m_z = z;
			m_w = w;
		}

		vec4& vec4::add(const vec4& other) {
			m_x += other.m_x;
			m_y += other.m_y;
			m_z += other.m_z;
			m_w += other.m_w;
			return *this;
		}

		vec4& vec4::sub(const vec4& other) {
			m_x -= other.m_x;
			m_y -= other.m_y;
			m_z -= other.m_z;
			m_w -= other.m_w;
			return *this;
		}

		vec4& vec4::mul(const vec4& other) {
			m_x *= other.m_x;
			m_y *= other.m_y;
			m_z *= other.m_z;
			m_w *= other.m_w;
			return *this;
		}

		vec4& vec4::div(const vec4& other) {
			m_x /= other.m_x;
			m_y /= other.m_y;
			m_z /= other.m_z;
			m_w /= other.m_w;
			return *this;
		}

		float vec4::length() {
			return sqrt(m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w);
		}

		vec4& vec4::normalize() {
			float len = length();
			m_x /= len;
			m_y /= len;
			m_z /= len;
			m_w /= len;
			return *this;
		}

		vec4 operator+(vec4 left, const vec4& right) {
			return left.add(right);
		}

		vec4 operator-(vec4 left, const vec4& right) {
			return left.sub(right);
		}

		vec4 operator*(vec4 left, const vec4& right) {
			return left.mul(right);
		}

		vec4 operator/(vec4 left, const vec4& right) {
			return left.div(right);
		}

		bool vec4::operator==(const vec4& other) {
			return m_x == other.m_x && m_y == other.m_y && m_z == other.m_z && m_w == other.m_w;
		}

		bool vec4::operator!=(const vec4& other) {
			return !(*this == other);
		}

		vec4& vec4::operator+=(const vec4& other) {
			return add(other);
		}

		vec4& vec4::operator-=(const vec4& other) {
			return sub(other);
		}

		vec4& vec4::operator*=(const vec4& other) {
			return mul(other);
		}

		vec4& vec4::operator/=(const vec4& other) {
			return div(other);
		}

		std::ostream& operator<<(std::ostream& stream, const vec4& vector) {
			stream << "vec4: (" << vector.m_x << ", " << vector.m_y << ", " << vector.m_z << ", " << vector.m_w << ")";
			return stream;
		}
	}
}