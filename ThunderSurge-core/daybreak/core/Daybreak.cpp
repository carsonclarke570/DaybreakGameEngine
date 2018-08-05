#include "Daybreak.h"

namespace daybreak {

	namespace core {

		Game* Daybreak::m_game = nullptr;
		bool Daybreak::m_isRunning = false;

		void Daybreak::load(Game* game) {
			Window::create(TITLE, WIDTH, HEIGHT);
			m_game = game;

			Mouse::init();
			Keyboard::init();
		}

		void Daybreak::start() {
			if (m_isRunning) {
				return;
			}
			run();
		}

		void Daybreak::stop() {
			if (!m_isRunning) {
				return;
			}
			m_isRunning = false;
		}

		void Daybreak::run() {
			float t = 0;
			unsigned int frames = 0;

			m_game->init();

			Timer time, system;
			float nextTick = system.elpasedMilliseconds();
			float sleepTime = 0;

			while (!quit())
			{
				float delta = time.elapsedSeconds();
				time.reset();
				m_game->update(delta);

				Window::clear();
				m_game->render();
				Window::update();

				nextTick += SKIP_TICKS;
				sleepTime = nextTick - system.elpasedMilliseconds();
				if (sleepTime >= 0) {
					std::this_thread::sleep_for(std::chrono::milliseconds((int)sleepTime));
				}
			}
			Window::dispose();
		}

		bool Daybreak::quit() {
			return Window::closed() || m_game->quit();
		}
	}
}