#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include <unordered_map>
#include <string>

#include "../../utils/Log.h"

#include "Scene.h"

namespace daybreak {

	namespace core {

		class SceneManager {
		private:
			static Scene* m_activeScene;
			static std::string m_activeName;
			static std::unordered_map<std::string, Scene*> m_scenes;
		public:
			static void add(std::string name, Scene* scene);
			static Scene* get(std::string name);
			static void setActive(std::string name);
			static void setActive(Scene* scene);
			static std::string getActive();
			static void update(float delta);
			static void render();
		};
	}
}

#endif
