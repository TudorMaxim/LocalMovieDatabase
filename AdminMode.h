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
#include "ui_AdminMode.h"
#include "qshortcut.h"

class AdminMode : public QWidget {
	Q_OBJECT

public:
	AdminMode(Controller& c, QWidget *parent = Q_NULLPTR);
	~AdminMode();
	void list();
	void listShort();
	
public slots:
	void addHandler();
	void removeHandler();
	void updateHandler();
	void filterByDurationHandler();
	void undoHandler();
	void redoHandler();

private:
	void init();
	Ui::AdminMode ui;
	Controller ctrl;

	QPushButton* addButton;
	QPushButton* removeButton;
	QPushButton* updateButton;
	QPushButton* filterButton;
	QComboBox* comboBox;

	QLineEdit* editTitle;
	QLineEdit* editGenre;
	QLineEdit* editYear;
	QLineEdit* editLikes;
	QLineEdit* editDuration;
	QLineEdit* editLink;

	QListWidget* movies;
};
