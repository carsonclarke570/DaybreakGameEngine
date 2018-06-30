#include "Camera.h"

namespace thundersurge {

	namespace core {

		const vec3 Camera::yAxis = vec3(0, 1, 0);

		Camera::Camera() {
			m_pos = math::vec3(0, 0, 0);
			m_forward = math::vec3(0, 0, 1);
			m_up = math::vec3(0, 1, 0);
		}

		Camera::Camera(vec3 pos, vec3 forward, vec3 up) {
			m_pos = pos;
			m_forward = forward;
			m_up = up;

			up = up.normalize();
			forward = forward.normalize();
		}

		void Camera::update(float delta) {
			float mov = 1.0f * delta;
			float rot = 100.0f * delta;

			if (Keyboard::isKeyPressed(KEY_W))
				move(m_forward, -mov);
			if (Keyboard::isKeyPressed(KEY_S))
				move(m_forward, mov);
			if (Keyboard::isKeyPressed(KEY_A))
				move(getLeft(), mov);
			if (Keyboard::isKeyPressed(KEY_D))
				move(getRight(), mov);

			if (Keyboard::isKeyPressed(KEY_UP))
				rotateX(rot);
			if (Keyboard::isKeyPressed(KEY_DOWN))
				rotateX(-rot);
			if (Keyboard::isKeyPressed(KEY_LEFT))
				rotateY(rot);
			if (Keyboard::isKeyPressed(KEY_RIGHT))
				rotateY(-rot);
		}
		
		void Camera::move(const vec3& dir, float amt) {
			m_pos = m_pos + (dir * amt);
		}

		void Camera::rotateY(float angle) {
			vec3 haxis = yAxis.cross(m_forward).normalize();
			m_forward = m_forward.rotate(angle, yAxis).normalize();
			m_up = m_forward.cross(haxis).normalize();
		}

		void Camera::rotateX(float angle) {
			vec3 haxis = yAxis.cross(m_forward).normalize();
			m_forward = m_forward.rotate(angle, haxis).normalize();
			m_up = m_forward.cross(haxis).normalize();
		}

		vec3 Camera::getLeft() {
			return m_forward.cross(m_up).normalize();
		}

		vec3 Camera::getRight() {
			return m_up.cross(m_forward).normalize();
		}
	}
}