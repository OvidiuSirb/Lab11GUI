#include "Lab11GUI.h"
#include <QtWidgets/QApplication>
#include "Controller.h"
#include "CSVPhoto.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo("..\\Lab11GUI\\Coats.txt");
	CSVPhoto p;
	Controller ctrl( repo, p, PhotoValidator() );
	Lab11GUI w( ctrl);
	w.show();
	return a.exec();
}
