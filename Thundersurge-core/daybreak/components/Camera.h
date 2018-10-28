#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "GameComponent.h"

#include "../graphics/buffers/UniformBuffer.h"

namespace daybreak {

	namespace components {

		using namespace graphics;

		/**
			The Camera class implements a in-scene camera. This is essentially
			just a postion and a projection matrix bundled together and passed
			into whatever shader pass is being executed.

			NOTES:
			- There should only be one active camera per scene

			TO-DO
			- Reduce the frequency of calaculation to only when necessary.

			@author  Carson Clarke-Magrab
			@version 1.0
			@since   2018-10-27
		 */
		class Camera : public GameComponent {
		private:
			/**
				The matrix that will handle the camera projection.
			*/
			mat4 m_projection;
			/**
				A uniform buffer to ensure all shader's access the same view
				and projection matrices.
			*/
			UniformBuffer m_modelView;
		public:
			/**
				Creates a new Camera object.

				@params projection The projection matrix associated with the 
						camera
			*/
			Camera(const mat4& projection)
				: m_projection(projection), m_modelView(2 * sizeof(mat4), 0)  {
			}
			/**
				Gets the projection matrix

				@returns The projection matrix
			*/
			mat4 getProjection() {
				return m_projection;
			}
			/**
				Calculates the view matrix.

				@returns The view matrix.
			*/
			mat4 getView() {
				return getTransform()->getRotation().toRotationMatrix() * mat4::translation(getTransform()->getTranslation() *  vec3(-1, -1, -1));
			}
			/**
				Gets the camera's position.

				@returns The camera position.
			*/
			vec3 getPosition() {
				return getTransform()->getTranslation();	
			}
			/**
				No need to update anything.
			*/
			void update(float delta) {}
			/**
				Renders the camera by setting the active shader's model, view 
				and projection matrices.

				Inherited from GameComponent

				@param shader The active shader.
			*/
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