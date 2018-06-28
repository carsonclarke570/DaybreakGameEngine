#pragma once

#include "math/math.h"
#include "input/input.h"

namespace thundersurge {

	namespace core {
		
		using namespace math;
		using namespace input;

		class Camera {
		private:
			static const vec3 yAxis;
			vec3 m_pos, m_up, m_forward;
		public:
			Camera();
			Camera(vec3 pos, vec3 forward, vec3 up);

			void update(float delta);
			void move(const vec3& dir, float amt);

			void rotateY(float amt);
			void rotateX(float amt);

			vec3 getLeft();
			vec3 getRight();

			inline vec3 getPosition() const { return m_pos; }
			inline vec3 getForward() const { return m_forward; }
			inline vec3 getUp() const { return m_up; }
		};
	}
}