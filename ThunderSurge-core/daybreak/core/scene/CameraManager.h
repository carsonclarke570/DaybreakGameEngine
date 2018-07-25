#ifndef _CAMERA_MANAGER_H_
#define _CAMERA_MANAGER_H_

#include "../../components/Camera.h"

namespace daybreak {
	
	namespace core {

		using namespace components;

		class CameraManager {
		private:
			static Camera* m_active;
		public:
			static void setActiveCamera(Camera* camera) {
				m_active = camera;
			}

			static Camera* getActiveCamera() {
				if (m_active == NULL) {
					Log::logErr("No active camera has been set! This will cause bugs.");
				}
				return m_active;
			}

		};
	}
}

#endif