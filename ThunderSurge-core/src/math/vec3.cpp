#include "vec3.h"

namespace thundersurge {

	namespace math {

		vec3::vec3() {
			m_x = 0.0f;
			m_y = 0.0f;
			m_z = 0.0f;
		}

		vec3::vec3(const float& x, const float& y, const float& z) {
			m_x = x;
			m_y = y;
			m_z = z;
		}

		vec3& vec3::add(const vec3& other) {
			m_x += other.m_x;
			m_y += other.m_y;
			m_z += other.m_z;
			return *this;
		}

		vec3& vec3::sub(const vec3& other) {
			m_x -= other.m_x;
			m_y -= other.m_y;
			m_z -= other.m_z;
			return *this;
		}

		vec3& vec3::mul(const vec3& other) {
			m_x *= other.m_x;
			m_y *= other.m_y;
			m_z *= other.m_z;
			return *this;
		}

		vec3& vec3::div(const vec3& other) {
			m_x /= other.m_x;
			m_y /= other.m_y;
			m_z /= other.m_z;
			return *this;
		}

		vec3 operator+(vec3 left, const vec3& right) {
			return left.add(right);
		}

		vec3 operator-(vec3 left, const vec3& right) {
			return left.sub(right);
		}

		vec3 operator*(vec3 left, const vec3& right) {
			return left.mul(right);
		}

		vec3 operator/(vec3 left, const vec3& right) {
			return left.div(right);
		}

		bool vec3::operator==(const vec3& other) {
			return m_x == other.m_x && m_y == other.m_y && m_z == other.m_z;
		}

		bool vec3::operator!=(const vec3& other) {
			return !(*this == other);
		}

		vec3& vec3::operator+=(const vec3& other) {
			return add(other);
		}

		vec3& vec3::operator-=(const vec3& other) {
			return sub(other);
		}

		vec3& vec3::operator*=(const vec3& other) {
			return mul(other);
		}

		vec3& vec3::operator/=(const vec3& other) {
			return div(other);
		}

		std::ostream& operator<<(std::ostream& stream, const vec3& vector) {
			stream << "vec3: (" << vector.m_x << ", " << vector.m_y << ", " << vector.m_z << ")";
			return stream;
		}
	}
}