#ifndef _TIMER_H_
#define _TIMER_H_

#include <chrono>

namespace daybreak {

	using namespace std::chrono;

	class Timer {
	private:
		typedef high_resolution_clock Clock;
		Clock::time_point m_epoch;
	public:
		Timer() {
			m_epoch = Clock::now();
		}

		void reset() {
			m_epoch = Clock::now();
		}

		float elapsed() {
			return duration_cast<microseconds>(Clock::now() - m_epoch).count() / 1000000.0f;
		}
	};
}

#endif