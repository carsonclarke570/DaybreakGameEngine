#pragma once

#include <math.h>

namespace thundersurge {

	namespace math {

		class Quaternion {
		private:
			float m_x, m_y, m_z, m_w;
		public:
			Quaternion(float x, float y, float z, float w);

			float length() const;
			Quaternion normalize() const;
			Quaternion conjugate() const;

			Quaternion& mul(const Quaternion& other);

			friend Quaternion operator*(Quaternion left, const Quaternion& right);

			Quaternion& operator*=(const Quaternion& other);

			inline float getX() { return m_x; }
			inline float getY() { return m_y; }
			inline float getZ() { return m_z; }
			inline float getW() { return m_w; }
		};
	}
}