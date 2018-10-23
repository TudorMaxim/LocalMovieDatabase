#include "repository.h"
using namespace std;

Repository::Repository(const string& file) {
	this->file_name = file;
	this->readFromFile();
}

Repository::~Repository() {}

void Repository::Add(const Movie& film) {
	V.push_back(film);
}

void Repository::Delete(const Movie& film) {
	V.erase(this->Find(film));
}

void Repository::Update(vector <Movie>::iterator& it, const Movie& newFilm) {
	*it = newFilm;
}

vector<Movie>::iterator Repository::Find(const Movie& film) {
	vector <Movie>::iterator it = find(V.begin(), V.end(), film);
	return it;
}

Movie Repository::findMovie(const std::string& title) {
	for (int i = 0; i < V.size(); i++)
		if (V[i].GetTitle() == title) return V[i];
	return V[0];
}
int Repository::Size() const {
	return V.size();
}

vector <Movie> Repository::GetAll() const {
	return V;
}

Movie& Repository::GetElement(vector <Movie>::iterator it) {
	return *it;
}

vector <Movie>::iterator Repository::Begin() {
	return V.begin();
}
vector <Movie>::iterator Repository::End() {
	return V.end();
}

void Repository::readFromFile() {
	Movie film;
	ifstream fin;
	fin.open(file_name);
	if (!fin.is_open()) {
		throw(FileException("The file could not be opened! \n"));
	}
	while (fin >> film) {
		V.push_back(film);
	}
	fin.close();
}

void Repository::writeToFile() {
	ofstream fout;
	fout.open(file_name);
	if (!fout.is_open()) {
		throw(FileException("The file could not be opened! \n"));
	}
	for (const Movie& film : V) {
		fout << film;
	}
	fout.close();
}