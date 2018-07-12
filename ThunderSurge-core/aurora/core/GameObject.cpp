#include "GameObject.h"
#include "../components/GameComponent.h"

namespace aurora {

	namespace core {

		GameObject::GameObject() {
			m_children = std::vector<GameObject*>();
			m_components = std::vector<GameComponent*>();
			m_localTransform = new Transform();
		}

		GameObject& GameObject::addChild(GameObject* child) {
			m_children.push_back(child);
			child->m_parentTransform = m_localTransform;
			return *this;
		}
		GameObject& GameObject::addComponent(GameComponent* component) {
			m_components.push_back(component);
			component->setParent(this);
			return *this;
		}

		void GameObject::updateAll(float delta) {
			if (m_parentTransform != NULL) {
				m_localTransform->setTranslation(m_localTransform->getTranslation() + m_parentTransform->getTranslation());
			}
			
			update(delta);

			for (int i = 0; i < m_children.size(); i++) {
				m_children[i]->updateAll(delta);
			}
		}

		void GameObject::renderAll(Shader* shader) {
			render(shader);
			
			for (int i = 0; i < m_children.size(); i++) {
				m_children[i]->renderAll(shader); /// parent * m_relative
			}
		}

		void GameObject::update(float delta) {
			for (int i = 0; i < m_components.size(); i++) {
				m_components[i]->update(delta);
			}
		}

		void GameObject::render(Shader* shader) {
			for (int i = 0; i < m_components.size(); i++) {
				m_components[i]->render(shader);
			}
		}
	}
}