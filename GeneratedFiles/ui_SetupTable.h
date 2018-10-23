/********************************************************************************
** Form generated from reading UI file 'SetupTable.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUPTABLE_H
#define UI_SETUPTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetupTable
{
public:
    QTableView *watchList;

    void setupUi(QWidget *SetupTable)
    {
        if (SetupTable->objectName().isEmpty())
            SetupTable->setObjectName(QStringLiteral("SetupTable"));
        SetupTable->resize(1044, 551);
        watchList = new QTableView(SetupTable);
        watchList->setObjectName(QStringLiteral("watchList"));
        watchList->setGeometry(QRect(0, 0, 1051, 551));

        retranslateUi(SetupTable);

        QMetaObject::connectSlotsByName(SetupTable);
    } // setupUi

    void retranslateUi(QWidget *SetupTable)
    {
        SetupTable->setWindowTitle(QApplication::translate("SetupTable", "SetupTable", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetupTable: public Ui_SetupTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPTABLE_H
