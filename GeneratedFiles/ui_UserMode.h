/********************************************************************************
** Form generated from reading UI file 'UserMode.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMODE_H
#define UI_USERMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserMode
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *header;
    QListWidget *watchList;
    QHBoxLayout *buttonsLayout;
    QLabel *titleLabel;
    QLineEdit *titleLineEdit;
    QLabel *genreLabel;
    QLineEdit *genreLineEdit;
    QHBoxLayout *inputLayout;
    QPushButton *removeButton;
    QPushButton *filterButton;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *desiredGenre;
    QListWidget *genreList;
    QLabel *currentLabel;
    QListWidget *currentMovie;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addButton;
    QPushButton *nextButton;

    void setupUi(QWidget *UserMode)
    {
        if (UserMode->objectName().isEmpty())
            UserMode->setObjectName(QStringLiteral("UserMode"));
        UserMode->resize(1092, 645);
        layoutWidget = new QWidget(UserMode);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(1, 1, 991, 341));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        header = new QLabel(layoutWidget);
        header->setObjectName(QStringLiteral("header"));
        QFont font;
        font.setPointSize(12);
        header->setFont(font);

        verticalLayout->addWidget(header);

        watchList = new QListWidget(layoutWidget);
        watchList->setObjectName(QStringLiteral("watchList"));

        verticalLayout->addWidget(watchList);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setSpacing(6);
        buttonsLayout->setObjectName(QStringLiteral("buttonsLayout"));
        titleLabel = new QLabel(layoutWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));

        buttonsLayout->addWidget(titleLabel);

        titleLineEdit = new QLineEdit(layoutWidget);
        titleLineEdit->setObjectName(QStringLiteral("titleLineEdit"));

        buttonsLayout->addWidget(titleLineEdit);

        genreLabel = new QLabel(layoutWidget);
        genreLabel->setObjectName(QStringLiteral("genreLabel"));

        buttonsLayout->addWidget(genreLabel);

        genreLineEdit = new QLineEdit(layoutWidget);
        genreLineEdit->setObjectName(QStringLiteral("genreLineEdit"));

        buttonsLayout->addWidget(genreLineEdit);


        verticalLayout->addLayout(buttonsLayout);

        inputLayout = new QHBoxLayout();
        inputLayout->setSpacing(6);
        inputLayout->setObjectName(QStringLiteral("inputLayout"));
        removeButton = new QPushButton(layoutWidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));

        inputLayout->addWidget(removeButton);

        filterButton = new QPushButton(layoutWidget);
        filterButton->setObjectName(QStringLiteral("filterButton"));

        inputLayout->addWidget(filterButton);


        verticalLayout->addLayout(inputLayout);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        desiredGenre = new QLabel(layoutWidget);
        desiredGenre->setObjectName(QStringLiteral("desiredGenre"));
        desiredGenre->setFont(font);

        verticalLayout_2->addWidget(desiredGenre);

        genreList = new QListWidget(layoutWidget);
        genreList->setObjectName(QStringLiteral("genreList"));

        verticalLayout_2->addWidget(genreList);


        verticalLayout_3->addLayout(verticalLayout_2);

        currentLabel = new QLabel(layoutWidget);
        currentLabel->setObjectName(QStringLiteral("currentLabel"));
        currentLabel->setFont(font);

        verticalLayout_3->addWidget(currentLabel);

        currentMovie = new QListWidget(layoutWidget);
        currentMovie->setObjectName(QStringLiteral("currentMovie"));

        verticalLayout_3->addWidget(currentMovie);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout_2->addWidget(addButton);

        nextButton = new QPushButton(layoutWidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));

        horizontalLayout_2->addWidget(nextButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_3);


        retranslateUi(UserMode);

        QMetaObject::connectSlotsByName(UserMode);
    } // setupUi

    void retranslateUi(QWidget *UserMode)
    {
        UserMode->setWindowTitle(QApplication::translate("UserMode", "UserMode", nullptr));
        header->setText(QApplication::translate("UserMode", "Watch List:", nullptr));
        titleLabel->setText(QApplication::translate("UserMode", "Title:", nullptr));
        genreLabel->setText(QApplication::translate("UserMode", "Genre:", nullptr));
        removeButton->setText(QApplication::translate("UserMode", "Remove", nullptr));
        filterButton->setText(QApplication::translate("UserMode", "Filter by genre", nullptr));
        desiredGenre->setText(QApplication::translate("UserMode", "Desired genre:", nullptr));
        currentLabel->setText(QApplication::translate("UserMode", "Current movie:", nullptr));
        addButton->setText(QApplication::translate("UserMode", "Add", nullptr));
        nextButton->setText(QApplication::translate("UserMode", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserMode: public Ui_UserMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMODE_H
