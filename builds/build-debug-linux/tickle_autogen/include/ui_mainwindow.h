/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QPushButton *revert_btn;
    QPushButton *switchMode;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_Player;
    QRadioButton *radioButton_Player_2;
    QMenuBar *menubar;
    QMenu *menuMode;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 700);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 700));
        MainWindow->setMaximumSize(QSize(800, 700));
        actionComputer = new QAction(MainWindow);
        actionComputer->setObjectName(QStringLiteral("actionComputer"));
        actionTwo_Player = new QAction(MainWindow);
        actionTwo_Player->setObjectName(QStringLiteral("actionTwo_Player"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 150, 551, 456));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(32);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btn_0_2 = new TicButton(layoutWidget);
        btn_0_2->setObjectName(QStringLiteral("btn_0_2"));
        btn_0_2->setStyleSheet(QStringLiteral("font-size:100px;"));

        gridLayout->addWidget(btn_0_2, 0, 2, 1, 1);

        btn_0_0 = new TicButton(layoutWidget);
        btn_0_0->setObjectName(QStringLiteral("btn_0_0"));
        btn_0_0->setStyleSheet(QStringLiteral("font-size:100px;"));

        gridLayout->addWidget(btn_0_0, 0, 0, 1, 1);

        btn_0_1 = new TicButton(layoutWidget);
        btn_0_1->setObjectName(QStringLiteral("btn_0_1"));
        btn_0_1->setStyleSheet(QStringLiteral("font-size:100px;"));

        gridLayout->addWidget(btn_0_1, 0, 1, 1, 1);

        btn_2_2 = new TicButton(layoutWidget);
        btn_2_2->setObjectName(QStringLiteral("btn_2_2"));
        btn_2_2->setStyleSheet(QStringLiteral("font-size:100px;"));

        gridLayout->addWidget(btn_2_2, 2, 2, 1, 1);

        btn_1_2 = new TicButton(layoutWidget);
        btn_1_2->setObjectName(QStringLiteral("btn_1_2"));
        btn_1_2->setStyleSheet(QStringLiteral("font-size:100px;"));

        gridLayout->addWidget(btn_1_2, 1, 2, 1, 1);

        btn_1_0 = new TicButton(layoutWidget);
        btn_1_0->setObjectName(QStringLiteral("btn_1_0"));
        btn_1_0->setStyleSheet(QStringLiteral("font-size:100px;"));

        gridLayout->addWidget(btn_1_0, 1, 0, 1, 1);

        btn_2_1 = new TicButton(layoutWidget);
        btn_2_1->setObjectName(QStringLiteral("btn_2_1"));
        btn_2_1->setStyleSheet(QStringLiteral("font-size:100px;"));

        gridLayout->addWidget(btn_2_1, 2, 1, 1, 1);

        btn_1_1 = new TicButton(layoutWidget);
        btn_1_1->setObjectName(QStringLiteral("btn_1_1"));
        btn_1_1->setStyleSheet(QStringLiteral("font-size:100px;"));

        gridLayout->addWidget(btn_1_1, 1, 1, 1, 1);

        btn_2_0 = new TicButton(layoutWidget);
        btn_2_0->setObjectName(QStringLiteral("btn_2_0"));
        btn_2_0->setStyleSheet(QStringLiteral("font-size:100px;"));

        gridLayout->addWidget(btn_2_0, 2, 0, 1, 1);

        RestartGame = new QPushButton(centralwidget);
        RestartGame->setObjectName(QStringLiteral("RestartGame"));
        RestartGame->setGeometry(QRect(160, 50, 93, 28));
        revert_btn = new QPushButton(centralwidget);
        revert_btn->setObjectName(QStringLiteral("revert_btn"));
        revert_btn->setGeometry(QRect(560, 50, 93, 28));
        switchMode = new QPushButton(centralwidget);
        switchMode->setObjectName(QStringLiteral("switchMode"));
        switchMode->setGeometry(QRect(360, 50, 93, 28));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(290, 110, 231, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_Player = new QRadioButton(widget);
        radioButton_Player->setObjectName(QStringLiteral("radioButton_Player"));

        horizontalLayout->addWidget(radioButton_Player);

        radioButton_Player_2 = new QRadioButton(widget);
        radioButton_Player_2->setObjectName(QStringLiteral("radioButton_Player_2"));

        horizontalLayout->addWidget(radioButton_Player_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuMode = new QMenu(menubar);
        menuMode->setObjectName(QStringLiteral("menuMode"));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionComputer->setText(QApplication::translate("MainWindow", "Computer", Q_NULLPTR));
        actionTwo_Player->setText(QApplication::translate("MainWindow", "Two Player", Q_NULLPTR));
        btn_0_2->setText(QApplication::translate("MainWindow", "_", Q_NULLPTR));
        btn_0_0->setText(QApplication::translate("MainWindow", "_", Q_NULLPTR));
        btn_0_1->setText(QApplication::translate("MainWindow", "_", Q_NULLPTR));
        btn_2_2->setText(QApplication::translate("MainWindow", "_", Q_NULLPTR));
        btn_1_2->setText(QApplication::translate("MainWindow", "_", Q_NULLPTR));
        btn_1_0->setText(QApplication::translate("MainWindow", "_", Q_NULLPTR));
        btn_2_1->setText(QApplication::translate("MainWindow", "_", Q_NULLPTR));
        btn_1_1->setText(QApplication::translate("MainWindow", "_", Q_NULLPTR));
        btn_2_0->setText(QApplication::translate("MainWindow", "_", Q_NULLPTR));
        RestartGame->setText(QApplication::translate("MainWindow", "Restart Game", Q_NULLPTR));
        revert_btn->setText(QApplication::translate("MainWindow", "Revert", Q_NULLPTR));
        switchMode->setText(QApplication::translate("MainWindow", "Switch Mode", Q_NULLPTR));
        radioButton_Player->setText(QApplication::translate("MainWindow", "Player One", Q_NULLPTR));
        radioButton_Player_2->setText(QApplication::translate("MainWindow", "Player Two", Q_NULLPTR));
        menuMode->setTitle(QApplication::translate("MainWindow", "Mode", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
