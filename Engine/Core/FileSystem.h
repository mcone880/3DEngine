#pragma once
#include <string>

namespace MAC {
	void SetFilePath(const std::string& pathName);
	std::string GetFilePath();
	bool ReadFileToString(const std::string& filename, std::string& filestring);
}