#pragma once
#include "CSVWatchList.h"
#include "HTMLWatchList.h"
#include "undo.h"
#include <stack>

class Controller {
private:
	Repository repo;
	FileWatchList* watchList;
	MovieValidator validator;
	std::stack<std::shared_ptr <UndoAction> > undoAdmin;
	std::stack<std::shared_ptr <UndoAction> > redoAdmin;
	std::stack<std::shared_ptr <UndoAction> > undoUser;
	std::stack<std::shared_ptr <UndoAction> > redoUser;

public:
	//Default contructor
	Controller();

	Controller(Repository& r, FileWatchList* wl, MovieValidator& v);

	//Default destructor
	~Controller();

	//Return an array containning all the movies from the controller
	std::vector <Movie> GetAll() const;

	/*
	Function that adds a movie to the controller
	input:
	film - the movie that is added
	*this - the inital controller
	output:
	*this - the controller after the movie was added
	*/
	void Add(const Movie& film);

	/*
	Function that deletes a movie from the controller
	input:
	film - the movie that is deleted
	*this - the inital controller
	output:
	*this - the controller after the movie was deleted
	*/
	void Delete(const std::string& title);

	/*
	Function that updates a movie on a given position from the controller
	input:
	pos - the position of the movie that is updated
	newFilm - the new movie
	*this - the inital controller
	output:
	*this - the controller after the movie on the given position was updated
	*/
	void Update(const std::string& title, const Movie& newFilm);

	/*
	Function that filters the database of movies according to a given genre
	input:
	genre - a string pattern that is searched
	output:
	an Array of movies containning the filtered list of movies.
	*/
	std::vector<Movie> FilterByGenre(const std::string& genre);

	void GiveLike(const std::string& title);

	std::vector <Movie> FilterByDuration(const int& d);

	void saveToFile();


	void AddToWatchList(const Movie& film);

	void DeleteFromWatchList(const std::string& title);

	std::vector <Movie> GetWatchList() const;

	void DisplayWatchList();

	void UndoAdmin();
	void UndoUser();
	void RedoAdmin();
	void RedoUser();

};