#ifndef _CORE_ENGINE_H_
#define _CORE_ENGINE_H_

#define WIDTH 960
#define HEIGHT 540
#define TITLE "Game"

#define FPS_CAP 500
#define SKIP_TICKS (1000 / FPS_CAP)

#include "Game.h"

#include "../core/Window.h"
#include "../utils/Timer.h"
#include "../core/Transform.h"
#include "../utils/Log.h"

#include <chrono>
#include <thread>

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