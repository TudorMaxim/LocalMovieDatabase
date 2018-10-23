#include "domain.h"
using namespace std;

Movie::Movie(string t, string g, int y, int ls, int d, string l) : title(t), genre(g), year(y), likes(ls), duration(d), link(l) {}

Movie::Movie(const Movie& other) {
	title = other.GetTitle();
	genre = other.GetGenre();
	year = other.GetYear();
	likes = other.GetLikes();
	link = other.GetLink();
	duration = other.GetDuration();
}

Movie& Movie::operator = (const Movie& film) {
	if (this == &film)
		return *this;

	this->title = film.title;
	this->genre = film.genre;
	this->year = film.year;
	this->likes = film.likes;
	this->link = film.link;
	this->duration = film.duration;
	return *this;
}

Movie::~Movie() {};

string Movie::GetTitle() const {
	return this->title;
}

string Movie::GetGenre() const {
	return this->genre;
}

int Movie::GetYear() const {
	return this->year;
}

int Movie::GetLikes() const {
	return this->likes;
}

int Movie::GetDuration() const {
	return this->duration;
}

string Movie::GetLink() const {
	return this->link;
}

void Movie::SetTitle(const string& t) {
	this->title = t;
}


void Movie::Play() {
	ShellExecuteA(NULL, NULL, "firefox.exe", this->GetLink().c_str(), NULL, SW_SHOWMAXIMIZED);
}

void Movie::IncrementLikes() {
	this->likes++;
}

/*
Function that adds an element to the array
input:
*this - the initial array
elem - the element that is added
output:
*this - the array containning the added element

Array <Movie> operator + (const Movie& elem, Array<Movie>& V) {
	V = V + elem;
	return V;
}*/

int toInt(const string& s) {
	int ret = 0;
	for (int i = 0; i < s.size(); i++) {
		ret = ret * 10 + (s[i] - '0');
	}
	return ret;
}

istream& operator >> (istream& in, Movie& film) {
	string line;
	getline(in, line, '\n');
	istringstream scanner(line);
	string token[6];
	for (int i = 0; i < 6; i++) {
		getline(scanner, token[i], ',');
	}
	film.title = token[0];
	film.genre = token[1];
	film.year = toInt(token[2]);
	film.likes = toInt(token[3]);
	film.link = token[5];
	film.duration = toInt(token[4]);
	return in;
}

ostream& operator << (ostream& out, const Movie& film) {
	out << film.GetTitle() << "," << film.GetGenre() << "," << film.GetYear() << "," << film.GetLikes() << "," << film.GetDuration() << "," << film.GetLink() << "\n";
	return out;
}