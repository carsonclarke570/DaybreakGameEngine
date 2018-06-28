#pragma once

#include "Transform.h"

namespace thundersurge {

	namespace core {

		float Transform::m_aspect = 16.0f / 9.0f;
		float Transform::m_fov = 70.0f;
		float Transform::m_zFar = 1000.0f;
		float Transform::m_zNear = 0.1f;

		Camera* Transform::m_camera = new Camera();

		Transform::Transform() {
			m_trans = math::vec3(0, 0, 0);
			m_scale = math::vec3(1, 1, 1);
			m_rotAxis = math::vec3(0, 0, 0);
			m_rotAngle = 0;
		}

		math::mat4 Transform::getTransform() {
			using namespace math;
			
			return mat4::translation(m_trans) * (mat4::rotation(m_rotAngle, m_rotAxis) * mat4::scale(m_scale));
		}

		math::mat4 Transform::getProjectedTransform() {
			using namespace math;

			mat4 transform = mat4::translation(vec3(-m_camera->getPosition().m_x, -m_camera->getPosition().m_y, -m_camera->getPosition().m_z));
			transform = mat4::camera(m_camera->getForward(), m_camera->getUp()) * (transform * getTransform());

			return mat4::perspective(m_fov, m_aspect, m_zNear, m_zFar) * transform;
		}

		void Transform::setProjection(float zNear, float zFar, float width, float height, float fov) {
			m_fov = fov;
			m_aspect = width / height;
			m_zFar = zFar;
			m_zNear = zNear;
		}
	}
}