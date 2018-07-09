#include <math.h>
#include "vec3.h"
#include "mat4.h"

#ifndef _QUATERNION_H_
#define _QUATERNION_H_

namespace thundersurge {

	namespace math {

		class Quaternion {
		private:
			float m_x, m_y, m_z, m_w;
		public:
			Quaternion(float x, float y, float z, float w);
			Quaternion(const vec3& axis, float angle);

			float length() const;
			Quaternion normalize() const;
			Quaternion conjugate() const;

			Quaternion& mul(const Quaternion& other);

			mat4 toRotationMatrix();

			friend Quaternion operator*(Quaternion left, const Quaternion& right);
			friend Quaternion operator*(Quaternion left, const vec3& right);

			Quaternion& operator*=(const Quaternion& other);

			vec3 rotate(const vec3& toRot);
			inline vec3 getRight() { return rotate(vec3(1, 0, 0)); }
			inline vec3 getLeft() { return rotate(vec3(-1, 0, 0)); }
			inline vec3 getForward() { return rotate(vec3(0, 0, 1)); }

			inline float getX() { return m_x; }
			inline float getY() { return m_y; }
			inline float getZ() { return m_z; }
			inline float getW() { return m_w; }
		};
	}
}

#endif