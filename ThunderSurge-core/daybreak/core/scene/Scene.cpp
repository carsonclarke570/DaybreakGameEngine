#include "Scene.h"

namespace daybreak {

	namespace core {

		Scene::Scene() {
			m_root = new GameObject();
			m_default = new Ambient();
		}

		Scene::~Scene() {
			delete m_root;
		}

		void Scene::update(float delta) {
			m_root->updateAll(delta);
		}

		void Scene::render() {
			m_root->renderAll(m_default);
		}

		void Scene::addGameObject(GameObject* object) {
			m_root->addChild(object);
		}
	}
}