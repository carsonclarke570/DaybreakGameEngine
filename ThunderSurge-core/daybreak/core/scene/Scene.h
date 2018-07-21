#ifndef _SCENE_H_
#define _SCENE_H_

#include "../../components/GameComponent.h"
#include "../../components/Light.h"
#include "../../graphics/Forward.h"

namespace daybreak {

	namespace core {
	
		class Scene {
		private:
			GameObject* m_root;
			Shader* m_default;
			std::vector<BaseLight*> m_lights;

		public:
			Scene();
			~Scene();

			void update(float delta);
			void render();
			void addGameObject(GameObject* object);
			void addLight(BaseLight* light);

			GameObject* getRoot() { return m_root; }
		};
	}
}

#endif
