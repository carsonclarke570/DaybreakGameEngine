#include "UIContainer.h"
#include "UIElement.h"

namespace daybreak {

	namespace components {

		UIContainer::UIContainer() {
			m_elements = std::vector<UIElement*>();
		}
		
		UIContainer::~UIContainer() {
			for (UIElement* e : m_elements) {
				delete e;
			}
			m_elements.clear();
		}

		void UIContainer::render(Shader* shader) {
			for (UIElement* e : m_elements) {
				e->render();
			}
		}
		
		void UIContainer::update(float delta) {
			for (UIElement* e : m_elements) {
				e->update(delta);
			}
		}
		
		void UIContainer::addElement(UIElement* element) {
			m_elements.push_back(element);
		}
	}
}