#include "tester.h"

using namespace std;

void Tester::TestDomain() {
	Movie film("Batman", "Action", 2007, 500000, 120, "justalink");
	Movie spiderman("Spiderman", "Action", 2004, 600000, 120, "justalink");
	Movie batman(film);

	film = film;
	//batman.Play();
	assert(film.GetTitle() == "Batman");
	assert(film.GetGenre() == "Action");
	assert(film.GetYear() == 2007);
	assert(film.GetLikes() == 500000);
	assert(film.GetLink() == "justalink");

	assert(batman.GetTitle() == "Batman");
	assert(batman.GetGenre() == "Action");
	assert(batman.GetYear() == 2007);
	assert(batman.GetLikes() == 500000);
	assert(batman.GetLink() == "justalink");

	Movie film2 = film;
	assert(film2.GetTitle() == "Batman");
	assert(film2.GetGenre() == "Action");
	assert(film2.GetYear() == 2007);
	assert(film2.GetLikes() == 500000);
	assert(film2.GetLink() == "justalink");
	assert(film == film2);
	assert(film != spiderman);

	film.IncrementLikes();
	assert(film.GetLikes() == 500001);
}

void Tester::TestRepository() {
	Repository repo;
	Movie batman("Batman", "Action", 2007, 500000, 120, "justalink");
	Movie spiderman("Spiderman", "Action", 2004, 600000, 120, "justalink");
	Movie superman("Superman", "Action", 2007, 500000, 120, "justalink");
	Movie wonderwoman("Wonderwoman", "Action", 2004, 600000, 120, "justalink");

	repo.Add(batman);
	assert(repo.Size() == 1);
	repo.Delete(batman);
	assert(repo.Size() == 0);
	repo.Add(batman);
	repo.Add(spiderman);
	repo.Add(wonderwoman);

	assert(repo.Find(superman) == repo.End());
	assert(repo.Find(batman) != repo.End());
	assert(repo.Find(batman) == repo.Begin());

	assert(repo.Size() == 3);

	vector <Movie>::iterator it = repo.Find(wonderwoman);
	repo.Update(it, superman);

	vector <Movie> V = repo.GetAll();

	assert(V.size() == 3);
	assert(V[0] == batman);
	assert(V[1] == spiderman);
	assert(V[2] == superman);
	assert(repo.GetElement(it) == superman);
}

void Tester::TestController() {
	Controller ctrl;
	Movie batman("Batman", "Action", 2007, 500000, 90, "www.justalink");
	Movie spiderman("Spiderman", "Action", 2004, 600000, 120, "www.justalink");
	Movie superman("Superman", "Action", 2007, 500000, 120, "www.justalink");
	Movie wonderwoman("Wonderwoman", "Action", 2004, 600000, 120, "www.justalink");
	try {
		ctrl.Delete(batman.GetTitle());
	}
	catch (RepositoryException ex) {
		assert(1);
	}
	try {
		ctrl.Add(batman);
		ctrl.Add(batman);
	}
	catch (RepositoryException ex) {
		vector <Movie> V = ctrl.GetAll();
		assert(V.size() == 1);
	}
	ctrl.Add(spiderman);
	ctrl.Add(superman);
	try {
		ctrl.Delete(spiderman.GetTitle());
		ctrl.Delete(spiderman.GetTitle());
	}
	catch (RepositoryException ex) {
		vector <Movie> V = ctrl.GetAll();
		assert(V.size() == 2);
	}
	vector <Movie> W = ctrl.GetAll();
	assert(W.size() == 2);
	assert(W[0] == batman);
	assert(W[1] == superman);
	try {
		ctrl.Update(superman.GetTitle(), wonderwoman);
		ctrl.Update(spiderman.GetTitle(), wonderwoman);
	}
	catch (RepositoryException ex) {
		assert(1);
	}
	vector <Movie> X = ctrl.GetAll();
	assert(X[1] == wonderwoman);

	string e = "", a = "Action", b = "Batman", s = "Spiderman";
	try {
		ctrl.GiveLike(b);
		ctrl.GiveLike(s);
	}
	catch (RepositoryException ex) {
		assert(1);
	}

	vector <Movie> I = ctrl.FilterByGenre(e);
	assert(I.size() == 2);
	assert(I[0].GetLikes() == 500001);

	I = ctrl.FilterByGenre(a);
	assert(I.size() == 2);

	I = ctrl.FilterByDuration(100);
	assert(I.size() == 1);
	assert(I[0].GetDuration() == 90);
}