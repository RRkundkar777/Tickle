/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <ticbutton.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionComputer;
    QAction *actionTwo_Player;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    TicButton *btn_0_2;
    TicButton *btn_0_0;
    TicButton *btn_0_1;
    TicButton *btn_2_2;
    TicButton *btn_1_2;
    TicButton *btn_1_0;
    TicButton *btn_2_1;
    TicButton *btn_1_1;
    TicButton *btn_2_0;
    QPushButton *RestartGame;
    QMenuBar *menubar;
    QMenu *menuMode;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 700);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 700));
        MainWindow->setMaximumSize(QSize(800, 700));
        actionComputer = new QAction(MainWindow);
        actionComputer->setObjectName(QString::fromUtf8("actionComputer"));
        actionTwo_Player = new QAction(MainWindow);
        actionTwo_Player->setObjectName(QString::fromUtf8("actionTwo_Player"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 90, 551, 456));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(32);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btn_0_2 = new TicButton(layoutWidget);
        btn_0_2->setObjectName(QString::fromUtf8("btn_0_2"));
        btn_0_2->setStyleSheet(QString::fromUtf8("font-size:100px;"));

        gridLayout->addWidget(btn_0_2, 0, 2, 1, 1);

        btn_0_0 = new TicButton(layoutWidget);
        btn_0_0->setObjectName(QString::fromUtf8("btn_0_0"));
        btn_0_0->setStyleSheet(QString::fromUtf8("font-size:100px;"));

        gridLayout->addWidget(btn_0_0, 0, 0, 1, 1);

        btn_0_1 = new TicButton(layoutWidget);
        btn_0_1->setObjectName(QString::fromUtf8("btn_0_1"));
        btn_0_1->setStyleSheet(QString::fromUtf8("font-size:100px;"));

        gridLayout->addWidget(btn_0_1, 0, 1, 1, 1);

        btn_2_2 = new TicButton(layoutWidget);
        btn_2_2->setObjectName(QString::fromUtf8("btn_2_2"));
        btn_2_2->setStyleSheet(QString::fromUtf8("font-size:100px;"));

        gridLayout->addWidget(btn_2_2, 2, 2, 1, 1);

        btn_1_2 = new TicButton(layoutWidget);
        btn_1_2->setObjectName(QString::fromUtf8("btn_1_2"));
        btn_1_2->setStyleSheet(QString::fromUtf8("font-size:100px;"));

        gridLayout->addWidget(btn_1_2, 1, 2, 1, 1);

        btn_1_0 = new TicButton(layoutWidget);
        btn_1_0->setObjectName(QString::fromUtf8("btn_1_0"));
        btn_1_0->setStyleSheet(QString::fromUtf8("font-size:100px;"));

        gridLayout->addWidget(btn_1_0, 1, 0, 1, 1);

        btn_2_1 = new TicButton(layoutWidget);
        btn_2_1->setObjectName(QString::fromUtf8("btn_2_1"));
        btn_2_1->setStyleSheet(QString::fromUtf8("font-size:100px;"));

        gridLayout->addWidget(btn_2_1, 2, 1, 1, 1);

        btn_1_1 = new TicButton(layoutWidget);
        btn_1_1->setObjectName(QString::fromUtf8("btn_1_1"));
        btn_1_1->setStyleSheet(QString::fromUtf8("font-size:100px;"));

        gridLayout->addWidget(btn_1_1, 1, 1, 1, 1);

        btn_2_0 = new TicButton(layoutWidget);
        btn_2_0->setObjectName(QString::fromUtf8("btn_2_0"));
        btn_2_0->setStyleSheet(QString::fromUtf8("font-size:100px;"));

        gridLayout->addWidget(btn_2_0, 2, 0, 1, 1);

        RestartGame = new QPushButton(centralwidget);
        RestartGame->setObjectName(QString::fromUtf8("RestartGame"));
        RestartGame->setGeometry(QRect(360, 50, 93, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuMode = new QMenu(menubar);
        menuMode->setObjectName(QString::fromUtf8("menuMode"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuMode->menuAction());
        menuMode->addSeparator();
        menuMode->addAction(actionComputer);
        menuMode->addAction(actionTwo_Player);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionComputer->setText(QApplication::translate("MainWindow", "Computer", nullptr));
        actionTwo_Player->setText(QApplication::translate("MainWindow", "Two Player", nullptr));
        btn_0_2->setText(QApplication::translate("MainWindow", "_", nullptr));
        btn_0_0->setText(QApplication::translate("MainWindow", "_", nullptr));
        btn_0_1->setText(QApplication::translate("MainWindow", "_", nullptr));
        btn_2_2->setText(QApplication::translate("MainWindow", "_", nullptr));
        btn_1_2->setText(QApplication::translate("MainWindow", "_", nullptr));
        btn_1_0->setText(QApplication::translate("MainWindow", "_", nullptr));
        btn_2_1->setText(QApplication::translate("MainWindow", "_", nullptr));
        btn_1_1->setText(QApplication::translate("MainWindow", "_", nullptr));
        btn_2_0->setText(QApplication::translate("MainWindow", "_", nullptr));
        RestartGame->setText(QApplication::translate("MainWindow", "Restart Game", nullptr));
        menuMode->setTitle(QApplication::translate("MainWindow", "Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
