#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab11GUI.h"

class Lab11GUI : public QMainWindow
{
	Q_OBJECT

public:
	Lab11GUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::Lab11GUIClass ui;
};
