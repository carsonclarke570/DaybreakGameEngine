#include <vector>

#include "../core/Daybreak.h"
#include "../graphics/Shader.h"

#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

namespace daybreak {

	namespace core {

		using namespace graphics;

		class GameComponent;

		class GameObject {
		private:
			std::vector<GameObject*> m_children;
			std::vector<GameComponent*> m_components;
			Transform* m_localTransform;
			Transform* m_parentTransform;

			void update(float delta);
			void render(Shader* shader);
			void render();
		public:
			GameObject();
			~GameObject();
			
			GameObject* addChild(GameObject* child);
			GameObject* addComponent(GameComponent* component);

			void updateAll(float delta);
			void renderAll(Shader* shader);
			void renderAll();
		
			inline Transform* getTransform() { return m_localTransform; }
		};
	}
}

#endif