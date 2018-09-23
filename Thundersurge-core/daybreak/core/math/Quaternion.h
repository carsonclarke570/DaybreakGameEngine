#include <math.h>
#include "vec3.h"
#include "mat4.h"

#ifndef _QUATERNION_H_
#define _QUATERNION_H_

namespace daybreak {

	namespace math {

		struct Quaternion {
	
			float m_x, m_y, m_z, m_w;
		
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

			vec3 getForward();
			vec3 getBack();
			vec3 getRight();
			vec3 getLeft();
			vec3 getUp();
			vec3 getDown();

			inline float getX() { return m_x; }
			inline float getY() { return m_y; }
			inline float getZ() { return m_z; }
			inline float getW() { return m_w; }
		};
	}
}

#endif