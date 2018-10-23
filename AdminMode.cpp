#include "AdminMode.h"


AdminMode::AdminMode(Controller& c, QWidget *parent) :  ctrl(c), QWidget(parent) {
	ui.setupUi(this);
	this->init();
	this->list();
	comboBox->addItem("Detailed");
	comboBox->addItem("Short");

	QObject::connect(addButton, &QPushButton::clicked, this, &AdminMode::addHandler);
	QObject::connect(removeButton, &QPushButton::clicked, this, &AdminMode::removeHandler);
	QObject::connect(updateButton, &QPushButton::clicked, this, &AdminMode::updateHandler);
	QObject::connect(filterButton, &QPushButton::clicked, this, &AdminMode::filterByDurationHandler);

	QShortcut* undo = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this);
	QObject::connect(undo, &QShortcut::activated, this, &AdminMode::undoHandler);

	QShortcut* redo = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y), this);
	QObject::connect(redo, &QShortcut::activated, this, &AdminMode::redoHandler);

	QObject::connect(comboBox, QOverload<const QString &>::of(&QComboBox::currentTextChanged),
		[=] (const QString &text) { 
			if (text == "Detailed") 
				list(); 
			else 
				listShort(); 
			}
	);
}

AdminMode::~AdminMode() { }


void AdminMode::init() {
	QHBoxLayout* mainLayout = new QHBoxLayout{ this };
	QVBoxLayout* leftLayout = new QVBoxLayout{};
	QVBoxLayout* rightLayout = new QVBoxLayout{}; 
	QHBoxLayout* filterLayout = new QHBoxLayout{};

	this->movies = new QListWidget();

	QLabel* header = new QLabel("Movies:");

	this->comboBox = new QComboBox();
	leftLayout->addWidget(comboBox);

	leftLayout->addWidget(header);
	leftLayout->addWidget(movies);

	QHBoxLayout* bottomLayout = new QHBoxLayout{};
	QVBoxLayout* labelsLayout = new QVBoxLayout{};
	QVBoxLayout* editLayout = new QVBoxLayout{};

	QLabel* label_title = new QLabel("Title");
	this->editTitle = new QLineEdit();

	QLabel* label_genre = new QLabel("Genre");
	this->editGenre = new QLineEdit();

	QLabel* label_year = new QLabel("Year");
	this->editYear = new QLineEdit();

	QLabel* label_likes = new QLabel("Likes");
	this->editLikes = new QLineEdit();

	QLabel* label_link = new QLabel("Link");
	this->editLink = new QLineEdit();

	QLabel* label_duration = new QLabel("Duration");
	this->editDuration = new QLineEdit();

	labelsLayout->addWidget(label_title);
	labelsLayout->addWidget(label_genre);
	labelsLayout->addWidget(label_year);
	labelsLayout->addWidget(label_likes);
	labelsLayout->addWidget(label_duration);
	labelsLayout->addWidget(label_link);

	editLayout->addWidget(editTitle);
	editLayout->addWidget(editGenre);
	editLayout->addWidget(editYear);
	editLayout->addWidget(editLikes);
	editLayout->addWidget(editDuration);
	editLayout->addWidget(editLink);


	bottomLayout->addLayout(labelsLayout);
	bottomLayout->addLayout(editLayout);

	leftLayout->addLayout(bottomLayout);

	QHBoxLayout* buttonsLayout = new QHBoxLayout();

	this->addButton = new QPushButton("Add");
	this->removeButton = new QPushButton("Remove");
	this->updateButton = new QPushButton("Update");
	this->filterButton = new QPushButton("Filter by duration");


	buttonsLayout->addWidget(addButton);
	buttonsLayout->addWidget(removeButton);
	buttonsLayout->addWidget(updateButton);
	filterLayout->addWidget(filterButton);

	leftLayout->addLayout(buttonsLayout);
	leftLayout->addLayout(filterLayout);

	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);

}

void AdminMode::list() {
	this->movies->clear();
	std::vector<Movie> V = this->ctrl.GetAll();
	if (V.size() == 0) {
		std::string s = "There are no movies in the repository!";
		QMessageBox msgBox;
		QString qstr = QString::fromStdString(s);
		msgBox.setText(qstr);
		msgBox.exec();
		return;
	}
	for (auto m : V) {
		std::string s = "";
		s += m.GetTitle() + " - " + m.GetGenre() + " (" + std::to_string(m.GetYear()) + ") / " + std::to_string(m.GetLikes()) + " likes " + std::to_string(m.GetDuration()) + " minutes";
		this->movies->addItem(QString::fromStdString(s));
	}
}

void AdminMode::listShort() {
	this->movies->clear();
	std::vector<Movie> V = this->ctrl.GetAll();
	if (V.size() == 0) {
		std::string s = "There are no movies in the repository!";
		QMessageBox msgBox;
		QString qstr = QString::fromStdString(s);
		msgBox.setText(qstr);
		msgBox.exec();
		return;
	}
	for (auto m : V) {
		std::string s = "";
		s += m.GetTitle() + " " + std::to_string(m.GetYear());
		this->movies->addItem(QString::fromStdString(s));
	}
}

