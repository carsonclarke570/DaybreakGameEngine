#include "Quaternion.h"

namespace thundersurge {

	namespace math {

		Quaternion::Quaternion(float x, float y, float z, float w) :
			m_x(x), m_y(y), m_z(z), m_w(w) {
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

		Quaternion& Quaternion::operator*=(const Quaternion& other) {
			return mul(other);
		}

		Quaternion operator*(Quaternion left, const Quaternion& right) {
			return left.mul(right);
		}
	}
}