#include "MainWindow.h"

MainWindow::MainWindow(Controller& c, QWidget *parent) : ctrl(c), QMainWindow(parent) {
	ui.setupUi(this);
	QObject::connect(ui.adminButton, &QPushButton::clicked, this, &MainWindow::adminMode);
	QObject::connect(ui.userButton, &QPushButton::clicked, this, &MainWindow::userMode);
	QObject::connect(ui.tableButton, &QPushButton::clicked, this, &MainWindow::tableHandler);
}


void MainWindow::adminMode() {
	AdminMode* admin = new AdminMode(this->ctrl);
	admin->show();
}

void MainWindow::userMode() {
	UserMode* user = new UserMode(this->ctrl);
	user->show();
}

void MainWindow::tableHandler() {
	SetupTable* t = new SetupTable(this->ctrl);
	t->show();
}