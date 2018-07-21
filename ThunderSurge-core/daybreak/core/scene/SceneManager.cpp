#include "SceneManager.h"

namespace daybreak {

	namespace core {

		Scene* SceneManager::m_activeScene = NULL;
		std::string SceneManager::m_activeName = "";
		std::unordered_map<std::string, Scene*> SceneManager::m_scenes;
		
		void SceneManager::add(std::string name, Scene* scene) {
			m_scenes[name] = scene;
		}

		Scene* SceneManager::get(std::string name) {
			if (!m_scenes[name]) {
				char* message = new char[28 + name.size()];
				sprintf(message, "Scene \"%s\" does not exist", name.c_str());
				Log::logErr(message);
				delete message;
				exit(0);
			}
			return m_scenes[name];
		}

		void SceneManager::setActive(std::string name) {
			if (!m_scenes[name]) {
				char* message = new char[28 + name.size()];
				sprintf(message, "Scene \"%s\" does not exist", name.c_str());
				Log::logErr(message);
				delete message;
				exit(0);
			}
			m_activeScene = m_scenes[name];
			m_activeName = name;
		}

		void SceneManager::setActive(Scene* scene) {
			m_activeScene = scene;
			m_activeName = "";
		}

		std::string SceneManager::getActive() {
			return m_activeName;
		}

		void SceneManager::update(float delta) {
			if (m_activeScene != NULL) {
				m_activeScene->update(delta);
			}
		}

		void SceneManager::render() {
			if (m_activeScene != NULL) {
				m_activeScene->render();
			}
		}
	}
}
