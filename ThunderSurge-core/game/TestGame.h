#ifndef _TEST_
#define _TEST_

#include "MenuState.h"

#include "../daybreak/core/StateManager.h"


namespace daybreak {

	namespace core {

		using namespace math;
		using namespace graphics;
		using namespace input;

		class TestGame : public Game {
		private:
			GameState* m_menu;
		public:
			TestGame() {
				m_menu = new MenuState();
			} 

			~TestGame() {
				m_menu->dispose();
				delete m_menu;
			}

			void init() {
				m_menu->init();
			}

			void update(float delta) {
				m_menu->update(delta);
			}

			void render() {
				m_menu->render();
			}

			bool quit() {
				return false;
			}
		};
	}
}

#endif