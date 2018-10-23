#include "CSVWatchList.h"

using namespace std;

void CSVWatchList::writeToFile() {
	ofstream fout(this->file_name);

	if (!fout.is_open())
		throw FileException("The file could not be opened!");

	for (auto f : this->V)
		fout << f;

	fout.close();
}

void CSVWatchList::displayWatchList() const {
	string aux = "\"" + this->file_name + "\"";
	ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\Microsoft Office\\Office14\\EXCEL.EXE", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}

void CSVWatchList::readFromFile() {
	Movie film;
	ifstream fin;
	fin.open(this->file_name);
	if (!fin.is_open()) {
		throw(FileException("The file could not be opened! \n"));
	}
	while (fin >> film && !fin.eof()) {
		this->V.push_back(film);
	}
	fin.close();
}