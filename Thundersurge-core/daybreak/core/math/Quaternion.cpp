#include "Quaternion.h"

namespace daybreak {

	namespace math {

		Quaternion::Quaternion(float x, float y, float z, float w) :
			m_x(x), m_y(y), m_z(z), m_w(w) {
		}

		Quaternion::Quaternion(const vec3& axis, float angle) {
			float s = sinf(toRadians(angle / 2));

			m_x = axis.m_x * s;
			m_y = axis.m_y * s;
			m_z = axis.m_z * s;
			m_w = cosf(toRadians(angle / 2));
		}

		float Quaternion::length() const {
			return (float) sqrt(m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w);
		}

		Quaternion Quaternion::normalize() const {
			float len = length();
			return Quaternion(m_x / len, m_y / len, m_z / len, m_w / len);
		}

		Quaternion Quaternion::conjugate() const {
			return Quaternion(-m_x, -m_y, -m_z, m_w);
		}

		Quaternion& Quaternion::mul(const Quaternion& other) {
			float w = m_w * other.m_w - m_x * other.m_x - m_y * other.m_y - m_z * other.m_z;
			float x = m_x * other.m_w + m_w * other.m_x + m_y * other.m_z - m_z * other.m_y;
			float y = m_y * other.m_w + m_w * other.m_y + m_z * other.m_x - m_x * other.m_z;
			float z = m_z * other.m_w + m_w * other.m_z + m_x * other.m_y - m_y * other.m_x;

			m_w = w;
			m_x = x;
			m_y = y;
			m_z = z;

			return *this;
		}

		mat4 Quaternion::toRotationMatrix() {
			vec3 forward = vec3(2.0f * (m_x * m_z - m_w * m_y), 2.0f * (m_y * m_z + m_w * m_x), 1.0f - 2.0f * (m_x * m_x + m_y * m_y));
			vec3 up = vec3(2.0f * (m_x * m_y + m_w * m_z), 1.0f - 2.0f * (m_x * m_x + m_z * m_z), 2.0f * (m_y * m_z - m_w * m_x));
			vec3 right = vec3(1.0f - 2.0f * (m_y * m_y + m_z * m_z), 2.0f * (m_x * m_y - m_w * m_z), 2.0f * (m_x * m_z + m_w * m_y));

			return mat4::rotation(forward, up, right);
		}

		vec3 Quaternion::getForward() {
			return getBack() * vec3(-1, -1, -1);
		}

		vec3 Quaternion::getBack() {
			return vec3(2.0f * (m_x * m_z - m_w * m_y), 2.0f * (m_y * m_z + m_w * m_x), 1.0f - 2.0f * (m_x * m_x + m_y * m_y));
		}

		vec3 Quaternion::getRight() {
			return vec3(1.0f - 2.0f * (m_y * m_y + m_z * m_z), 2.0f * (m_x * m_y - m_w * m_z), 2.0f * (m_x * m_z + m_w * m_y));
		}

		vec3 Quaternion::getLeft() {
			return getRight() * vec3(-1, -1, -1);
		}

		vec3 Quaternion::getUp() {
			return vec3(2.0f * (m_x * m_y + m_w * m_z), 1.0f - 2.0f * (m_x * m_x + m_z * m_z), 2.0f * (m_y * m_z - m_w * m_x));
		}

		vec3 Quaternion::getDown() {
			return getUp() * vec3(-1, -1, -1);
		}

		Quaternion& Quaternion::operator*=(const Quaternion& other) {
			return mul(other);
		}

		Quaternion operator*(Quaternion left, const Quaternion& right) {
			return left.mul(right);
		}

		Quaternion operator*(Quaternion left, const vec3& right) {
			float w = -left.getX() * right.m_x - left.getY() * right.m_y - left.getZ() * right.m_z;
			float x = left.getW() * right.m_x + left.getY() * right.m_z - left.getZ() * right.m_y;
			float y = left.getW() * right.m_y + left.getZ() * right.m_x - left.getX() * right.m_z;
			float z = left.getW() * right.m_z + left.getX() * right.m_y - left.getY() * right.m_x;

			return Quaternion(x, y, z, w);
		}
	}
}