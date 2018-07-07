#include "math/math.h"
#include "input/input.h"
#include "../graphics/window.h"

#ifndef _CAMERA_H_
#define _CAMERA_H_

namespace thundersurge {

	namespace core {
		
		using namespace math;
		using namespace input;
		using namespace graphics;

		class Camera {
		private:
			static const vec3 yAxis;
			vec3 m_pos, m_up, m_forward;
			
			bool m_mouselocked;
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

#endif