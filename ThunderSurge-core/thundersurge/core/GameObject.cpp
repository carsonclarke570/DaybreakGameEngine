#include "GameObject.h"
#include "../components/GameComponent.h"

namespace thundersurge {

	namespace core {

		GameObject::GameObject() {
			m_children = std::vector<GameObject*>();
			m_components = std::vector<GameComponent*>();
			m_transform = new Transform();
			std::cout << m_transform << std::endl;
		}

		GameObject& GameObject::addChild(GameObject* child) {
			m_children.push_back(child);
			return *this;
		}
		GameObject& GameObject::addComponent(GameComponent* component) {
			m_components.push_back(component);
			component->setParent(this);
			return *this;
		}

		void GameObject::updateAll(float delta) {
			update(delta);

			for (int i = 0; i < m_children.size(); i++) {
				m_children[i]->update(delta);
			}
		}

		void GameObject::renderAll(Shader* shader) {
			render(shader);
			
			for (int i = 0; i < m_children.size(); i++) {
				m_children[i]->render(shader);
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