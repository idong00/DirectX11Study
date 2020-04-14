#pragma once
#include <string>

class StringHelper {
public:
	static std::wstring StringToWide(std::string std);
	static std::string GetDirectoryFromPath(const std::string & filepath);
	static std::string GetFileExtension(const std::string & filename);
};