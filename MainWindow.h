#pragma once
#include "AdminMode.h"
#include "UserMode.h"
#include "ui_MainWindow.h"
#include "SetupTable.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(Controller& c, QWidget *parent = Q_NULLPTR);

public slots:
	void adminMode();
	void userMode();
	void tableHandler();

private:
	Ui::MainWindowClass ui;
	Controller ctrl;
};
