#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <memory>
#include <shellapi.h>

class Movie {
private:
	std::string title;
	std::string genre;
	int year;
	int likes;
	int duration;
	std::string link;
	//friend Array <Movie> operator + (const Movie& elem, Array<Movie>& V);

public:
	//Default constructor
	Movie() {}

	//Creates a movie
	Movie(std::string title, std::string genre, int year, int likes, int d, std::string link);

	//Copy constructor
	Movie(const Movie& other);

	//Assignment operator
	Movie& operator = (const Movie& film);

	//Destructor
	~Movie();

	//Equality operator
	bool operator == (const Movie& other) {
		return this->title == other.GetTitle();
	}
	//Inequality operator
	inline bool operator != (const Movie& other) {
		return this->title != other.GetTitle();
	}

	//Less operator
	inline bool operator < (const int& t) {
		return this->duration < t;
	}

	//Getters
	std::string GetTitle() const;
	std::string GetGenre() const;
	int GetYear() const;
	int GetLikes() const;
	int GetDuration() const;
	std::string GetLink() const;

	const Movie& self() {
		return *this;
	}

	//Setter for title
	void SetTitle(const std::string& t);
	void SetGenre(const std::string& t) { this->genre = t;  }
	void SetYear(int t) { this->year = t; }
	void SetLikes(int t) { this->likes = t; }
	void SetDuration(int t) { this->duration = t; }
	void SetLink(const std::string& t) { this->link = t; }
	//play the triler
	void Play();

	void IncrementLikes();

	friend int toInt(const std::string& s);
	friend std::istream& operator >> (std::istream& in, Movie& film);
	friend std::ostream& operator << (std::ostream& out, const Movie& film);
};