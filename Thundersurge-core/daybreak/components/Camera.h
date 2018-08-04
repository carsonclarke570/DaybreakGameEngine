#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "GameComponent.h"

#include "../graphics/buffers/UniformBuffer.h"

namespace daybreak {

	namespace components {

		using namespace graphics;

		class Camera : public GameComponent {
		private:
			mat4 m_projection;
			UniformBuffer m_modelView;
		public:
			Camera(const mat4& projection)
				: m_projection(projection), m_modelView(2 * sizeof(mat4), 0)  {
			}

			~Camera() {

			}

			mat4 getProjection() {
				return m_projection;
			}

			mat4 getView() {
				return getTransform()->getRotation().toRotationMatrix() * mat4::translation(getTransform()->getTranslation() *  vec3(-1, -1, -1));
			}

			vec3 getPosition() {
				return getTransform()->getTranslation();
			}

			void update(float delta) {}

			void render(Shader* shader) {
				m_modelView.setData(0, getView());
				m_modelView.setData(sizeof(mat4), getProjection());
				shader->enable();
				shader->setUniform3f("viewPos", getPosition());
				shader->disable();
			}

			
		};
	}
}

#endif