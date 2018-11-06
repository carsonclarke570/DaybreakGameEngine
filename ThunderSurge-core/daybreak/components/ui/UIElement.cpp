#include "UIElement.h"

namespace daybreak {

	namespace components {
		
		UIElement::UIElement() {
			m_transform = new Transform();
		}

		UIElement::~UIElement() {
			delete m_transform;
		}

		mat4& UIElement::getTransform() {
			mat4 res = m_transform->getTransform();
			if (m_parent) {
				res = res * m_parent->getTransform()->getTransform();
				return res;
			}
			return res;
		}
	}
}