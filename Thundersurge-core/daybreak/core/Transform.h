#include "math/math.h"

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

namespace daybreak {

	namespace core {

		using namespace math;

		class Transform {
		private:
			vec3 m_trans;
			vec3 m_scale;
			Quaternion m_rot;
		public:
			Transform();

			mat4 getTransform();

			void rotate(const float angle, const vec3& axis);
			void translate(const vec3& trans);
			void scale(const vec3& scale);

			inline void setTranslation(const math::vec3& trans) { m_trans = trans; }
			inline void setScale(const math::vec3& scale) { m_scale = scale; }
			inline void setRotation(const float angle, const math::vec3& axis) { m_rot = Quaternion(axis, angle); }

			inline vec3& getScale() { return m_scale; }
			inline vec3& getTranslation() { return m_trans; }
			inline Quaternion& getRotation() { return m_rot; }

		};
	}
}

#endif