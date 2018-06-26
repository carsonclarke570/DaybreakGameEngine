#include "CoreEngine.h"

namespace thundersurge {

	namespace core {

		CoreEngine::CoreEngine(Game* game) {
			m_window = new Window(TITLE, WIDTH, HEIGHT);
			m_isRunning = false;
			m_game = game;

			Mouse::init();
			Keyboard::init();
		}

		CoreEngine::~CoreEngine() {
			delete m_window;
			delete m_game;
		}

		void CoreEngine::start() {
			if (m_isRunning) {
				return;
			}
			run();
		}

		void CoreEngine::stop() {
			if (!m_isRunning) {
				return;
			}
			m_isRunning = false;
		}

		void CoreEngine::run() {

			Timer time;
			float t = 0;
			unsigned int frames = 0;

			m_game->init();

			while (!m_window->closed())
			{
				m_game->update();

				m_window->clear();
				m_game->render();
				m_window->update();

				frames++;
				if (time.elapsed() - t > 1.0f) {
					t++;
					printf("FPS: %d\n", frames);
					frames = 0;
				}
			}
		}
	}
}