#include "UIElement.h"

namespace daybreak {

	namespace core {
		
		UIElement::UIElement() {
			m_children = std::vector<UIElement*>();
		}

		void UIElement::updateAll(float delta) {
			update(delta);
			for (child : m_children) {
				child.updateAll(delta);
			}
		}

		void UIElement::renderAll() {
			render();
			for (child : m_children) {
				child.renderAll();
			}
		}
	}
}