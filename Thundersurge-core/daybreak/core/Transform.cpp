#include "Transform.h"

namespace daybreak {

	namespace core {

		Transform::Transform() :
			m_trans(vec3(0, 0, 0)), m_scale(vec3(1, 1, 1)), m_rot(Quaternion(0, 0, 0, 1)) {
		}

		mat4 Transform::getTransform() {
			mat4 res = mat4::translation(m_trans) * (m_rot.toRotationMatrix() * mat4::scale(m_scale));

			return res;
		}

		void Transform::rotate(const float angle, const vec3& axis) {
			m_rot = (Quaternion(axis, angle) * m_rot).normalize();
		}

		void Transform::translate(const vec3& trans) {
			m_trans = m_trans + trans;
		}

		void Transform::scale(const vec3& scale) {
			m_scale = m_scale * scale;
		}
	}
}