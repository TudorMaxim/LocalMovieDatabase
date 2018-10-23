#include "controller.h"

using namespace std;

Controller::Controller() {}

Controller::Controller(Repository& r, FileWatchList* wl, MovieValidator& v) : repo(r), watchList(wl), validator(v) { }

Controller::~Controller() { }

vector <Movie> Controller::GetAll() const {
	return repo.GetAll();
}

void Controller::Add(const Movie& film) {
	this->validator.validate(film);
	vector<Movie>::iterator it = repo.Find(film);
	if (it == repo.End()) {
		repo.Add(film);
		undoAdmin.push(make_shared <UndoAdd> (this->repo, film));
	}
	else
		throw(DuplicateMovieException());

}

void Controller::Delete(const string& title) {
	if (repo.Size() == 0)
		throw (EmptyWatchListException());

	Movie film;
	film.SetTitle(title);
	vector<Movie>::iterator it = repo.Find(film);

	if (it == repo.End())
		throw (InexistentMovieException());

	film = repo.findMovie(title);
	repo.Delete(repo.findMovie(title));
	undoAdmin.push(make_shared <UndoRemove> (this->repo, film));

}

void Controller::Update(const std::string& title, const Movie& newFilm) {
	Movie film;
	film.SetTitle(title);
	vector<Movie>::iterator it = repo.Find(film);
	if (it == repo.End())
		throw (InexistentMovieException());

	this->validator.validate(newFilm);
	film = repo.findMovie(title);
	repo.Update(it, newFilm);
	undoAdmin.push(make_shared <UndoUpdate> (this->repo, newFilm, film));
}


vector <Movie> Controller::FilterByGenre(const std::string& genre) {
	vector <Movie> V = repo.GetAll();
	if (genre == "") {
		return V;
	}
	vector <Movie> Interested;
	copy_if(V.begin(), V.end(), back_inserter(Interested), [genre](Movie m) {
		istringstream is(genre);
		string g;
		while (is >> g) 
			if (m.GetGenre().find(g) != string::npos) return true;
		return false;
	});
	return Interested;
}

void Controller::GiveLike(const string& title) {
	Movie searched;
	searched.SetTitle(title);
	vector<Movie>::iterator it = repo.Find(searched);
	if (it == repo.End())
		throw(InexistentMovieException());

	Movie film = repo.GetElement(it);
	film.IncrementLikes();
	repo.Update(it, film);
}

vector <Movie> Controller::FilterByDuration(const int& d) {
	vector <Movie> V = repo.GetAll();
	vector <Movie> Interested;
	copy_if(V.begin(), V.end(), back_inserter(Interested), [d](Movie m) {return m < d;  });
	return Interested;
}

void Controller::saveToFile() {
	repo.writeToFile();
	watchList->writeToFile();
}

void Controller::AddToWatchList(const Movie& film) {
	this->validator.validate(film);
	vector<Movie>::iterator it = watchList->Find(film);
	if (it == watchList->End()) {
		watchList->Add(film);
		undoUser.push(make_shared <UndoAddToWatchList>(this->watchList, film));
	}
	else
		throw(DuplicateMovieException());
}

void Controller::DeleteFromWatchList(const string& title) {
	if (watchList->Size() == 0)
		throw (EmptyWatchListException());

	Movie film;
	film.SetTitle(title);
	vector<Movie>::iterator it = watchList->Find(film);
	if (it != watchList->End()) {
		film = watchList->findMovie(title);
		watchList->Delete(film);
		undoUser.push(make_shared <UndoRemoveFromWatchList> (this->watchList, film));
	}
	else
		throw (InexistentMovieException());

}

vector <Movie> Controller::GetWatchList() const {
	return watchList->GetAll();
}

void Controller::DisplayWatchList() {
	watchList->writeToFile();
	watchList->displayWatchList();
}

void Controller::UndoAdmin() {
	if (this->undoAdmin.empty())
		throw RepositoryException("Nothing to undo right now! \n");
	try {
		std::shared_ptr <UndoAction> last =  undoAdmin.top();
		last->executeUndo();
		undoAdmin.pop();
		this->redoAdmin.push(last);
	}
	catch (RepositoryException& e) {
		cout << e.what() << "\n";
	}
}

void Controller::RedoAdmin() {
	if (this->redoAdmin.empty())
		throw RepositoryException("Nothing to redo right now! \n");
	try {
		std::shared_ptr <UndoAction> last =  (redoAdmin.top());
		last->executeRedo();
		redoAdmin.pop();
		undoAdmin.push(last);
	}
	catch (RepositoryException& e) {
		cout << e.what() << "\n";
	}
}

void Controller::UndoUser() {
	if (this->undoUser.empty())
		throw RepositoryException("Nothing to undo right now! \n");
	try {
		std::shared_ptr <UndoAction> last =  (undoUser.top());
		last->executeUndo();
		undoUser.pop();
		this->redoUser.push(last);
	}
	catch (RepositoryException& e) {
		cout << e.what() << "\n";
	}

}

void  Controller::RedoUser() {
	if (this->redoUser.empty())
		throw RepositoryException("Nothing to redo right now! \n");
	try {
		std::shared_ptr <UndoAction> last =  (redoUser.top());
		last->executeRedo();
		redoUser.pop();
		undoUser.push(last);
	}
	catch (RepositoryException& e) {
		cout << e.what() << "\n";
	}
}