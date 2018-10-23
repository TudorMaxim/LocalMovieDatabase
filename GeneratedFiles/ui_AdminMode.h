/********************************************************************************
** Form generated from reading UI file 'AdminMode.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMODE_H
#define UI_ADMINMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminMode
{
public:

    void setupUi(QWidget *AdminMode)
    {
        if (AdminMode->objectName().isEmpty())
            AdminMode->setObjectName(QStringLiteral("AdminMode"));
        AdminMode->resize(400, 300);

        retranslateUi(AdminMode);

        QMetaObject::connectSlotsByName(AdminMode);
    } // setupUi

    void retranslateUi(QWidget *AdminMode)
    {
        AdminMode->setWindowTitle(QApplication::translate("AdminMode", "AdminMode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminMode: public Ui_AdminMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMODE_H
