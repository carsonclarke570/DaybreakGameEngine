#define WIDTH 960
#define HEIGHT 540
#define TITLE "Game"

#include "Game.h"

#include "../graphics/Window.h"
#include "../utils/Timer.h"
#include "../core/Transform.h"
#include "../utils/Log.h"

#ifndef _CORE_ENGINE_H_
#define _CORE_ENGINE_H_

namespace daybreak {

	namespace core {

		using namespace graphics;

		class CoreEngine {
		private:
			Game* m_game;
			bool m_isRunning;

			void run();
			bool quit();
		public:
			CoreEngine(Game* game);
			~CoreEngine();

			void start();
			void stop();
		};
	}
}

#endif