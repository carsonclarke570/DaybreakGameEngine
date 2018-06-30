#include "CoreEngine.h"

namespace thundersurge {

	namespace core {

		CoreEngine::CoreEngine(Game* game) {
			Window::create(TITLE, WIDTH, HEIGHT);
			m_isRunning = false;
			m_game = game;

			Mouse::init();
			Keyboard::init();
		}

		CoreEngine::~CoreEngine() {
			Window::dispose();
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

			while (!Window::closed())
			{
				float delta = time.elapsed();
				time.reset();
				m_game->update(delta);

				Window::clear();
				m_game->render();
				Window::update();

				frames++;
				t += delta;
				if (t >= 1.0f) {
					printf("FPS: %d\n", frames);
					t = 0;
					frames = 0;
				}
			}
		}
	}
}