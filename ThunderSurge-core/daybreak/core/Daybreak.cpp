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

			Timer time;
			float t = 0;
			unsigned int frames = 0;

			m_game->init();

			while (!quit())
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
					char message[14];
					sprintf(message, "FPS: %d", frames);
					Log::log(message);
					t = 0;
					frames = 0;
				}
			}
			Window::dispose();
		}

		bool Daybreak::quit() {
			return Window::closed() || m_game->quit();
		}
	}
}