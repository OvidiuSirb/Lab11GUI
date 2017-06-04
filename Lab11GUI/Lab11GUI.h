#pragma once

#include <QtWidgets/QMainWindow>
#include <qlistwidget.h>
#include <qformlayout.h>
#include "ui_Lab11GUI.h"
#include "Controller.h"
#include <sstream>
#include "ui_Lab11GUI.h"
#include <qmainwindow.h>
#include <RepositoryExceptions.h>
#include <qmessagebox.h>


class Lab11GUI : public QMainWindow
{
	Q_OBJECT

public:
	Lab11GUI(Controller& _ctrl, QWidget *parent = Q_NULLPTR) : ctrl(_ctrl) 
	{ 
	initGUI();
	currentCoatsInCoatList = ctrl.get_repo().get_coats();
	populate_coat_list();
	ConnectSignalsAndSlots();
	}
	~Lab11GUI() {}

	void initGUI()
	{

		ui.setupUi(this);
		
//		QVBoxLayout* layout = new QVBoxLayout(this);   //layout vertical
//		this->coats->setSelectionMode(QAbstractItemView::SingleSelection);	//how the view responds to user selections
//		layout->addWidget(this->coats);
	}

	void populateCoats()
	{
		if (this->coats->count() > 0)
			this->coats->clear();

		for (auto c : this->ctrl.get_repo().get_coats())
		{
			std::stringstream buffer;
			buffer << c;
			QString text = QString::fromStdString(buffer.str());
			QFont f("Comic Sans MS", 15);
			QListWidgetItem* item = new QListWidgetItem(text);
			item->setFont(f);
			this->coats->addItem(item);
		}

		if (this->ctrl.get_repo().get_coats().size() > 0)
			this->coats->setCurrentRow(0);
	}
	void ConnectSignalsAndSlots()
	{
		//add a connection: function listItemChanged() will be called when an item in the list is selected
		QObject::connect(ui.coat_list, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));
		
		//add button connection
		QObject::connect(ui.add, SIGNAL(clicked()), this, SLOT(addNewCoat()));
		QObject::connect(ui.delete_2, SIGNAL(clicked()), this, SLOT(deleteCoat()));
		QObject::connect(ui.move_one, SIGNAL(clicked()), this, SLOT(moveCoatToPhotos()));
		QObject::connect(ui.move_all, SIGNAL(clicked()), this, SLOT(moveAllCoats()));
		QObject::connect(ui.update, SIGNAL(clicked()), this, SLOT(updateCoat()));
		QObject::connect(ui.view, SIGNAL(clicked()), this, SLOT(view()));
		QObject::connect(ui.next, SIGNAL(clicked()), this, SLOT(next()));
		
	}
	void populate_coat_list()
	{
		if (ui.coat_list->count() > 0)
			ui.coat_list->clear();

		for (auto s : this->currentCoatsInCoatList)
		{
			QString itemInList = QString::fromStdString(s.get_colour() + " - " + std::to_string(s.get_quantity()) + " - " + std::to_string(s.get_size()) + " - " + std::to_string(s.get_price()) + "$");
			QListWidgetItem *item3 = new QListWidgetItem(itemInList);
			ui.coat_list->addItem(item3);
		}

		if (this->currentCoatsInCoatList.size() > 0)
			ui.coat_list->setCurrentRow(0);
	}

	int getCoatListSelectedIndex()
	{
		if (ui.coat_list->count() == 0)
			return -1;
		QModelIndexList index = ui.coat_list->selectionModel()->selectedIndexes();
		if (index.size() == 0)
		{
			ui.colour->clear();
			ui.size->clear();
			ui.price->clear();
			ui.quantity->clear();
			ui.photo->clear();
			return -1;
		}
		int idx = index.at(0).row();
		return idx;
	}

	void populatePhotos()
	{
		if (ui.basket->count() > 0)
			ui.basket->clear();
		
		for (auto s : this->ctrl.get_coats_from_photos())
		{
			QString itemInList = QString::fromStdString(s.get_colour() + " - " + std::to_string(s.get_quantity()) + " - " + std::to_string(s.get_size()) + " - " + std::to_string(s.get_price()) + "$");
			QListWidgetItem *item3 = new QListWidgetItem(itemInList);
			ui.basket->addItem(item3);
		}
	}

