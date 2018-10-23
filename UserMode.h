#pragma once
#include <QWidget>
#include <QtWidgets/QMainWindow>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qinputdialog.h>
#include <qlistwidget.h>
#include <qstring.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <QHBoxLayout>
#include <qcombobox.h>
#include "controller.h"
#include <qshortcut.h>
#include "ui_UserMode.h"

class UserMode : public QWidget {
	Q_OBJECT

public:
	UserMode(Controller& c, QWidget *parent = Q_NULLPTR);
	~UserMode();
	void listGenre(QString genre);
	void listCurrent();
	void list();

public slots:
	void removeHandler();
	void filterHandler();
	void addHandler();
	void nextHandler();
	void undoHandler();
	void redoHandler();

private:
	Ui::UserMode ui;
	Controller ctrl;
	std::vector <Movie> options;
	int pos;
};
