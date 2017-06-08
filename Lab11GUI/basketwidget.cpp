#include "basketwidget.h"



basketwidget::basketwidget(Controller& c,QAbstractItemModel* model,QWidget *parent) : QWidget(parent), ctrl { c },tableModel{model}
{
	ui.setupUi(this);

	this->ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	this->ui.tableView->setModel(this->tableModel);
}


basketwidget::~basketwidget()
{
}
