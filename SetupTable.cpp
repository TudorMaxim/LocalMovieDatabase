#include "SetupTable.h"

SetupTable::SetupTable(Controller& _ctrl, QWidget *parent) : ctrl(_ctrl), QWidget(parent) {
	ui.setupUi(this);
	this -> table = new TableView(this->ctrl);
	this->setUpTableView();
}

SetupTable::~SetupTable() { }


void SetupTable::setUpTableView() {
	QSortFilterProxyModel* proxyModel = new QSortFilterProxyModel();
	proxyModel->setSourceModel(this->table);
	ui.watchList->setSortingEnabled(true);
	ui.watchList->setModel(proxyModel);
	ui.watchList->resizeColumnsToContents();
}

