#include "math/math.h"
#include "Camera.h"

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

namespace thundersurge {

	namespace core {

		using namespace math;

		class Transform {
		private:
			vec3 m_trans;
			vec3 m_scale;
			Quaternion m_rot;

			static float m_zNear;
			static float m_zFar;
			static float m_aspect;
			static float m_fov;

			static Camera* m_camera;
		public:
			Transform();

			mat4 getTransform();
			mat4 getProjectedTransform();

			void rotate(const float angle, const vec3& axis);
			void translate(const vec3& trans);
			void scale(const vec3& scale);

			static void setProjection(float zNear, float zFar, float width, float height, float fov);

			inline void setTranslation(const math::vec3& trans) { m_trans = trans; }
			inline void setScale(const math::vec3& scale) { m_scale = scale; }
			inline void setRotation(const float angle, const math::vec3& axis) { m_rot = Quaternion(axis, angle); }

			inline vec3& getScale() { return m_scale; }
			inline vec3& getTranslation() { return m_trans; }

			static inline void setCamera(Camera* camera) { m_camera = camera; }
			static inline Camera* getCamera() { return m_camera; }
		};
	}
}

#endif