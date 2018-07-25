#include "Scene.h"

namespace daybreak {

	namespace core {

		Scene::Scene() {
			m_root = new GameObject();
			m_default = new AmbientShader();
		}

		Scene::~Scene() {
			delete m_root;
		}

		void Scene::update(float delta) {
			m_root->updateAll(delta);
		}

		void Scene::render() {
			m_root->renderAll(m_default);

			glEnable(GL_BLEND);
			glBlendFunc(GL_ONE, GL_ONE);
			glDepthMask(false);
			glDepthFunc(GL_EQUAL);

			for (Light* light : m_lights) {
				m_root->renderAll(light->shader);
			}

			glDepthMask(true);
			glDisable(GL_BLEND);

			/*if (m_skybox != NULL) {
				glDepthFunc(GL_LEQUAL);
				m_skybox->render(m_skyboxShader);  
			} */

			glDepthFunc(GL_LESS);
		}

		void Scene::addGameObject(GameObject* object) {
			m_root->addChild(object);
		}

		void Scene::addLight(Light* light) {
			m_lights.push_back(light);
		}
	}
}