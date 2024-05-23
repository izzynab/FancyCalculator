#pragma once

#include <string>

class History {

public:
	History(const std::string& filePath);
	void save(const std::string& operation);
	std::string load() const;
};