void AdminMode::addHandler() {
	QString title = this->editTitle->text();
	QString genre = this->editGenre->text();
	QString year = this->editYear->text();
	QString likes = this->editLikes->text();
	QString duration = this->editDuration->text();
	QString link = this->editLink->text();
	try {
		this->ctrl.Add(Movie(title.toStdString(), genre.toStdString(), year.toInt(), likes.toInt(), duration.toInt(), link.toStdString()));
		list();
	}
	catch (MovieException& e) {
		for (auto s : e.getErrors()) {
			QMessageBox msgBox;
			QString qstr = QString::fromStdString(s);
			msgBox.setText(qstr);
			msgBox.exec();
		}
	}
	catch (RepositoryException& e) {
		QMessageBox msgBox;
		msgBox.setText(e.what());
		msgBox.exec();
	}
	catch (FileException& e) {
		QMessageBox msgBox;
		msgBox.setText(e.what());
		msgBox.exec();
	}
	this->editTitle->clear();
	this->editGenre->clear();
	this->editYear->clear();
	this->editLikes->clear();
	this->editLink->clear();
	this->editDuration->clear();
}

void AdminMode::removeHandler() {
	QString title = this->editTitle->text();
	try {
		this->ctrl.Delete(title.toStdString());
		list();
	}
	catch (MovieException& e) {
		for (auto s : e.getErrors()) {
			QMessageBox msgBox;
			QString qstr = QString::fromStdString(s);
			msgBox.setText(qstr);
			msgBox.exec();
		}
	}
	catch (RepositoryException& e) {
		QMessageBox msgBox;
		msgBox.setText(e.what());
		msgBox.exec();
	}
	catch (FileException& e) {
		QMessageBox msgBox;
		msgBox.setText(e.what());
		msgBox.exec();
	}
	this->editTitle->clear();
}

void AdminMode::updateHandler() {
	QString title = this->editTitle->text();
	QString genre = this->editGenre->text();
	QString year = this->editYear->text();
	QString likes = this->editLikes->text();
	QString duration = this->editDuration->text();
	QString link = this->editLink->text();
	try {
		this->ctrl.Update(title.toStdString(), Movie(title.toStdString(), genre.toStdString(), year.toInt(),
													likes.toInt(), duration.toInt(), link.toStdString()));
		list();
	}
	catch (MovieException& e) {
		for (auto s : e.getErrors()) {
			QMessageBox msgBox;
			QString qstr = QString::fromStdString(s);
			msgBox.setText(qstr);
			msgBox.exec();
		}
	}
	catch (RepositoryException& e){
		QMessageBox msgBox;
		msgBox.setText(e.what());
		msgBox.exec();
	}
	catch (FileException& e){
		QMessageBox msgBox;
		msgBox.setText(e.what());
		msgBox.exec();
	}
	this->editTitle->clear();
	this->editGenre->clear();
	this->editYear->clear();
	this->editLikes->clear();
	this->editLink->clear();
	this->editDuration->clear();
}

void AdminMode::filterByDurationHandler() {
	QString duration = this->editDuration->text();
	try {
		std::vector <Movie> V = this->ctrl.FilterByDuration(duration.toInt());
		if (V.size() == 0) {
			std::string s = "There are no movies shorter than " + duration.toStdString() + " minutes";
			QMessageBox msgBox;
			QString qstr = QString::fromStdString(s);
			msgBox.setText(qstr);
			msgBox.exec();
			return;
		}
		this->movies->clear();
		for (auto m : V) {
			std::string s = "";
			s += m.GetTitle() + " - " + m.GetGenre() + " (" + std::to_string(m.GetYear()) + ") / " + std::to_string(m.GetLikes()) + " likes " + std::to_string(m.GetDuration()) + " minutes";
			this->movies->addItem(QString::fromStdString(s));
		}
	}
	catch (MovieException& e) {
		for (auto s : e.getErrors()) {
			QMessageBox msgBox;
			QString qstr = QString::fromStdString(s);
			msgBox.setText(qstr);
			msgBox.exec();
		}
	}
	catch (RepositoryException& e) {
		QMessageBox msgBox;
		msgBox.setText(e.what());
		msgBox.exec();
	}
	catch (FileException& e) {
		QMessageBox msgBox;
		msgBox.setText(e.what());
		msgBox.exec();
	}
	this->editDuration->clear();
}

void AdminMode::undoHandler() {
	try {
		this->ctrl.UndoAdmin();
		this->list();
	}
	catch (RepositoryException& ex) {
		QMessageBox msgBox;
		msgBox.setText(ex.what());
		msgBox.exec();
	}
}

void AdminMode::redoHandler() {
	try {
		this->ctrl.RedoAdmin();
		this->list();
	}
	catch (RepositoryException& ex) {
		QMessageBox msgBox;
		msgBox.setText(ex.what());
		msgBox.exec();
	}
}