private:
	Controller& ctrl;
	std::vector<Coat> currentCoatsInCoatList ;
	QListWidget* coats =  new QListWidget();
	Ui_Lab11GUIClass ui;
	QListWidget* coat_list = ui.coat_list;

private slots:
	void listItemChanged()
	{
		int idx = this->getCoatListSelectedIndex();
		if (idx == -1)
			return;

		std::vector<Coat> coats = this->currentCoatsInCoatList;
		
		//get the coat at the selected index
		if (idx >= coats.size())
			return;
		Coat c = coats[idx];

		ui.colour->setText(QString::fromStdString(c.get_colour()));
		ui.size->setText(QString::fromStdString(std::to_string(c.get_size())));
		ui.quantity->setText(QString::fromStdString(std::to_string(c.get_quantity())));
		ui.price->setText(QString::fromStdString(std::to_string(c.get_price())));
		ui.photo->setText(QString::fromStdString(c.get_photo()));
	}
	
	void addNewCoat()
	{
		std::string colour = ui.colour->text().toStdString();
		int size = ui.size->text().toInt();
		int price = ui.price->text().toInt();
		int quantity = ui.quantity->text().toInt();
		std::string photo = ui.photo->text().toStdString();

		try
		{
			this->ctrl.add_coat_to_repository(size, colour, photo, quantity, price);
			this->currentCoatsInCoatList = this->ctrl.get_repo().get_coats();
			this->populate_coat_list();
		}
		catch (RepositoryException& e)
		{
			QMessageBox messageBox;
			messageBox.critical(0, "Error", QString::fromStdString(e.what()));
		}
	}
	void deleteCoat()
	{
		std::string colour = ui.colour->text().toStdString();
		int size = ui.size->text().toInt();
		
		this->ctrl.delete_coat(size, colour);
		this->currentCoatsInCoatList = this->ctrl.get_repo().get_coats();
		this->populate_coat_list();
	}

	void moveCoatToPhotos()
	{
		int idx = this->getCoatListSelectedIndex();
		if (idx == -1 || idx >= this->currentCoatsInCoatList.size())
			{return; }
		Coat c = this->currentCoatsInCoatList[idx];
		this->ctrl.add_coat_to_photos(c);
		this->populatePhotos();
	}

	void moveAllCoats()
	{
		for (auto s : this->currentCoatsInCoatList)
			this->ctrl.add_coat_to_photos(s);
		this->populatePhotos();
	}

	void updateCoat()
	{
		int idx = this->getCoatListSelectedIndex();
		if (idx == -1)
			return;

		std::vector<Coat> coats = this->currentCoatsInCoatList;

		//get the coat at the selected index
		if (idx >= coats.size())
			return;
		Coat c = coats[idx];

		std::string colour = ui.colour->text().toStdString();
		int size = ui.size->text().toInt();
		int price = ui.price->text().toInt();
		int quantity = ui.quantity->text().toInt();
		std::string photo = ui.photo->text().toStdString();

		try
		{
			this->ctrl.update_coat(c.get_size(), c.get_colour(), size, colour, photo, quantity, price);
			this->currentCoatsInCoatList = this->ctrl.get_repo().get_coats();
			this->populate_coat_list();
		}
		catch (RepositoryException& e)
		{
			QMessageBox messageBox;
			messageBox.critical(0, "Error", QString::fromStdString(e.what()));
		}
	}
	void view()
	{
		this->ctrl.next_photo(0);
	}
	void next()
	{
		this->ctrl.next_photo();
	}
};
