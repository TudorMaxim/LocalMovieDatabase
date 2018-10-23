/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *buttonsLayout;
    QPushButton *adminButton;
    QPushButton *userButton;
    QPushButton *tableButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(600, 400);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 80, 481, 81));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 200, 591, 131));
        buttonsLayout = new QHBoxLayout(layoutWidget);
        buttonsLayout->setSpacing(6);
        buttonsLayout->setContentsMargins(11, 11, 11, 11);
        buttonsLayout->setObjectName(QStringLiteral("buttonsLayout"));
        buttonsLayout->setContentsMargins(0, 0, 0, 0);
        adminButton = new QPushButton(layoutWidget);
        adminButton->setObjectName(QStringLiteral("adminButton"));
        adminButton->setFont(font);

        buttonsLayout->addWidget(adminButton);

        userButton = new QPushButton(layoutWidget);
        userButton->setObjectName(QStringLiteral("userButton"));
        userButton->setFont(font);

        buttonsLayout->addWidget(userButton);

        tableButton = new QPushButton(layoutWidget);
        tableButton->setObjectName(QStringLiteral("tableButton"));
        tableButton->setFont(font);

        buttonsLayout->addWidget(tableButton);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindowClass", "In what way would you like to use the application?", nullptr));
        adminButton->setText(QApplication::translate("MainWindowClass", "Admin Mode", nullptr));
        userButton->setText(QApplication::translate("MainWindowClass", "User Mode", nullptr));
        tableButton->setText(QApplication::translate("MainWindowClass", "Table", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
