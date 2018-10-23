#pragma once
#include "FileWatchList.h"

class HTMLWatchList : public FileWatchList {
public:
	HTMLWatchList(const std::string& filename) : FileWatchList(filename) { readFromFile(); }

	void writeToFile() override;

	void displayWatchList() const override;

	void readFromFile() override;
};


