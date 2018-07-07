#include "Camera.h"

namespace thundersurge {

	namespace core {

		const vec3 Camera::yAxis = vec3(0, 1, 0);

		Camera::Camera() {
			m_pos = math::vec3(0, 0, 0);
			m_forward = math::vec3(0, 0, 1);
			m_up = math::vec3(0, 1, 0);

			m_mouselocked = false;
		}

		Camera::Camera(vec3 pos, vec3 forward, vec3 up) {
			m_pos = pos;
			m_forward = forward.normalize();
			m_up = up.normalize();

			m_mouselocked = false;
		}

		void Camera::update(float delta) {
			float mov = 1.0f * delta;
			float rot = 0.05f;

			if (Keyboard::isKeyDown(KEY_W) || Keyboard::isKeyPressed(KEY_W))
				move(m_forward, -mov);
			if (Keyboard::isKeyDown(KEY_S) || Keyboard::isKeyPressed(KEY_S))
				move(m_forward, mov);
			if (Keyboard::isKeyDown(KEY_A) || Keyboard::isKeyPressed(KEY_A))
				move(getLeft(), mov);
			if (Keyboard::isKeyDown(KEY_D) || Keyboard::isKeyPressed(KEY_D))
				move(getRight(), mov);

			if (Keyboard::isKeyPressed(KEY_ESCAPE)) {
				Mouse::showCursor();
				m_mouselocked = false;
			}

			if (Mouse::isButtonPressed(0)) {
				Mouse::setMousePosition(Window::getWidth() / 2, Window::getHeight() / 2);
				Mouse::hideCursor();
				m_mouselocked = true;
			}

			if (m_mouselocked) {
				math::vec2 curpos;
				Mouse::getMousePosition(curpos);
				math::vec2 delta = curpos - math::vec2(Window::getWidth() / 2, Window::getHeight() / 2);

				bool rotY = delta.m_x != 0.0f;
				bool rotX = delta.m_y != 0.0f;

				if (rotY) {
					rotateY(-delta.m_x * rot);
				}
				if (rotX) {
					rotateX(-delta.m_y * rot);
				}

				if (rotY || rotX) {
					Mouse::setMousePosition(Window::getWidth() / 2, Window::getHeight() / 2);
				}
			}
		}
		
		void Camera::move(const vec3& dir, float amt) {
			m_pos = m_pos + (dir * amt);
		}

		void Camera::rotateY(float angle) {
			vec3 haxis = yAxis.cross(m_forward).normalize();
			//m_forward = m_forward.rotate(angle, yAxis).normalize();
			m_forward = (Quaternion(yAxis, angle).toRotationMatrix() * m_forward).normalize();
			m_up = m_forward.cross(haxis).normalize();
		}

		void Camera::rotateX(float angle) {
			vec3 haxis = yAxis.cross(m_forward).normalize();
			//m_forward = m_forward.rotate(angle, haxis).normalize();
			m_forward = (Quaternion(haxis, angle).toRotationMatrix() * m_forward).normalize();
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