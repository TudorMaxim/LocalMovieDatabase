#pragma once
#include "domain.h"
#include "domainValidator.h"
#include "repositoryExceptions.h"
#include <vector>
#include <algorithm>

class Repository {
protected:
	std::vector <Movie> V;
	std::string file_name;

public:
	//Default constructor
	Repository() {}
	Repository(const std::string& file);

	//Default destructor
	~Repository();

	/*
	Function that adds a movie to the repository
	input:
	film - the movie that is added
	*this - the inital repository
	output:
	*this - the repository after the movie was added
	*/
	void Add(const Movie& film);

	/*
	Function that deletes a movie from the repository
	input:
	film - the movie that is deleted
	*this - the inital repository
	output:
	*this - the repository after the movie was deleted
	*/
	void Delete(const Movie& film);

	/*
	Function that updates a movie on a given position from the repository
	input:
	it - an iterator
	newFilm - the new movie
	*this - the inital repository
	output:
	*this - the repository after the movie on the given position was updated
	*/
	void Update(std::vector<Movie>::iterator& it, const Movie& newFilm);

	/*
	Function that finds a movie in the repository.
	input:
	film - the movie that is searched
	*this - the repository
	output:
	return the position  which has the current element the searched movie
	*/
	std::vector<Movie>::iterator Find(const Movie& film);
	Movie findMovie(const std::string& title);

	//Return the size of the repository
	int Size() const;

	//Return an array containning all the movies from the repository
	std::vector <Movie> GetAll() const;

	//Get the element on a given position
	Movie& GetElement(std::vector<Movie>::iterator it);

	std::vector <Movie>::iterator Begin();
	std::vector <Movie>::iterator End();

	std::vector <Movie> :: iterator getIterator(int index) {
		int i = 0;
		for (std::vector <Movie>::iterator it = V.begin(); it != V.end(); it++) {
			if (i == index) return it;
			i++;
		}
		return V.end();
	}
	void readFromFile();
	void writeToFile();

};