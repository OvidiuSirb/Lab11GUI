#pragma once
#include <qwidget.h>
#include "ui_Widget.h"
#include "Controller.h"
#include <qabstractitemmodel.h>

class basketwidget : public QWidget
{
	Q_OBJECT

public:
	basketwidget(Controller& c,QAbstractItemModel* model,QWidget *parent = 0);
	~basketwidget();

private:
	Ui::Form ui;
	Controller& ctrl;

	QAbstractItemModel* tableModel;
};

