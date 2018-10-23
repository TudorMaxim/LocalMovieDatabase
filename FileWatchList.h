#pragma once

#include "repository.h"

class FileWatchList : public Repository {
protected:
	std::string file_name;

public:
	FileWatchList(std::string name) : file_name(name) {};
	virtual ~FileWatchList() {}

	virtual void displayWatchList() const = 0;
	virtual void readFromFile() = 0;
	virtual void writeToFile() = 0;
};