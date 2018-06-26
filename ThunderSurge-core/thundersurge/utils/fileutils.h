#pragma once

#include <string>
#include <fstream>

namespace thundersurge {

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
	};
}