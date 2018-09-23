#ifndef _SCENE_H_
#define _SCENE_H_

#define NORMAL_DEBUG 1

#include "../../core/GameObject.h"

#include "../../components/ForwardLighting.h"
#include "../../components/Skybox.h"

#include "../../graphics/PostFX.h"

namespace daybreak {

	namespace core {

		using namespace graphics;

		class Scene {
		private:
			GameObject* m_root;
			Shader* m_default;
#if NORMAL_DEBUG
			Shader* m_normals;
#endif 
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
