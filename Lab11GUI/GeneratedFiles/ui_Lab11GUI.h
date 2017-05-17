/********************************************************************************
** Form generated from reading UI file 'Lab11GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB11GUI_H
#define UI_LAB11GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab11GUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lab11GUIClass)
    {
        if (Lab11GUIClass->objectName().isEmpty())
            Lab11GUIClass->setObjectName(QStringLiteral("Lab11GUIClass"));
        Lab11GUIClass->resize(600, 400);
        menuBar = new QMenuBar(Lab11GUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Lab11GUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lab11GUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lab11GUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lab11GUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Lab11GUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lab11GUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lab11GUIClass->setStatusBar(statusBar);

        retranslateUi(Lab11GUIClass);

        QMetaObject::connectSlotsByName(Lab11GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lab11GUIClass)
    {
        Lab11GUIClass->setWindowTitle(QApplication::translate("Lab11GUIClass", "Lab11GUI", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Lab11GUIClass: public Ui_Lab11GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB11GUI_H
