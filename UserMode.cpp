#include "UserMode.h"
#include <cassert>

UserMode::UserMode(Controller& c, QWidget *parent) : ctrl(c), QWidget(parent) {
	ui.setupUi(this);
	list();
	QObject::connect(ui.filterButton, &QPushButton::clicked, this, &UserMode::filterHandler);
	QObject::connect(ui.removeButton, &QPushButton::clicked, this, &UserMode::removeHandler);
	QObject::connect(ui.addButton, &QPushButton::clicked, this, &UserMode::addHandler);
	QObject::connect(ui.nextButton, &QPushButton::clicked, this, &UserMode::nextHandler);

	QShortcut* undo = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this);
	QObject::connect(undo, &QShortcut::activated, this, &UserMode::undoHandler);

	QShortcut* redo = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y), this);
	QObject::connect(redo, &QShortcut::activated, this, &UserMode::redoHandler);
}

UserMode::~UserMode() {}


void UserMode::list() {
	std::vector <Movie> V = ctrl.GetWatchList();
	if (V.empty()) {
		QMessageBox mb;
		mb.setText(QString("There are no movies in the watch list!"));
		mb.exec();
		return;
	}
	ui.watchList->clear();
	for (Movie m : V) {
		std::string s = "";
		s += m.GetTitle() + " - " + m.GetGenre() + " (" + std::to_string(m.GetYear()) + ") / " + 
			std::to_string(m.GetLikes()) + " likes " + std::to_string(m.GetDuration()) + " minutes";
		ui.watchList->addItem(QString::fromStdString(s));
	}
}

void UserMode::removeHandler() {
	std::vector <Movie> V = ctrl.GetWatchList();
	QString Qtitle = ui.titleLineEdit->text();
	std::string title = Qtitle.toStdString();
	try {
		ctrl.DeleteFromWatchList(title);
		QWidget* wg = new QWidget();
		QString s = QInputDialog::getText(wg, "Watch List", "Did you like the movie? (yes/no)");
		if (s.toStdString() == "yes") {
			ctrl.GiveLike(title);
		}
		list();
	}
	catch (RepositoryException& ex) {
		QMessageBox mb;
		mb.setText(ex.what());
		mb.exec();	}
	ui.titleLineEdit->clear();
}

void UserMode::filterHandler() {
	QString genre = ui.genreLineEdit->text();
	options = ctrl.FilterByGenre(genre.toStdString());
	if (options.empty()) {
		QMessageBox mb;
		mb.setText("Error: There are no movies having any of the given genre!");
		mb.exec();
		ui.genreLineEdit->clear();
		ui.genreList->clear();
		ui.currentMovie->clear();
		return;
	}
	pos = 0;
	listGenre(genre);
	listCurrent();
	ui.genreLineEdit->clear();
}


void UserMode::listGenre(QString genre) {
	ui.genreList->clear();
	std::string g = genre.toStdString();
	std::istringstream is(g);
	std::string token;
	while (is >> token) {
		ui.genreList->addItem(QString::fromStdString(token));
	}
}

void UserMode::listCurrent() {
	ui.currentMovie->clear();
	std::string s = options[pos].GetTitle() + " - " + options[pos].GetGenre() + " (" + std::to_string(options[pos].GetYear()) + ") / " +
		std::to_string(options[pos].GetLikes()) + " likes " + std::to_string(options[pos].GetDuration()) + " minutes";
	ui.currentMovie->addItem(QString::fromStdString(s));
	options[pos].Play();
}


void UserMode::addHandler() {
	try {
		ctrl.AddToWatchList(options[pos]);
		listCurrent();
		
	}
	catch (RepositoryException& ex) {
		QMessageBox mb;
		mb.setText(ex.what());
		mb.exec();
	}
	list();
	nextHandler();
}

void UserMode::nextHandler() {
	pos++;
	if (pos == options.size())
		pos = 0;
	listCurrent();
}

void UserMode::undoHandler() {
	try {
		this->ctrl.UndoUser();
		this->list();
	}
	catch (RepositoryException& ex) {
		QMessageBox msgBox;
		msgBox.setText(ex.what());
		msgBox.exec();
	}
}

void UserMode::redoHandler() {
	try {
		this->ctrl.RedoUser();
		this->list();
	}
	catch (RepositoryException& ex) {
		QMessageBox msgBox;
		msgBox.setText(ex.what());
		msgBox.exec();
	}
}