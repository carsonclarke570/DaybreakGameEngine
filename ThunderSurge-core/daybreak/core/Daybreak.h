#ifndef _CORE_ENGINE_H_
#define _CORE_ENGINE_H_

#define WIDTH 960
#define HEIGHT 540
#define TITLE "Game"

#include "Game.h"

#include "../core/Window.h"
#include "../utils/Timer.h"
#include "../core/Transform.h"
#include "../utils/Log.h"

namespace daybreak {

	namespace core {

		class Daybreak {
		private:
			static Game* m_game;
			static bool m_isRunning;

			static void run();
			static bool quit();
		public:

			static void load(Game* game);
			static void start();
			static void stop();
		};
	}
}

#endif