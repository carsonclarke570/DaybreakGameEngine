#ifndef _LOG_H_
#define _LOG_H_

#include <ctime>
#include <chrono>

namespace aurora {

	using namespace std::chrono;

	class Log {
	private:
		inline static char* getTime() {
			time_t now = system_clock::to_time_t(system_clock::now());
			char* time = ctime(&now);
			time[24] = 0;
			return time;
		}
	public:
		static void log(const char* message) {
			if (true) {
				printf("[%s] %s\n", getTime(), message);
			}
		}

		static void logOk(const char* message) {
			if (true) {
				printf("[%s]\tOK:  %s\n", getTime(), message);
			}
		}

		static void logErr(const char* message) {
			if (true) {
				printf("[%s] ERROR: %s\n", getTime(), message);
			}
		}
	};
}

#endif

