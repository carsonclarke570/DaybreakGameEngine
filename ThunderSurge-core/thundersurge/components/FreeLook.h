#ifndef _FREE_LOOK_H_
#define _FREE_LOOK_H_

#include "GameComponent.h"
#include "../core/input/input.h"
#include "../graphics/window.h"

namespace thundersurge {

	namespace components {

		using namespace graphics;

		class FreeLook : public GameComponent {
		private:
			static const vec3 Y_AXIS;

			bool m_mouseLocked;
			float m_sensitivity;
			int m_unlockKey;
		public:
			FreeLook(float sensitivity) {
				m_sensitivity = sensitivity;
				m_unlockKey = KEY_ESCAPE;
				m_mouseLocked = false;
			}

			void update(float delta) {
				vec2 center = vec2(Window::getWidth() / 2, Window::getHeight() / 2);
				vec2 d;

				if (Keyboard::isKeyPressed(m_unlockKey)) {
					Mouse::showCursor();
					m_mouseLocked = false;
				}

				if (Mouse::isButtonPressed(0)) {
					Mouse::hideCursor();
					m_mouseLocked = true;
					Mouse::setMousePosition(center.m_x, center.m_y);
				}

				if (m_mouseLocked) {
					Mouse::getMousePosition(d);
					d = d - center;

					bool rotY = d.m_x != 0;
					bool rotX = d.m_y != 0;

					if (rotY)
						getTransform()->rotate(toRadians(d.m_x * m_sensitivity), Y_AXIS);
					if (rotX)
						getTransform()->rotate(toRadians(d.m_y * m_sensitivity), getTransform()->getRotation().getRight());

					if (rotY || rotX)
						Mouse::setMousePosition(center.m_x, center.m_y);
				}
			}

			void render(Shader* shader) { }
		};

		const vec3 FreeLook::Y_AXIS = vec3(0, 1, 0);
	}
}

#endif