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

		float vec3::dot(const vec3& other) const {
			return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
		}

		vec3 vec3::cross(const vec3& other) const {
			float x = m_y * other.m_z - m_z * other.m_y;
			float y = m_z * other.m_x - m_x * other.m_z;
			float z = m_x * other.m_y - m_y * other.m_x;

			return vec3(x, y, z);
		}

		vec3 vec3::rotate(float angle, const vec3& axis) {
			float s = sin(toRadians(angle / 2));

			float x = axis.m_x * s;
			float y = axis.m_y * s;
			float z = axis.m_z * s;
			float w = cos(toRadians(angle / 2));

			Quaternion rot(x, y, z, w);
			Quaternion con = rot.conjugate();
	
			rot = (rot * *this) * con;

			m_x = rot.getX();
			m_y = rot.getY();
			m_z = rot.getZ();

			return *this;
		}

		float vec3::length() const {
			return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
		}

		vec3 vec3::normalize() const {
			float len = length();
			return vec3(m_x / len, m_y / len, m_z /len);
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

		vec3 operator+(vec3 left, const float& right) {
			return left.add(vec3(right, right, right));
		}

		vec3 operator-(vec3 left, const float& right) {
			return left.sub(vec3(right, right, right));
		}

		vec3 operator*(vec3 left, const float& right) {
			return left.mul(vec3(right, right, right));
		}

		vec3 operator/(vec3 left, const float& right) {
			return left.div(vec3(right, right, right));
		}

		Quaternion operator*(Quaternion left, const vec3& right) {
			float w = -left.getX() * right.m_x - left.getY() * right.m_y - left.getZ() * right.m_z;
			float x = left.getW() * right.m_x + left.getY() * right.m_z - left.getZ() * right.m_y;
			float y = left.getW() * right.m_y + left.getZ() * right.m_x - left.getX() * right.m_z;
			float z = left.getW() * right.m_z + left.getX() * right.m_y - left.getY() * right.m_x;

			return Quaternion(x, y, z, w);
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