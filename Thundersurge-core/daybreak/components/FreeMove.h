#ifndef _FREE_MOVE_H_
#define _FREE_MOVE_H_

#include "GameComponent.h"
#include "../core/input/input.h"

namespace daybreak {

	namespace components {

		class FreeMove : public GameComponent {
		private:
			const static vec3 X_AXIS;
			const static vec3 Z_AXIS;

			float m_speed;
			int m_forward, m_back, m_left, m_right;
		public:
			FreeMove(float speed) {
				m_speed = speed;
				m_forward = KEY_W;
				m_left = KEY_A;
				m_back = KEY_S;
				m_right = KEY_D;
			}

			FreeMove(float speed, int forward, int back, int left, int right) {
				m_speed = speed;
				m_forward = forward;
				m_back = back;
				m_left = left;
				m_right = right;
			}

			void update(float delta) {
				float movamt = m_speed * delta;

				if (Keyboard::isKeyPressed(m_forward) || Keyboard::isKeyDown(m_forward))
					move(getTransform()->getRotation().getForward(), movamt);
				if (Keyboard::isKeyPressed(m_back) || Keyboard::isKeyDown(m_back))
					move(getTransform()->getRotation().getForward(), -movamt);
				if (Keyboard::isKeyPressed(m_left) || Keyboard::isKeyDown(m_left))
					move(getTransform()->getRotation().getRight(), -movamt);
				if (Keyboard::isKeyPressed(m_right) || Keyboard::isKeyDown(m_right))
					move(getTransform()->getRotation().getRight(), movamt);
			}

			void move(const vec3& dir, float amt) {
				getTransform()->translate(dir * vec3(amt, amt, amt));
			}

			void render(Shader* shader) { }
		};
	}
}

#endif