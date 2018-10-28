#include "Scene.h"

namespace daybreak {

	namespace core {

		Scene::Scene() {
			m_root = new GameObject();
			m_default = new Shader("daybreak/graphics/shaders/forward-lighting.vert", "daybreak/graphics/shaders/forward-default.frag");
#if NORMAL_DEBUG
			m_normals = new Shader("daybreak/graphics/shaders/normal-debug.vert", "daybreak/graphics/shaders/normal-debug.frag", "daybreak/graphics/shaders/normal-debug.geo", false);
#endif 
			PostFX::init();
		}

		Scene::~Scene() {
			delete m_root;
			delete m_default;
			delete m_skybox;
			for (Light* l : m_lights) {
				delete l;
			}
#if NORMAL_DEBUG
			delete m_normals;
#endif 
		}

		void Scene::update(float delta) {
			m_root->updateAll(delta);

			for (Light* light : m_lights) {
				light->update();
			}
		}

		void Scene::render() {
			PostFX::bind();

			m_root->renderAll(m_default);

#if NORMAL_DEBUG
			m_root->renderAll(m_normals);
#endif

			glEnable(GL_BLEND);
			glBlendFunc(GL_ONE, GL_ONE);
			glDepthMask(false);
			glDepthFunc(GL_EQUAL);

			for (Light* light : m_lights) {
				m_root->renderAll(light->shader);
			}

			glBlendFunc(GL_ZERO, GL_SRC_COLOR);
			m_root->renderAll();

			glDepthMask(true);
			glDisable(GL_BLEND);

			if (m_skybox != NULL) {
				glDepthFunc(GL_LEQUAL);
				m_skybox->render();
			}
			
			glDepthFunc(GL_LESS);
			PostFX::unbind();
			PostFX::render();
		}

		void Scene::addGameObject(GameObject* object) {
			m_root->addChild(object);
		}

		void Scene::addLight(Light* light) {
			m_lights.push_back(light);
		}

		void Scene::addSkybox(Skybox* skybox) {
			m_skybox = skybox;
		}
	}
}