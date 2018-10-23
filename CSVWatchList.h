#pragma once
#include "FileWatchList.h"

class CSVWatchList : public FileWatchList
{
public:
	CSVWatchList(const std::string& filename) : FileWatchList(filename) { readFromFile(); }

	void writeToFile() override;

	void displayWatchList() const override;

	void readFromFile() override;
};

