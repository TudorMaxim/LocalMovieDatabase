#pragma once

#include <QWidget>
#include <qpushbutton.h>
#include "ui_MyMainWindow.h"

class MyMainWindow : public QWidget
{
	Q_OBJECT

public:
	MyMainWindow(QWidget *parent = Q_NULLPTR);
	~MyMainWindow();

private:
	Ui::MyMainWindow ui;
};
