#pragma once
#include "repository.h"
#include "FileWatchList.h"


class UndoAction {
public:
	virtual void executeUndo() = 0;
	virtual void executeRedo() = 0;
	virtual ~UndoAction() {};
};


class UndoAdd : public UndoAction {
private:
	Movie addedMovie;
	Repository& repo;	
public:
	UndoAdd(Repository& _repo, const Movie& m) : repo(_repo), addedMovie(m) {}
	void executeUndo() override {
		this->repo.Delete(this->addedMovie);
	}
	void executeRedo() override {
		this->repo.Add(this->addedMovie);
	}
};

class UndoRemove : public UndoAction {
private:
	Movie removedMovie;
	Repository& repo;
public:
	UndoRemove(Repository& _repo, const Movie& m) : repo(_repo), removedMovie(m) {}
	void executeUndo() override {
		this->repo.Add(this->removedMovie);
	}
	void executeRedo() override {
		this->repo.Delete(this->removedMovie);
	}
};

class UndoUpdate : public UndoAction {
private:
	Movie oldMovie;
	Movie newMovie;
	Repository& repo;

public:
	UndoUpdate(Repository& _repo, const Movie& newM, const Movie& oldM) : repo(_repo), newMovie(newM), oldMovie(oldM) {}
	void executeUndo() override {
		this->repo.Update(this->repo.Find(this->newMovie), this->oldMovie);
	}
	void executeRedo() override {
		this->repo.Update(this->repo.Find(oldMovie), this->newMovie);
	}
};

class UndoAddToWatchList : public UndoAction {
private:
	Movie addedMovie;
	FileWatchList* repo;
public:
	UndoAddToWatchList(FileWatchList*_repo, const Movie& m) : repo(_repo), addedMovie(m) {}
	void executeUndo() override {
		this->repo->Delete(this->addedMovie);
	}
	void executeRedo() override {
		this->repo->Add(this->addedMovie);
	}
};

class UndoRemoveFromWatchList : public UndoAction {
private:
	Movie removedMovie;
	FileWatchList* repo;
public:
	UndoRemoveFromWatchList(FileWatchList* _repo, const Movie& m) : repo(_repo), removedMovie(m) {}
	void executeUndo() override {
		this->repo->Add(this->removedMovie);
	}
	void executeRedo() override {
		this->repo->Delete(this->removedMovie);
	}
};