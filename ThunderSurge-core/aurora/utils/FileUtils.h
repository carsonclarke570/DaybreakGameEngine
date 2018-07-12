#include <string>
#include <vector>
#include <fstream>

#ifndef _FILE_UTIL_H_
#define _FILE_UTIL_H_

namespace aurora {

	class FileUtils {
	public:
		static std::string read_file(const char* filepath) {
			FILE* file = fopen(filepath, "rt");
			fseek(file, 0, SEEK_END);
			unsigned long len = ftell(file);
			char* data = new char[len + 1];
			memset(data, 0, len + 1);
			fseek(file, 0, SEEK_SET);
			fread(data, 1, len, file);
			fclose(file);

			std::string result(data);
			delete[] data;
			return result;
		}

		static std::vector<std::string> split(const std::string& string, const char delim) {
			size_t start = 0;
			size_t end = string.find_first_of(delim);

			std::vector<std::string> result;

			while (end <= std::string::npos) {
				result.emplace_back(string.substr(start, end - start));

				if (end == std::string::npos) {
					break;
				}

				start = end + 1;
				end = string.find_first_of(delim, start);
			}

			return result;
		}
	};
}

#endif