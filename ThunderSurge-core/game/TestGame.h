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
		public:
			TestGame() {
			} 

			~TestGame() {
			}

			void init() {
				StateManager::change(new MenuState());
			}

			void update(float delta) {
				StateManager::update(delta);
			}

			void render() {
				StateManager::render();
			}

			bool quit() {
				return false;
			}
		};
	}
}

#endif