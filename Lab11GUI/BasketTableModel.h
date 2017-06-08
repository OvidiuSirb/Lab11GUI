#pragma once
#include <qabstractitemmodel.h>
#include "Repository.h"
#include "Controller.h"

class BasketTableModel : public QAbstractTableModel
{
private:
	Controller& ctrl;

public:
	BasketTableModel(Controller& c) : ctrl{ c } {}
	~BasketTableModel();

	int rowCount(const QModelIndex& parent = QModelIndex{}) const override;
	int columnCount(const QModelIndex& parent = QModelIndex{}) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	//bool setData
	Qt::ItemFlags flags(const QModelIndex& index) const override;
};

