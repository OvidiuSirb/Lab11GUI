#include "BasketTableModel.h"
#include <qbrush.h>
#include <qcolor.h>

BasketTableModel::~BasketTableModel()
{
}

int BasketTableModel::rowCount(const QModelIndex& parent) const
{
	return this->ctrl.get_photos().get_size();
}

int BasketTableModel::columnCount(const QModelIndex& parent) const
{
	return 4;
}
 
QVariant BasketTableModel::data(const QModelIndex& index, int role) const
{
	Coat currentCoat = this->ctrl.get_photos().getAll()[index.row()];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (index.column())
		{
		case 0:
			return QString::fromStdString(currentCoat.get_colour());
		case 1:
			return QString::number(currentCoat.get_size());
		case 2:
			return QString::number(currentCoat.get_quantity());
		case 3:
			return QString::number(currentCoat.get_price());
		default:
			break;
		}
	}
	return QVariant();
}

QVariant BasketTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString{ "Colour" };
			case 1:
				return QString{ "Size" };
			case 2:
				return QString{ "Quantity" };
			case 3:
				return QString{ "Price" };
			default:
				break;
			}
		}
	}
	return QVariant();

}

Qt::ItemFlags BasketTableModel::flags(const QModelIndex& index) const
{
	int col = index.column();
	if (col == 0 || col == 1)
		return Qt::ItemFlags{};
	return Qt::ItemIsEnabled | Qt::ItemIsSelectable; //|Qt::itemIsEditable
}