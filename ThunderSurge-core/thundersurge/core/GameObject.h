#pragma once

#include <vector>

#include "../core/CoreEngine.h"
#include "../core/Transform.h"
#include "../graphics/shader/Shader.h"

namespace thundersurge {

	namespace core {

		class GameComponent;

		class GameObject {
		private:
			std::vector<GameObject*> m_children;
			std::vector<GameComponent*> m_components;
			Transform* m_transform;
			CoreEngine* m_engine;

			void update(float delta);
			void render(Shader* shader);
		public:
			GameObject();
			
			GameObject& addChild(GameObject* child);
			GameObject& addComponent(GameComponent* component);

			void updateAll(float delta);
			void renderAll(Shader* shader);

			Transform* getTransform() const { return m_transform; }
		};
	}
}