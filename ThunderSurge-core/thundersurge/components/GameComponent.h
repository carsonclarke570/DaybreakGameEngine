#pragma once

#include "../core/GameObject.h"

namespace thundersurge {

	namespace core {

		class GameObject;

		class GameComponent {
		private:
			GameObject m_parent;
		public:
			virtual void update(float delta) = 0;
			virtual void render(Shader* shader) = 0;

			inline void setParent(const GameObject& parent) { m_parent = parent; }
			inline Transform* getTransform() { return m_parent.getTransform(); }
		};
	}
}