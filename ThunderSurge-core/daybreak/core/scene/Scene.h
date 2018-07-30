#ifndef _SCENE_H_
#define _SCENE_H_

#include "../../core/GameObject.h"
#include "../../components/ForwardLighting.h"
#include "../../components/Skybox.h"

namespace daybreak {

	namespace core {

		class Scene {
		private:
			GameObject* m_root;
			Shader* m_default;
			Skybox* m_skybox;
			std::vector<Light*> m_lights;
		public:
			Scene();
			~Scene();

			void update(float delta);
			void render();
			void addGameObject(GameObject* object);
			void addLight(Light* light);
			void addSkybox(Skybox* skybox);

			GameObject* getRoot() { return m_root; }
		};
	}
}

#endif
