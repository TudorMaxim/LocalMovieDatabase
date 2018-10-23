#pragma once

#include <QWidget>
#include <qsortfilterproxymodel.h>
#include "TableView.h"
#include "ui_SetupTable.h"

class SetupTable : public QWidget {
	Q_OBJECT

public:
	SetupTable(Controller& c, QWidget *parent = Q_NULLPTR);
	~SetupTable();
	void setUpTableView();

private:
	Ui::SetupTable ui;
	Controller ctrl;
	TableView* table;
};
