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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab11GUIClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *colour;
    QLineEdit *size;
    QLineEdit *price;
    QLineEdit *quantity;
    QLineEdit *photo;
    QListWidget *coat_list;
    QListWidget *basket;
    QPushButton *move_one;
    QPushButton *move_all;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *add;
    QPushButton *delete_2;
    QPushButton *update;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *view;
    QPushButton *next;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lab11GUIClass)
    {
        if (Lab11GUIClass->objectName().isEmpty())
            Lab11GUIClass->setObjectName(QStringLiteral("Lab11GUIClass"));
        Lab11GUIClass->resize(901, 523);
        centralWidget = new QWidget(Lab11GUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 55, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(600, 20, 55, 16));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 250, 72, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(90, 251, 281, 140));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        colour = new QLineEdit(layoutWidget1);
        colour->setObjectName(QStringLiteral("colour"));

        verticalLayout_2->addWidget(colour);

        size = new QLineEdit(layoutWidget1);
        size->setObjectName(QStringLiteral("size"));

        verticalLayout_2->addWidget(size);

        price = new QLineEdit(layoutWidget1);
        price->setObjectName(QStringLiteral("price"));

        verticalLayout_2->addWidget(price);

        quantity = new QLineEdit(layoutWidget1);
        quantity->setObjectName(QStringLiteral("quantity"));

        verticalLayout_2->addWidget(quantity);

        photo = new QLineEdit(layoutWidget1);
        photo->setObjectName(QStringLiteral("photo"));

        verticalLayout_2->addWidget(photo);

        coat_list = new QListWidget(centralWidget);
        coat_list->setObjectName(QStringLiteral("coat_list"));
        coat_list->setGeometry(QRect(10, 50, 361, 192));
        basket = new QListWidget(centralWidget);
        basket->setObjectName(QStringLiteral("basket"));
        basket->setGeometry(QRect(600, 40, 281, 381));
        move_one = new QPushButton(centralWidget);
        move_one->setObjectName(QStringLiteral("move_one"));
        move_one->setGeometry(QRect(430, 100, 93, 28));
        move_all = new QPushButton(centralWidget);
        move_all->setObjectName(QStringLiteral("move_all"));
        move_all->setGeometry(QRect(430, 220, 93, 28));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 430, 295, 30));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        add = new QPushButton(widget);
        add->setObjectName(QStringLiteral("add"));

        horizontalLayout->addWidget(add);

        delete_2 = new QPushButton(widget);
        delete_2->setObjectName(QStringLiteral("delete_2"));

        horizontalLayout->addWidget(delete_2);

        update = new QPushButton(widget);
        update->setObjectName(QStringLiteral("update"));

        horizontalLayout->addWidget(update);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(650, 430, 195, 30));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        view = new QPushButton(widget1);
        view->setObjectName(QStringLiteral("view"));

        horizontalLayout_2->addWidget(view);

        next = new QPushButton(widget1);
        next->setObjectName(QStringLiteral("next"));

        horizontalLayout_2->addWidget(next);

        Lab11GUIClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(Lab11GUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lab11GUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Lab11GUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lab11GUIClass->setStatusBar(statusBar);

        retranslateUi(Lab11GUIClass);
        QObject::connect(add, SIGNAL(pressed()), coat_list, SLOT(reset()));

        QMetaObject::connectSlotsByName(Lab11GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lab11GUIClass)
    {
        Lab11GUIClass->setWindowTitle(QApplication::translate("Lab11GUIClass", "Lab11GUI", Q_NULLPTR));
        label->setText(QApplication::translate("Lab11GUIClass", "All coats", Q_NULLPTR));
        label_2->setText(QApplication::translate("Lab11GUIClass", "Basket", Q_NULLPTR));
        label_3->setText(QApplication::translate("Lab11GUIClass", "Colour:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Lab11GUIClass", "Size:", Q_NULLPTR));
        label_5->setText(QApplication::translate("Lab11GUIClass", "Price:", Q_NULLPTR));
        label_6->setText(QApplication::translate("Lab11GUIClass", "Quantity:", Q_NULLPTR));
        label_7->setText(QApplication::translate("Lab11GUIClass", "Photograph:", Q_NULLPTR));
        move_one->setText(QApplication::translate("Lab11GUIClass", ">", Q_NULLPTR));
        move_all->setText(QApplication::translate("Lab11GUIClass", ">>", Q_NULLPTR));
        add->setText(QApplication::translate("Lab11GUIClass", "Add", Q_NULLPTR));
        delete_2->setText(QApplication::translate("Lab11GUIClass", "Delete", Q_NULLPTR));
        update->setText(QApplication::translate("Lab11GUIClass", "Update", Q_NULLPTR));
        view->setText(QApplication::translate("Lab11GUIClass", "View", Q_NULLPTR));
        next->setText(QApplication::translate("Lab11GUIClass", "Next", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Lab11GUIClass: public Ui_Lab11GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB11GUI_H
