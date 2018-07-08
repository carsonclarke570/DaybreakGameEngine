#ifndef _LOG_H_
#define _LOG_H_

#include <ctime>
#include <chrono>

namespace thundersurge {

	using namespace std::chrono;

	class Log {
	private:
		static bool enabled;
	public:
		static void log(const char* message) {
			time_t now = system_clock::to_time_t(system_clock::now());
			if (enabled)
				printf("[%s] %s", ctime(&now), message);
		}
	};

	bool Log::enabled = true;
}

#endif

