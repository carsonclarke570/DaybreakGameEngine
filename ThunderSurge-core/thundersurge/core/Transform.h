#pragma once

#include "math/math.h"
#include "Camera.h"

namespace thundersurge {

	namespace core {

		class Transform {
		private:
			math::vec3 m_trans;
			math::vec3 m_scale;
			math::vec3 m_rotAxis;
			float m_rotAngle;

			static float m_zNear;
			static float m_zFar;
			static float m_aspect;
			static float m_fov;

			static Camera* m_camera;
		public:
			Transform();

			math::mat4 getTransform();
			math::mat4 getProjectedTransform();

			static void setProjection(float zNear, float zFar, float width, float height, float fov);

			inline void setTranslation(const math::vec3& trans) { m_trans = trans; }
			inline void setScale(const math::vec3& scale) { m_scale = scale; }
			inline void setRotation(const float angle, const math::vec3& axis) { m_rotAngle = angle; m_rotAxis = axis; }
			
			static inline void setCamera(Camera* camera) { m_camera = camera; }
		};
	}
}