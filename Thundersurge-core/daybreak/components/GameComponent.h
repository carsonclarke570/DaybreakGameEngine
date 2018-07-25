#ifndef _GAME_COMPONENT_H_
#define _GAME_COMPONENT_H_

#include "../core/GameObject.h"

namespace daybreak {

	namespace core {

		class GameComponent {
		private:
			GameObject* m_parent;
		public:
			virtual void update(float delta) = 0;
			virtual void render(Shader* shader) = 0;
			//void addToScene(Scene* scene) { } 

			inline void setParent(GameObject* parent) { m_parent = parent; }

			inline Transform* getTransform() { return m_parent->getTransform(); }
		};
	}
}

#endif 