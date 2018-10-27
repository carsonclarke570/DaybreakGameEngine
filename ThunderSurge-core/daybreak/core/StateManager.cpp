#include "StateManager.h"

namespace daybreak {

	namespace core {

		GameState* StateManager::m_activeState = nullptr;
		
		void StateManager::change(GameState* state) {
			if (m_activeState) {
				m_activeState->dispose();
			}

			m_activeState = state;

			if (state) {
				m_activeState->init();
			}
		}

		void StateManager::update(float delta) {
			if (m_activeState) {
				m_activeState->update(delta);
			}
		}

		void StateManager::render() {
			if (m_activeState) {
				m_activeState->render();
			}
		}
	}
}